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
        int nodes;

    public:

      List() : start(nullptr), nodes(0) {};//Constructor

      T front(){
        return start -> data;
      };
      T back(){
        return start -> prev -> data;
      };
      void push_front(T value){
        Node<T>* Tmp=new Node<T>;
        Tmp -> data=value;
        if (!start){
          Tmp -> next=Tmp;
          Tmp -> prev=Tmp;
          start=Tmp;
        }
        else{
          Node<T>* Temp=new Node<T>;
          Temp= start -> prev;
          start -> prev=Tmp;
          Tmp -> next=start;
          Tmp -> prev= Temp;
          Temp -> next=Tmp;
          start=Tmp;
        }
        nodes++;
      };
      void push_back(T value){
        Node<T>* Tmp=new Node<T>;
        Tmp -> data=value;
        if (!start){
          Tmp -> next=Tmp;
          Tmp -> prev=Tmp;
          start=Tmp;
        }
        else{
          Node<T>* Temp=new Node<T>;
          Temp= start -> prev;
          start -> prev=Tmp;
          Tmp -> next=start;
          Tmp -> prev= Temp;
          Temp -> next=Tmp;
        }
        nodes++;
      };
      void pop_front(){
          if(!start){
            throw "NO";
          }
          if (size()==1){
            start=nullptr;
          }
          else{
            Node<T>* Tmp=new Node<T>;
            Node<T>* Temp=new Node<T>;
            Tmp= start -> next;
            Temp=start -> prev;
            Tmp -> prev=Temp;
            Temp -> next=Tmp;
            start -> next=nullptr;
            start -> prev=nullptr;
            delete start;
            start=Tmp;
          }
          nodes--;
        };
      void pop_back(){
        if (!start){
          throw "NO";
        }
        if (size()==1){
          start=nullptr;
        }
        else{
          Node<T>* Tmp=new Node<T>;
          Tmp=start -> prev;
          Node<T>* Temp=new Node<T>;
          Temp= Tmp -> prev;
          start -> prev=Temp;
          Temp -> next=start;
          Tmp -> next=nullptr;
          Tmp -> prev=nullptr;
          delete Tmp;
        }
        nodes--;
      };
      T get(int position){
        if (!start || position < 0){
            throw "NO";
          }
        else{
          if (!position){
            return start -> data;
          }
          else{
            int c=0;
            Node<T>* Tmp = start;
            while (Tmp){
              if (c==position){
                return Tmp -> data;
              }
              c++;
              Tmp=Tmp -> next;
            }
            throw "NO";
          }
        }
      };
      void concat(List<T> &other){
        if (!other.start){
          throw "NO";
        }
        else{
          for (int i=0; i<other.size(); i++){
            push_back(other.get(i));
          }
        }
      };
      bool empty(){
        return !start;
      };
      int size(){
        return nodes;
      };
      void clear(){
        while (nodes){
          pop_front();
        }
      };
      Iterator<T> begin(){
        Iterator<T>* It=new Iterator<T>(start);
        return *It;
      };
      Iterator<T> end(){
        Iterator<T>* It=new Iterator<T>(start->prev);
        return *It;
      };

      ~List(){ this->clear(); };
};

#endif
