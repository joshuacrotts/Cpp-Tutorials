#include "../include/commons.hpp"
#include "../include/vector.hpp"

template <class T> static void printVector( const Vector<T> &v );
template <class T> static void printCapacityAndSize( const Vector<T> &v );

int
main( int argc, char *argv[] ) {
  Vector<int> v;
  printCapacityAndSize( v );
  v.addElement( 10 );
  v.addElement( 20 );
  v.addElement( 30 );
  v.addElement( 17 );
  v.addElement( 12 );
  v.addElement( 11 );
  printCapacityAndSize( v );
  printVector( v );
  std::cout << "Removing index 1 (should be 20): " << v.removeElement( 1 ) << std::endl;
  printCapacityAndSize( v );
  printVector( v );
  std::cout << "Removing index 3 (should be 12): " << v.removeElement( 3 ) << std::endl;
  printCapacityAndSize( v );
  printVector( v );
}

/**
 * Prints the vector. Simple as that.
 */
template <class T>
static void
printVector( const Vector<T> &v ) {
  for ( int i = 0; i < v.getSize(); i++ ) {
    std::cout << "Index: " << i << ": " << v.getElement( i ) << std::endl;
  }
}

/**
 * Prints the logical size and capacity of the vector.
 */
template <class T>
static void
printCapacityAndSize( const Vector<T> &v ) {
  std::cout << "Capacity: " << v.getCapacity() << ", Size: " << v.getSize() << std::endl;
}