#include "../Tree.h"

template <typename T>
tree::BST<T>::BST():root(NULL){}

template <typename T>
typename tree::BST<T>::node_ptr tree::BST<T>::Insert(node_ptr nod,T n){
    if(nod==NULL){
        node_ptr tmp=new node;
        tmp->data=n;
        tmp->left=NULL;
        tmp->right=NULL;

        return tmp;
    } 

    if(n<nod->data){
        nod->left=Insert(nod->left,n);
    }
    else{
        nod->right=Insert(nod->right,n);
    }
    return nod;
}

template <typename T>
void tree::BST<T>::PreOrder(node_ptr nod){
    lst::Stack<node_ptr> stack;

    stack.Push(nod);

    while(1){
        if(stack.isEmpty()){
            break;
        }

        nod=stack.Pop();

        std::cout<<nod->data<<" ";

        if(nod->right){
            stack.Push(nod->right);
        }
        if(nod->left){
            stack.Push(nod->left);
        }
    }
    std::cout<<std::endl;
}

template <typename T>
void tree::BST<T>::InOrder(node_ptr nod){
    lst::Stack<node_ptr> stack;

    while(1){
        while(nod){
            stack.Push(nod);
            nod=nod->left;
        }

        if(stack.isEmpty()){
            break;
        }

        nod=stack.Pop();

        std::cout<<nod->data<<" ";
        nod=nod->right;
    }
    std::cout<<std::endl;
}

template <typename T>
void tree::BST<T>::PostOrder(node_ptr nod){
    lst::Stack<node_ptr> stack;

    while(1){
        while(nod){
            stack.Push(nod);
            stack.Push(nod);
            nod=nod->left;
        }

        if(stack.isEmpty()){
            break;
        }

        nod=stack.Pop();

        if(nod==stack.Top()){
            nod=nod->right;
        }
        else{
            std::cout<<nod->data<<" ";
            nod=NULL;
        }
    }
    std::cout<<std::endl;
}

template <typename T>
void tree::BST<T>::LevelOrder(node_ptr nod){
    lst::Queue<node_ptr> queue;

    queue.Enqueue(nod);

    while(1){
        if(queue.isEmpty()){
            break;
        }

        nod=queue.Dequeue();

        std::cout<<nod->data<<" ";

        if(nod->left){
            queue.Enqueue(nod->left);
        }
        if(nod->right){
            queue.Enqueue(nod->right);
        }
    }
    std::cout<<std::endl;
}

template <typename T>
void tree::BST<T>::Search(node_ptr nod,T n){
    lst::Queue<char> answer;

    answer.Enqueue('H');

    while(1){
        if(nod->data>n){
            answer.Enqueue('L');
            nod=nod->left;
        }
        else if(nod->data<n){
            answer.Enqueue('R');
            nod=nod->right;
        }
        else{
            break;
        }

        if(!nod){
            std::cout<<-1<<std::endl;
            return;
        }
    }

    while(!answer.isEmpty()){
        std::cout<<answer.Dequeue();
    }
    std::cout<<std::endl;
}

template <typename T>
typename tree::BST<T>::node_ptr tree::BST<T>::ReturnMax(node_ptr nod)
{
    while (nod->right)
    {
        nod = nod->right;
    }

    return nod;
}

template <typename T>
typename tree::BST<T>::node_ptr tree::BST<T>::ReturnMin(node_ptr nod)
{
    while (nod->left)
    {
        nod = nod->left;
    }

    return nod;
}

template <typename T>
typename tree::BST<T>::node_ptr tree::BST<T>::Delete(node_ptr nod, T n)
{
    node_ptr tmp;

    if (!nod)
    {
        return nod;
    }
    else if (nod->data > n)
    {
        nod->left=Delete(nod->left,n);
    }
    else if (nod->data < n)
    {
        nod->right=Delete(nod->right,n);
    }
    else
    {
        if (nod->left && nod->right)
        { // if node have 2 child
            tmp = ReturnMin(nod->right);
            nod->data = tmp->data;
            nod->right = Delete(nod->right, tmp->data);
        }
        else
        { // if node have 1 or no child
            tmp = nod;
            if (nod->left)
            {
                nod = nod->left;
            }
            else
            {
                nod = nod->right;
            }
            delete tmp;
        }
    }

    return nod;
}

template <typename T>
void tree::BST<T>::FreeNode(node_ptr nod){
    if(nod!=NULL){
        FreeNode(nod->left);
        FreeNode(nod->right);
        delete nod;
    }
}

template <typename T>
tree::BST<T>::~BST(){
    FreeNode(root);
}