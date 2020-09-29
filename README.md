# C++ Streams

## What this repo is

In this repo I tried to copy the functionality of Java's streams. Mostly for my own purposes.

## Note

Since I wrote it for my own purposes, it's basically a dumbed down version of what Java has and this doesn't use lazy evaluation like Java's so it's probably a lot slower.  
Other than these, I tried keeping it similar to Java's.

## Documentation

### Constructors

#### Stream()

An empty constructor.

#### Stream(const std::vector<T> &vector)

Initializes the stream with the given vector.

#### bool allMatch(bool (*predicate)(T))

Checks if all elements match the predicate.

*predicate* - The predicate to test all the elements

**return** -  returns whether all elements match the predicate

#### bool anyMatch(bool (*predicate)(T))

Checks if any element matches the predicate.

*predicate* - The predicate to test all elements

**return** -  Whether any element matches the predicate

#### long count()

Returns how many elements the stream contains

**return** - Number of elements in the stream

#### Stream<T> distinct()

Returns a new `Stream` object containing only the distinct elements of the originals.  
That means no duplicate values in the streams.

**return** - The new `Stream` object with distinct values

#### Stream<T> filter(bool (*predicate)(T))

Returns a new `Stream` object containing only the elements matching the predicate

*predicate* - The predicate to test all elements

**return** - The new `Stream` object with filtered values

#### void forEach(void (*action)(T))

Applies *action* to all elements.

*action* - The action to apply to all elements

#### Stream<U> map(U (*mapper)(T))

Maps all elements using *mapper*

*mapper* - The mapper function to use

**return** - The new `Stream` object with the mapped values

##### NOTE

It doesn't work with lambda functions as of now. However, if you pass a named function to it, it works.

#### T max()

Returns the maximum element of the stream

**return** - The maximum value of the stream

#### T min()

Returns the minimum element of the stream

**return** - The minimum value of the stream

#### bool noneMatch(bool (*predicate)(T))

Checks if no element matches the predicate.

*predicate* - The predicate to test all elements

**return** -  Whether no element matches the predicate

#### static Stream<T> of(std::vector<T> v)

Constructs a stream of the given vector.

**return** - The scream constructed of the given vector

#### Stream<T> sorted()

Sorts the elements of the stream using the `<` operator.

**return** - The new `Stream` object with sorted elements

#### Stream<T> sorted(bool (*comparator)(T, T))

Sorts the elements of the stream using the comparator.

**return** - The new `Stream` object with sorted elements

#### std::vector<T> toVector()

Converts the stream to `std::vector`.

**return** - The `std::vector` with all the elements of the stream
