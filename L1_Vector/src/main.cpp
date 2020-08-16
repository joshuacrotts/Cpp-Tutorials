#include "../include/commons.hpp"
#include "../include/vector.hpp"

static void printVector( const Vector &v );
static void printCapacityAndSize( const Vector &v );

int
main( int argc, char *argv[] ) {
  Vector v;
  printCapacityAndSize(v);
  v.addElement( 10 );
  v.addElement( 20 );
  v.addElement( 30 );
  v.addElement( 17 );
  v.addElement( 12 );
  v.addElement( 11 );
  printCapacityAndSize(v);
  printVector( v );
  std::cout << "Removing index 1 (should be 20): " << v.removeElement( 1 ) << std::endl;
  printCapacityAndSize(v);
  printVector( v );
  std::cout << "Removing index 3 (should be 12): " << v.removeElement( 3 ) << std::endl;
  printCapacityAndSize(v);
  printVector( v );
}

/**
 * Prints the vector. Simple as that.
 */
static void
printVector( const Vector &v ) {
  for ( int i = 0; i < v.getSize(); i++ ) {
    std::cout << "Index: " << i << ": " << v.getElement( i ) << std::endl;
  }
}

/**
 * Prints the logical size and capacity of the vector.
 */
static void
printCapacityAndSize( const Vector &v ) {
  std::cout << "Capacity: " << v.getCapacity() << ", Size: " << v.getSize() << std::endl;
}