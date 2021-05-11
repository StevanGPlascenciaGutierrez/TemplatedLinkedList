#pragma once
#ifndef NODE_H
#define NODE_H
#include <cstddef>
/*
  Name: Node
  Desc: Nodes to hold data of any form
 */
template <typename T>
class Node{
private:
  T data;
  Node* next;

public:
  Node(T);
  Node(T, Node*);
  T getData();
  Node* getNext();
  void setData(T);
  void setNext(Node*);
};

template<typename T>
Node<T>::Node(T data){//Creates Node with only data
  this->data = data;
  next = NULL;

}

template<typename T>
Node<T>::Node(T data, Node* next ){//Creates Node with Data and Next
  this->data = data;
  this->next = next;
}

template<typename T>
T Node<T>::getData(){//Returns Data
  return data;
}

template<typename T>
Node<T>* Node<T>::getNext(){//Returns Pointer to Next
  return next;
}

template<typename T>
void Node<T>::setData(T data){//Sets Data
  this->data = data;
}

template<typename T>
void Node<T>::setNext(Node* next){//Sets Next Pointer
  this->next = next;
}
    
#endif
