#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "commons.hpp"

template <class T> class LinkedListNode {
public:
  T                  data;
  LinkedListNode<T> *next;
};

template <class T> class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  size_t            getSize() const noexcept;
  size_t            isEmpty() const noexcept;
  void              addNode( T data );
  T                 removeNode( size_t index );
  T                 getNode( size_t index ) const;
  T                 getFirst() const noexcept;
  T                 getLast() const noexcept;

private:
  size_t             size;
  LinkedListNode<T> *head;
  LinkedListNode<T> *tail;
};

//================ CONSTRUCTOR/DESTRUCTOR =================//
/**
 *
 */
template <class T> LinkedList<T>::LinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

/**
 *
 */
template <class T> LinkedList<T>::~LinkedList() {
  LinkedListNode<T> *tmp;
  while ( this->head != nullptr ) {
    tmp        = this->head;
    this->head = this->head->next;
    delete tmp;
  }
}

//================ PUBLIC FUNCTIONS =================//
/**
 *
 */
template <class T>
inline size_t
LinkedList<T>::getSize() const noexcept {
  return this->size;
}

/**
 *
 */
template <class T>
inline size_t
LinkedList<T>::isEmpty() const noexcept {
  return this->size == 0;
}

/**
 *
 */
template <class T>
inline T
LinkedList<T>::getFirst() const noexcept {
  return head->data;
}

/**
 *
 */
template <class T>
inline T
LinkedList<T>::getLast() const noexcept {
  return tail->data;
}

/**
 *
 */
template <class T>
void
LinkedList<T>::addNode( T data ) {
  LinkedListNode<T> *newData = new LinkedListNode<T>;
  newData->data              = data;

  /* If the head is null it means the list is empty. */
  if ( this->head == nullptr ) {
    this->head = newData;
    this->tail = this->head;
  } else {
    /* Otherwise, set the current tail to point to this,
       then make the tail this. */
    this->tail->next = newData;
    this->tail       = newData;
  }

  this->size++;
}

/**
 *
 */
template <class T>
T
LinkedList<T>::removeNode( size_t index ) {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  }

  this->size--;
  LinkedListNode<T> *node;

  /* Just get the head then reset the pointer. */
  if ( index == 0 ) {
    node       = this->head;
    this->head = this->head->next;
  } else if ( index == size - 1 ) {
    /* Grab the tail and reset the pointer. */
    node             = this->tail;
    this->tail->next = nullptr;
    this->tail       = nullptr;
  } else {
    LinkedListNode<T> *before = this->head;
    for ( int i = 0; i < index - 1; i++ ) {
      before = before->next;
    }

    node         = before->next;
    before->next = node->next;
  }

  return node->data;
}

/**
 *
 */
template <class T>
T
LinkedList<T>::getNode( size_t index ) const {
  if ( index < 0 || index >= this->size ) {
    std::ostringstream msg;
    msg << "Error: index " << index << " is out of bounds." << std::endl;
    throw std::invalid_argument( msg.str() );
  }

  /* Traverse until we find the right node. */
  LinkedListNode<T> *it = this->head;
  for ( int i = 0; i < index; i++ ) {
    it = it->next;
  }

  return it->data;
}

#endif // LINKEDLIST_HPP
