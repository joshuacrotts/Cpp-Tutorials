#include "../include/vector.hpp"

//================ CONSTRUCTOR/DESTRUCTOR =================//

/**
 *
 */
Vector::Vector() {
  this->size = 0;

  /* This looks ugly, but it just makes an array of integers.
     "int" will change later! I decided to use C++ pointers
     instead of C-style pointers because... future? */
  this->arr = std::unique_ptr<int[]>{new int[this->capacity]};
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
 * This may not be the correct way to supply modifiers after
 * a function, someone correct me!
 */
ssize_t
Vector::getSize() const noexcept {
  return this->size;
}

/**
 *
 */
ssize_t
Vector::getCapacity() const noexcept {
  return this->capacity;
}

/**
 *
 */
int32_t
Vector::getElement( ssize_t index ) const {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  }

  return this->arr[index];
}

/**
 *
 */
bool
Vector::isEmpty() const noexcept {
  return this->size == 0;
}

/**
 *
 */
int32_t
Vector::addElement( int element ) noexcept {
  this->resize( RIGHT );
  this->arr[this->size] = element;
  this->size++;
  return VECTOR_ADD;
}

/**
 *
 */
void
Vector::insertElement( int element, ssize_t index ) {
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
 *
 */
int32_t
Vector::removeElement( ssize_t index ) {
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