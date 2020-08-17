#include "../include/linkedlist.hpp"

int
main( int argc, char *argv[] ) {
  LinkedList<int> ll;
  ll.addNode( 100 );
  ll.addNode( 200 );
  ll.addNode( 300 );

  for ( int i = 0; i < ll.getSize(); i++ ) {
    int x = ll.getNode( i );
    std::cout << x << std::endl;
  }
}