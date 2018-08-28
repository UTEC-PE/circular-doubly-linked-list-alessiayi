#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        List();

        T front();
        T back();
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};

#endif