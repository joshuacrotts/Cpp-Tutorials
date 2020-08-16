#include "../include/vector.hpp"

//================ CONSTRUCTOR/DESTRUCTOR =================//

/**
 *
 */
Vector::Vector() {
  this->size = 0;
  this->arr  = std::make_unique<int[]>( this->capacity );
}

/**
 *
 * For those of you coming from another language, this is called the
 * "destructor" of an object. When it is released from memory (typically
 * through delete or another analogous way, this method is called).
 * */
Vector::~Vector() {
  this->size     = 0;
  this->capacity = 0;
  /* The pointer is automatically freed, yay! */
}

//================ PRIVATE FUNCTIONS =================//

/**
 * We can delegate the checking of sizes to this function,
 * and just call it whenever we want to alter the array.
 */
void
Vector::resize( enum RESIZE_TYPE rszType ) {
  /* If we need to grow, then the logical size is the same as the capacity. */
  if ( this->size == this->capacity && rszType == RIGHT ) {
    this->capacity *= RESIZE_FACTOR;
    std::unique_ptr<int[]> newArray{new int[this->capacity]};
    for ( int i = 0; i < this->size; i++ ) {
      newArray[i] = this->arr[i];
    }

    this->arr = std::move( newArray );
  }

  /* If we need to shrink, then the logical size is the same as the capacity / 2. */
  else if ( this->size == this->capacity / RESIZE_FACTOR && rszType == LEFT ) {
    this->capacity /= RESIZE_FACTOR;
    std::unique_ptr<int[]> newArray{new int[this->capacity]};
    for ( int i = 0; i < this->size; i++ ) {
      newArray[i] = this->arr[i];
    }

    this->arr = std::move( newArray );
  }
}

/**
 * Shifts the vector elements to the right or left by 1.
 *
 * @param stds_vector_t * pointer to vector.
 * @param size_t index to offset to or from.
 * @param enum RESIZE_TYPE {LEFT, RIGHT} direction to shift.
 *
 * @return void.
 */
void
Vector::shift( size_t offsetIndex, enum RESIZE_TYPE direction ) {
  switch ( direction ) {
  case LEFT:
    for ( uint32_t i = offsetIndex; i < this->size; i++ ) {
      this->arr[i] = this->arr[i + 1];
    }
    break;
  case RIGHT:
    for ( uint32_t i = this->size; i >= offsetIndex; i-- ) {
      this->arr[i] = this->arr[i - 1];
    }
    break;
  }
}

//================ PUBLIC FUNCTIONS =================//

/**
 *
 * Returns the logical size of the vector at the time.
 *
 * @param void.
 *
 * @return size of vector.
 *
 * This may not be the correct way to supply modifiers after
 * a function, someone correct me!
 */
size_t
Vector::getSize( void ) const noexcept {
  return this->size;
}

/**
 * Returns the logical capacity of the vector at the time.
 *
 * @param void.
 *
 * @return capacity of vector.
 */
size_t
Vector::getCapacity( void ) const noexcept {
  return this->capacity;
}

/**
 * Retrieves an element at the specified index.
 *
 * @param index to retrieve.
 *
 * @return data at index.
 */
int32_t
Vector::getElement( size_t index ) const {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  }

  return this->arr[index];
}

/**
 * Determines if the vector is empty (has no elements).
 *
 * @param void.
 *
 * @return true if the array is empty, false otherwise.
 */
bool
Vector::isEmpty( void ) const noexcept {
  return this->size == 0;
}

/**
 * Adds an element to the end of the vector. If the vector
 * has to be resized,it will be.
 *
 * @param element to add.
 *
 * @return void.
 */
void
Vector::addElement( int element ) noexcept {
  this->resize( RIGHT );
  this->arr[this->size] = element;
  this->size++;
}

/**
 * Inserts an element at the specified index. An exception is thrown
 * if the index is out of bounds.
 *
 * @param element to insert.
 * @param index to insert at.
 *
 * @return void.
 */
void
Vector::insertElement( int element, size_t index ) {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  }

  this->size++;

  /* If we have to resize before inserting, do it now. */
  resize( RIGHT );

  /* Take each element one by one, and copy it to
  the space to the right. */
  shift( index, RIGHT );

  this->arr[index] = element;
}

/**
 * Removes an element at the specified index. If the array is empty
 * or the index is out of bounds, an exception is thrown.
 *
 * @param index of element to remove.
 *
 * @return item removed.
 */
int32_t
Vector::removeElement( size_t index ) {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  } else if ( this->isEmpty() ) {
    throw std::invalid_argument( "Error, the vector is empty." );
  }

  /* Retrieve the element we want. */
  int32_t data = this->arr[index];
  this->size--;

  /* Take each element one by one, and copy it to
  the space to the right. */
  shift( index, LEFT );

  /* If we have to resize before removing, do it now. */
  resize( LEFT );

  return data;
}