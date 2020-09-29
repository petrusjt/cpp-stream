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

*predicate* - The predicate to test all the elements

**return** -  returns whether any element matches the predicate

#### long count()

Returns how many elements the stream contains

**return** - Number of elements in the stream



