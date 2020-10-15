#ifndef STREAM_STDFUNCTION_HEADER
#define STREAM_STDFUNCTION_HEADER

#include <vector>
#include <algorithm>
#include <functional>

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

    bool allMatch(std::function<bool(T)> predicate)
    {
        for(const auto& value : inner_array)
        {
            if(!predicate(value))
            {
                return false;
            }
        }
        return true;
    }

    bool anyMatch(std::function<bool(T)> predicate)
    {
        for(const auto& value : inner_array)
        {
            if(predicate(value))
            {
                return true;
            }
        }
        return false;
    }

    size_t count()
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

    Stream<T> filter(std::function<bool(T)> predicate)
    {
        Stream<T> newStream;
        for(const auto& value : inner_array)
        {
            if(predicate(value))
            {
                newStream.addItem(value);
            }
        }
        return newStream;
    }

    void forEach(std::function<void(T)> action)
    {
        for(const auto& value : inner_array)
        {
            action(value);
        }
    }

    template<class U>
    Stream<U> map(std::function<U(T)> mapper)
    {
        std::vector<U> v;
        for(const auto& value : inner_array)
        {
            v.push_back(mapper(value));
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

    bool noneMatch(std::function<bool(T)> predicate)
    {
        for(const auto& value : inner_array)
        {
            if(predicate(value))
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

    Stream<T> sorted(std::function<bool(T,T)> comparator)
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