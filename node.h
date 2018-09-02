#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node <T>(): next(nullptr){};

    void killSelf(){
      if (next){
        next->killSelf();
      }
      delete this;
    }
    void print_next();
};

#endif
