#ifndef List_h
#define List_h

#include <iostream>

namespace lst{
    template <typename T>
    class SLL{ //Singly Linked List
    protected:
        struct node{
            T data;
            node *next;
        };
        typedef node* node_ptr;
        node_ptr head,tail,cur;//헤드 노드와 테일 노드를 더미 노드로 둔다.
        //이렇게 함으로써 삽입과 제거를 어떤 상황이든 일반화시킬 수 있다.
        //cur은 테일 노드의 직전 노드(마지막 데이터 값이 있는 노드)를 가리킨다.

    public:
        SLL();
        void Add(T data);
        void Delete(T data);     
        void Print();
        ~SLL();
    };

    template <typename T>
    class DLL{ //Doubly Linked List
    protected:
        struct node{
            T data;
            node *prev,*next;
        };
        typedef node* node_ptr;
        node_ptr head,tail;//헤드 노드와 테일 노드를 더미 노드로 둔다.

    public:
        DLL();
        void Add(T data);
        void Delete(T data);     
        void Print();
        void Reverse();
        ~DLL();
    };

    template <typename T>
    class XOR{ //XOR Linked List
    protected:
        struct node{
            T data;
            node *npx;
        };
        typedef node* node_ptr;
        node_ptr head,tail;//헤드 노드와 테일 노드를 더미 노드로 둔다.

    public:
        XOR();
        node_ptr Prev(node_ptr cur,node_ptr next);
        node_ptr Next(node_ptr cur,node_ptr prev);
        void Add(T data);
        void Delete(T data);     
        void Print();
        ~XOR();
    };

    template <typename T>
    class CDLL{ //Circular Doubly Linked List
    protected:
        struct node{
            T data;
            node *prev,*next;
        };
        typedef node* node_ptr;
        node_ptr head;
        //헤드 노드는 더미 노드로, 실제 쓰이는 노드를 가리키는 용도로만 쓰인다.

    public:
        CDLL();
        void Add(T data);
        void Delete(T data);     
        void Print();
        void Reverse();
        void Josephus(int n,int k);
        ~CDLL();
    };

    template <typename T>
    class Stack:public DLL<T>{
    //top=tail->prev

    public:
        Stack(){};
        int isEmpty();
        void Push(T item);
        T Pop();
        T Top();
        ~Stack(){};
    };

    template <typename T>
    class Queue:public DLL<T>{
    //front=head->next,rear=tail->prev

    public:
        Queue(){};
        int isEmpty();
        void Enqueue(T item);
        T Dequeue();
        T Front();
        T Rear();
        ~Queue(){};
    };

}

#endif