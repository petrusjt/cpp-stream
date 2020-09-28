//Safeguard so multiple includes of this file don't cause errors
#ifndef STREAM_HEADER
#define STREAM_HEADER

#include <vector>
#include <algorithm>


template<class T>
class Stream
{
private:
    std::vector<T> inner_array;

public:
    Stream(){}
    Stream(const std::vector<T> &vector)
    {
        inner_array = vector;
    }
    ~Stream(){}

    bool allMatch(bool (*predicate)(T))
    {
        for(const auto& value : inner_array)
        {
            if(!(*predicate)(value))
            {
                return false;
            }
        }
        return true;
    }

    bool anyMatch(bool (*predicate)(T))
    {
        for(const auto& value : inner_array)
        {
            if((*predicate)(value))
            {
                return true;
            }
        }
        return false;
    }

    long count()
    {
        return this->inner_array.size();
    }

    Stream<T> distinct()
    {
        Stream newStream;

        for(const auto& value : inner_array)
        {
            if(!isInVector(newStream.inner_array,value))
            {
                newStream.inner_array.push_back(value);
            }
        }

        return newStream;
    }

    Stream<T> filter(bool (*predicate)(T))
    {
        Stream<T> newStream;
        for(const auto& value : inner_array)
        {
            if((*predicate)(value))
            {
                newStream.addItem(value);
            }
        }
        return newStream;
    }

    void forEach(void (*action)(T))
    {
        for(const auto& value : inner_array)
        {
            (*action)(value);
        }
    }

    template<class U>
    Stream<U> map(U (*mapper)(T))
    {
        std::vector<U> v;
        for(const auto& value : inner_array)
        {
            //newStream.inner_array.push_back((*mapper)(value));
            v.push_back((*mapper)(value));
        }
        Stream<U> newStream(v);
        return newStream;
    }

    T max()
    {
        return *std::max_element(inner_array.begin(), inner_array.end());
    }

    T min()
    {
        return *std::min_element(inner_array.begin(), inner_array.end());
    }

    bool noneMatch(bool (*predicate)(T))
    {
        for(const auto& value : inner_array)
        {
            if((*predicate)(value))
            {
                return false;
            }
        }
        return true;
    }

    static Stream<T> of(std::vector<T> v)
    {
        Stream<T> newStream(v);
        return newStream;
    }

    Stream<T> sorted()
    {
        Stream<T> newStream;
        newStream.inner_array = this->inner_array;
        std::sort(newStream.inner_array.begin(), newStream.inner_array.end());
        return newStream;
    }

    Stream<T> sorted(bool (*comparator)(T, T))
    {
        Stream<T> newStream;
        newStream.inner_array = this->inner_array;
        std::sort(newStream.inner_array.begin(), newStream.inner_array.end(), comparator);
        return newStream;
    }

    std::vector<T> toVector()
    {
        return this->inner_array;
    }

private: 
    void addItem(T item)
    {
        this->inner_array.push_back(item);
    }

    bool isInVector(std::vector<T> v, T item)
    {
        for(const auto& value : v)
        {
            if(value == item)
            {
                return true;
            }
        }
        return false;
    }

};

#endif