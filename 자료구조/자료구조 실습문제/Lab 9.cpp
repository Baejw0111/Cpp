#include <iostream>
using namespace std;

template <typename T>
class DLL
{ // Doubly Linked List
protected:
    struct node
    {
        T data;
        node *prev, *next;
    };
    typedef node *node_ptr;
    node_ptr head, tail;

public:
    DLL();
    void Add(T data);
    ~DLL();
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
class AVL{
    struct node{
        T data;
        node *left,*right;
        int height;
    };
    typedef node* node_ptr;

    public:
        node_ptr root;
        AVL();
        int MaxHeight(node_ptr nod);
        node_ptr RightRotate(node_ptr nodeA);
        node_ptr LeftRotate(node_ptr nodeA);
        int GetBF(node_ptr nod);
        node_ptr Rebalance(node_ptr nod);
        node_ptr Insert(node_ptr nod,T n);
        void InOrder(node_ptr nod);
        node_ptr ReturnMin(node_ptr nod);
        node_ptr Delete(node_ptr nod,T n);
        void FreeNode(node_ptr nod);
        ~AVL();
};

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    AVL<int> t;

    while(s){
        cin>>m;

        switch (m)
        {
            case 'i':
                cin>>n;
                t.root=t.Insert(t.root,n);
                break;
                
            case 't':
                t.InOrder(t.root);
                break;

            case 'r':
                cin >> n;
                t.root = t.Delete(t.root, n);
                break;

            case 'x':
                s=0;
                break;
        }

    }

    return 0;
}

template <typename T>
DLL<T>::DLL() : head(new node), tail(new node)
{
    head->next = tail;
    head->prev = NULL;

    tail->prev = head;
    tail->next = NULL;
}

template <typename T>
void DLL<T>::Add(T data)
{
    node_ptr temp = NULL;
    temp = new node;
    temp->data = data;
    temp->next = tail;
    temp->prev = tail->prev;

    tail->prev->next = temp;
    tail->prev = temp;
}

template <typename T>
DLL<T>::~DLL()
{
    tail = NULL;

    while (head)
    {
        node_ptr temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
int Stack<T>::isEmpty(){
    if(this->head->next==this->tail){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void Stack<T>::Push(T item){
    this->Add(item);
}

template <typename T>
T Stack<T>::Pop(){//삭제
    typename DLL<T>::node_ptr i=this->tail->prev;

    T tmp=i->data;

    i->prev->next=i->next;
    i->next->prev=i->prev;
    delete i;

    return tmp;
}

template <typename T>
T Stack<T>::Top(){
    return this->tail->prev->data;
}

template <typename T>
AVL<T>::AVL():root(NULL){}

template <typename T>
int AVL<T>::MaxHeight(node_ptr nod){
    if(nod->left){
        if(nod->right){
            if(nod->left->height>nod->right->height){ return nod->left->height;
                return nod->left->height;
            }
            else{
                return nod->right->height;
            }
        }
        else{
            return nod->left->height;
        }
    }
    else{
        if(nod->right){
            return nod->right->height;
        }
        else{
            return 0;
        }
    }
}


template <typename T>
typename AVL<T>::node_ptr AVL<T>::RightRotate(node_ptr nodeA){
    node_ptr nodeB=nodeA->left;
    node_ptr nodeBchild=nodeB->right;

    nodeB->right=nodeA;
    nodeA->left=nodeBchild;

    nodeA->height=1+MaxHeight(nodeA);
    nodeB->height=1+MaxHeight(nodeB);

    return nodeB;
}

template <typename T>
typename AVL<T>::node_ptr AVL<T>::LeftRotate(node_ptr nodeA){
    node_ptr nodeB=nodeA->right;
    node_ptr nodeBchild=nodeB->left;

    nodeB->left=nodeA;
    nodeA->right=nodeBchild;

    nodeA->height=1+MaxHeight(nodeA);
    nodeB->height=1+MaxHeight(nodeB);

    return nodeB;
}

template <typename T>
int AVL<T>::GetBF(node_ptr nod){
    int hl,hr;
    if(nod->left==NULL){
        hl=0;
    }
    else{
        hl=nod->left->height;
    }

    if(nod->right==NULL){
        hr=0;
    }
    else{
        hr=nod->right->height;
    }

    int bf=hl-hr;

    return bf;
}

template <typename T>
typename AVL<T>::node_ptr AVL<T>::Rebalance(node_ptr nod){
    if(!nod){
        return nod;
    }

    int bf=GetBF(nod);

    if(bf>1){
        if(nod->left->left){//LL case
            return RightRotate(nod);
        }
        else{//LR case
            nod->left=LeftRotate(nod->left);
            return RightRotate(nod);
        }
    }
    else if(bf<-1){
        if(nod->right->right){//RR case
            return LeftRotate(nod);
        }
        else{//RL case
            nod->right=RightRotate(nod->right);
            return LeftRotate(nod);
        }
    }

    return nod;
}

template <typename T>
typename AVL<T>::node_ptr AVL<T>::Insert(node_ptr nod,T n){
    if(nod==NULL){
        node_ptr tmp=new node;
        tmp->data=n;
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->height=1;

        return tmp;
    } 

    if(n<nod->data){
        nod->left=Insert(nod->left,n);
    }
    else{
        nod->right=Insert(nod->right,n);
    }

    nod->height=1+MaxHeight(nod);
    nod=Rebalance(nod);
    nod->height=1+MaxHeight(nod);

    return nod;
}

template <typename T>
void AVL<T>::InOrder(node_ptr nod){
    Stack<node_ptr> stack;

    while(1){
        while(nod){
            stack.Push(nod);
            nod=nod->left;
        }

        if(stack.isEmpty()){
            break;
        }

        nod=stack.Pop();

        cout<<nod->data<<" ";
        nod=nod->right;
    }
    cout<<endl;
}

template <typename T>
typename AVL<T>::node_ptr AVL<T>::ReturnMin(node_ptr nod)
{
    while (nod->left)
    {
        nod = nod->left;
    }

    return nod;
}

template <typename T>
typename AVL<T>::node_ptr AVL<T>::Delete(node_ptr nod, T n)
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

    if(nod){
        nod->height=1+MaxHeight(nod);
    }
    nod=Rebalance(nod);
    if(nod){
        nod->height=1+MaxHeight(nod);
    }

    return nod;
}

template <typename T>
void AVL<T>::FreeNode(node_ptr nod){
    if(nod!=NULL){
        FreeNode(nod->left);
        FreeNode(nod->right);
        delete nod;
    }
}

template <typename T>
AVL<T>::~AVL(){
    FreeNode(root);
}