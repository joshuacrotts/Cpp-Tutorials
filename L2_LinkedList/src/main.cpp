#include "../include/linkedlist.hpp"

int
main( int argc, char *argv[] ) {
  LinkedList<int> ll;
  ll.addNode( 100 );
  ll.addNode(200);
  ll.addNode(300);

  std::cout << "first: " << ll.getFirst() << std::endl;
}