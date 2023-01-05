#ifndef Tree_h
#define Tree_h
#include "../2. List/Stack/StackList.cpp"
#include "../2. List/Queue/QueueList.cpp"

#include <iostream>

namespace tree
{
    template <typename T>
    class BST
    {
        struct node
        {
            T data;
            node *left, *right;
        };
        using node_ptr = node *;

    public:
        node_ptr root;
        BST();
        node_ptr Insert(node_ptr nod, T n);
        void PreOrder(node_ptr nod);
        void InOrder(node_ptr nod);
        void PostOrder(node_ptr nod);
        void LevelOrder(node_ptr nod);
        void Search(node_ptr nod, T n);
        node_ptr ReturnMax(node_ptr nod);
        node_ptr ReturnMin(node_ptr nod);
        node_ptr Delete(node_ptr nod, T n);
        void FreeNode(node_ptr nod);
        ~BST();
    };

    template <typename T>
    class AVL
    {
        struct node
        {
            T data;
            node *left, *right;
            int height;
        };
        typedef node *node_ptr;

    public:
        node_ptr root;
        AVL();
        int MaxHeight(node_ptr nod);
        node_ptr RightRotate(node_ptr nodeA);
        node_ptr LeftRotate(node_ptr nodeA);
        int GetBF(node_ptr nod);
        node_ptr Rebalance(node_ptr nod);
        node_ptr Insert(node_ptr nod, T n);
        void PreOrder(node_ptr nod);
        void InOrder(node_ptr nod);
        void PostOrder(node_ptr nod);
        void LevelOrder(node_ptr nod);
        void Search(node_ptr nod, T n);
        node_ptr ReturnMax(node_ptr nod);
        node_ptr ReturnMin(node_ptr nod);
        node_ptr Delete(node_ptr nod, T n);
        void FreeNode(node_ptr nod);
        ~AVL();
    };

    template <typename T>
    class TBT
    { // Threaded Binary Tree
        struct node
        {
            T data;
            struct node *left_child, *right_child;
            int left_thread, right_thread;
        };
        using node_ptr = node *;

        node_ptr root;

    public:
        TBT();
        node_ptr Insert(node_ptr nod, T n);
        node_ptr Delete(node_ptr nod, T n);
        void PreOrder(node_ptr nod);
        void InOrder(node_ptr nod);
        void PostOrder(node_ptr nod);
        void LevelOrder(node_ptr nod);
        void FreeNode(node_ptr nod);
        ~TBT();
    };

    template <typename T>
    class Heap
    {
        struct node
        {
            T data;
            node *left, *right;
        };
        using node_ptr = node *;

        node_ptr root;

    public:
        Heap(int n); // Max heap, Min heap 여부 결정
        Increase();
        Decrease();
        Insert();
        DeleteMax();
        Max();
        ~Heap();
    };
}

#endif