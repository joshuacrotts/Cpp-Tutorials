#ifndef VECTOR_HPP /* Header guards in case we accidentally re-include this file. */
#define VECTOR_HPP

#include "commons.hpp"

/* Enums for resizing the array dynamically. */
enum { VECTOR_INSERT, VECTOR_REMOVE };

static const int32_t INITIAL_CAPACITY = 10;
static const int32_t RESIZE_FACTOR    = 2;

/* For now, we'll just use ints as the data type stored in the vector
   to make sure it compiles for everyone (before we complicate things with
   templates). */
class Vector {
public:
  Vector();
  ~Vector();

  /* Returns the size of the vector (how many elements are currently in it.). */
  size_t getSize() const noexcept;

  /* Adds an element to the end of the vector. */
  int32_t addElement( int element ) noexcept;

  /* Inserts an element to the specified index of the vector. */
  int32_t insertElement( int element );

  /* Removes element at index. Exception is thrown if it is out of scope. */
  int32_t removeElement( size_t index );

private:
  size_t                 capacity = INITIAL_CAPACITY;
  size_t                 size;
  std::unique_ptr<int[]> arr; /* Create a pointer to our array. */

  void resize(); /* We don't need to expose this function to the user! */
};

/* Do not remove this! Sure, it's a bit weird (including a .cpp file), but we'll explain it once we
   get to generics (templates). */
// #include "../src/vector.cpp"

#endif // VECTOR_HPP