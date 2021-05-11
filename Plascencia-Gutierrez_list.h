#pragma once
#ifndef LIST_H
#define LIST_H
#include <string>
#include <cstddef> //For NULL
#include <iostream>
#include "Plascencia-Gutierrez_node.h"
/*
  Name:LinkedList
  Desc:Contains List of nodes that are connected, able to be modified
 */

template <typename T>
class LinkedList{

private:

  //Private Variables for LinkedList
  Node<T>* head;
  Node<T>* tail;
  
public:

  //Constructors
  LinkedList();
  LinkedList(T);
  LinkedList(T,T);
  
  //Destructor
  ~LinkedList();
  
  //Methods
  void addToFront(T);
  void addToEnd(T);
  bool addAtIndex(T, int);
  T removeFromFront();
  T removeFromEnd();
  void removeTheFirst(T);
  void removeAllOf(T);
  bool elementExists(T);
  Node<T>* find(T);
  int indexOf(T);
  T retrieveFront();
  T retrieveEnd();
  T retrieve(int);
  void printList();
  void empty();
  int length();
};

/*----------------- Constructors --------------*/
template<typename T>
LinkedList<T>::LinkedList(){
  Node<T>* head = NULL;
  Node<T>* tail = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(T data){
  Node<T>* head = new Node<T>(data);
  Node<T>* tail = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(T data, T data2){
  Node<T>* tail = new Node<T>(data2);
  Node<T>* head = new Node<T>(data,tail);
}

/*---------------- Deconstructor ------------*/

template<typename T>
LinkedList<T>::~LinkedList(){
  Node<T>* next;
  
  do{
    next = head->getNext();
    delete head;
    head = next;
  }while(head != NULL);
  
}

/*--------------- Methods ----------------*/

template<typename T>
void LinkedList<T>::addToFront(T data){//Adds Data to front of list
  Node<T>* newHead = new Node<T>(data, head);
  head = newHead;
}

template<typename T>
void LinkedList<T>::addToEnd(T data){//Adds Data to back of list
  Node<T>* newTail = new Node<T>(data);
  if(head == NULL){
    head = newTail;
  }else if(tail == NULL ){
    head->setNext(newTail);
    tail = newTail;
  }else{
    tail->setNext(newTail);
    tail = newTail;
  }
}

template<typename T>
bool LinkedList<T>::addAtIndex(T data, int index){//Adds Data at index
  Node<T>* newData = new Node<T>(data);
  Node<T>* next = head;
  index--;

  for(int i = 0; i < index; i++){

    if(next == NULL){
      return false;
    }

    next = next->getNext();
  }

  newData->setNext(next->getNext());
  next->setNext(newData);
  
  return true;

}

template<typename T>
T LinkedList<T>::removeFromFront(){//Removes data from front and deletes node
  T data = head->getData();
  Node<T>* temp = head;
  Node<T>* next = head->getNext();
  delete head;
  head = next;
  return data;
}

template<typename T>
T LinkedList<T>::removeFromEnd(){//Removes data from end and deletes node
  T data = tail->getData();
  Node<T>* temp = head;
  Node<T>* next = head;

  while( next != tail ){
    temp = next;
    next = next->getNext();
  }
  
  temp->setNext(NULL);
  tail = temp;
  delete next;
  return data;

}

template<typename T>
void LinkedList<T>::removeTheFirst(T data){//Removes First Element
  Node<T>* next = head;
  Node<T>* temp = head;
  while(next != NULL){
    if(*(next->getData()) == *data){
      if(next == head){
	head = next->getNext();
	delete next;
      }else if(next == tail){
	tail = temp;
	delete next;
      }else{
	temp->setNext(next->getNext());
	delete next;
      }
      return ;
    }
    
    temp = next;
    next = next->getNext();
  }
}

template<typename T>
void LinkedList<T>::removeAllOf(T data){//Removes all of the matching Elements
  Node<T>* next = head;
  Node<T>* temp = head;
  while(next != NULL){
    if(*(next->getData()) == *data){
      if(next == head){
	head = next->getNext();
	delete next;
	next = head;
      }else if(next == tail){
	temp->setNext(NULL);
	tail = temp;
	delete next;
	return;
      }else{
	temp->setNext(next->getNext());
	delete next;
	next = temp->getNext();
      }
    }else{
      temp = next;
      next = next->getNext();
    }
  } 
}

template<typename T>
bool LinkedList<T>::elementExists(T data){//Returns True if Element exists
  Node<T>* next = head;
  do{
    if(*(next->getData()) == *data){
      return true;
    }
    next = next->getNext();
  }while(next != NULL);

  return false;
}

template<typename T>
Node<T>* LinkedList<T>::find(T data){//Returns Node of Element
  Node<T>* next = head;
  do{
    if(*(next->getData()) == *data){
      return next;
    }
    next = next->getNext();
  }while(next != NULL);

  return NULL;
}

template<typename T>
int LinkedList<T>::indexOf(T data){//Returns Index of Element
  Node<T>* next = head;
  int index = 0;
  do{
    if(*(next->getData()) == *data){
      return index;
    }
    index++;
    next = next->getNext();
  }while(next != NULL);

  return NULL;
}

template<typename T>
T LinkedList<T>::retrieveFront(){//Returns front data
  return head->getData();
}

template<typename T>
T LinkedList<T>::retrieveEnd(){//Returns End data
  return tail->getData();
}

template<typename T>
T LinkedList<T>::retrieve(int index){//Returns data at index
  Node<T>* next = head;
  for(int i = 0; i < index; i++){
    if(next->getNext() == NULL){
      return NULL;
    }
    next = next->getNext();
  }

  if(next->getData() == NULL){
    return NULL;
  }

  return next->getData();
  
}

template<typename T>
void LinkedList<T>::printList(){//Prints List to console
  Node<T>* next = head;
  T data;
  
  std::cout << "There are now " << this->length() << " Zombies: ";
  while(next != NULL){
    data = next->getData();
    std::cout<< *data;
    next = next->getNext();
  }

}

template<typename T>
void LinkedList<T>::empty(){//Empties list
  Node<T>* next = head;

  while(next != NULL){
    head = next->getNext();
    delete next;
    next = head;
  }
  
}

template<typename T>
int LinkedList<T>::length(){//Returns Length
  Node<T>* next;
  Node<T>* temp = head;
  int length = 0;

  while(temp != NULL){
    length++;
    next = temp->getNext();
    temp = next;
  }

  return length;
}
#endif
