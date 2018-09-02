#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator<T>(): current(nullptr){};
        Iterator<T>(Node<T>* node): current (node){};

        Iterator<T> operator=(Iterator<T> node){
          current=node.current;

          return *this; //devuelve el mismo objeto
        };
        bool operator!=(Iterator<T> node){
            return current!=node.current;
        };
        Iterator<T> operator++(){
          current=current->next;
          return *this;
        };
        Iterator<T> operator--(){
          current=current->prev;
          return *this;
        };
        T operator*(){
          return current -> data;
        };
};

#endif
