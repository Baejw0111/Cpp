#ifndef Array_h
#define Array_h

#include <iostream>

namespace arr{
    template <typename T>
    class Queue{
    protected:
        T *q;
        int size,rear,front;

    public:
        Queue(int n);
        int isEmpty();
        int isFull();
        void Insert(T item);
        int Delete();
        void Print();
        ~Queue();
    };

    template <typename T>
    class Cqueue: public Queue<T>{
    public:
        Cqueue(int n);
        int isFull();
        int isEmpty();
        void Insert(T item);
        void Delete();
        void Print();
        ~Cqueue(){};
    };

    template <typename T>
    class Stack{
        T *s;
        int size,top;

    public:
        Stack(int n);
        int isEmpty();
        int isFull();
        void Push(T item);
        int Pop();
        void Print();
        ~Stack();
    };
}

#endif