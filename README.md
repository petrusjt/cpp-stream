# C++ Streams

## What this repo is

In this repo I tried to copy the functionality of Java's streams. Mostly for my own purposes.

## Note

Since I wrote it for my own purposes, it's basically a dumbed down version of what Java has and this doesn't use lazy evaluation like Java's so it's probably a lot slower.  
Other than these, I tried keeping it similar to Java's.

## stream_stdfunction

Behaves exactly the same as stream.hpp but uses `std::function` objects as parameters instead of function pointers. You can't use both in the same project because I named the two classes the same, however this shouldn't cause any problems. I don't think anyone would use the two in the same project.

## Documentation

<a href="#streamhpp">stream.hpp</a>
<a href="#streamstdfunctionhpp">stream_stdfunction.hpp</a>

<a name="streamhpp">

### Constructors

</a>

#### Stream()

An empty constructor.

#### Stream(const std::vector&lt; T &gt; &vector)

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

#### Stream&lt; T &gt; distinct()

Returns a new `Stream` object containing only the distinct elements of the originals.  
That means no duplicate values in the streams.

**return** - The new `Stream` object with distinct values

#### Stream&lt; T &gt; filter(bool (*predicate)(T))

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

#### static Stream&lt; T &gt; of(std::vector&lt; T &gt; v)

Constructs a stream of the given vector.

**return** - The scream constructed of the given vector

#### Stream&lt; T &gt; sorted()

Sorts the elements of the stream using the `<` operator.

**return** - The new `Stream` object with sorted elements

#### Stream&lt; T &gt; sorted(bool (*comparator)(T, T))

Sorts the elements of the stream using the comparator.

**return** - The new `Stream` object with sorted elements

#### std::vector&lt; T &gt; toVector()

Converts the stream to `std::vector`.

**return** - The `std::vector` with all the elements of the stream

<a name="stream_stdfunctionhpp">

### Constructors

</a>

#### Stream()

An empty constructor.

#### Stream(const std::vector&lt; T &gt; &vector)

Initializes the stream with the given vector.

#### bool allMatch(std::function&lt;bool(T)&gt; predicate)

Checks if all elements match the predicate.

*predicate* - The predicate to test all the elements

**return** -  returns whether all elements match the predicate

#### bool anyMatch(std::function&lt;bool(T)&gt; predicate)

Checks if any element matches the predicate.

*predicate* - The predicate to test all elements

**return** -  Whether any element matches the predicate

#### long count()

Returns how many elements the stream contains

**return** - Number of elements in the stream

#### Stream&lt; T &gt; distinct()

Returns a new `Stream` object containing only the distinct elements of the originals.  
That means no duplicate values in the streams.

**return** - The new `Stream` object with distinct values

#### Stream&lt; T &gt; filter(std::function&lt; bool(T) &gt; predicate)

Returns a new `Stream` object containing only the elements matching the predicate

*predicate* - The predicate to test all elements

**return** - The new `Stream` object with filtered values

#### void forEach(std::function&lt; void(T) &gt; action)

Applies *action* to all elements.

*action* - The action to apply to all elements

#### Stream<U> map(std::function&lt; U(T) &gt; mapper)

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

#### bool noneMatch(std::function&lt;bool(T)&gt; predicate)

Checks if no element matches the predicate.

*predicate* - The predicate to test all elements

**return** -  Whether no element matches the predicate

#### static Stream&lt; T &gt; of(std::vector&lt; T &gt; v)

Constructs a stream of the given vector.

**return** - The scream constructed of the given vector

#### Stream&lt; T &gt; sorted()

Sorts the elements of the stream using the `<` operator.

**return** - The new `Stream` object with sorted elements

#### Stream&lt; T &gt; sorted(std::function&lt;bool(T, T)&gt; comparator)

Sorts the elements of the stream using the comparator.

**return** - The new `Stream` object with sorted elements

#### std::vector&lt; T &gt; toVector()

Converts the stream to `std::vector`.

**return** - The `std::vector` with all the elements of the stream
