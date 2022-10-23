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
class Queue : public DLL<T>
{
    // front=head->next,rear=tail->prev

public:
    Queue(){};
    int isEmpty();
    void Enqueue(T item);
    T Dequeue();
    T Front();
    T Rear();
    ~Queue(){};
};

template <typename T>
class BST
{
    struct node
    {
        T data;
        node *left, *right;
    };
    typedef node *node_ptr;

public:
    node_ptr root;
    BST();
    node_ptr Insert(node_ptr nod, T n);
    void Search(node_ptr nod, T n);
    void FreeNode(node_ptr nod);
    ~BST();
};

int main()
{
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    BST<int> t;

    while (s)
    {
        cin >> m;

        switch (m)
        {
        case 'i':
            cin >> n;
            t.root = t.Insert(t.root, n);
            break;

        case 's':
            cin >> n;
            t.Search(t.root, n);
            break;

        case 'x':
            s = 0;
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
int Queue<T>::isEmpty()
{
    if (this->head->next == this->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
void Queue<T>::Enqueue(T item)
{
    this->Add(item);
}

template <typename T>
T Queue<T>::Dequeue()
{
    typename DLL<T>::node_ptr i = this->head->next;

    T tmp = i->data;

    i->prev->next = i->next;
    i->next->prev = i->prev;
    delete i;

    return tmp;
}

template <typename T>
BST<T>::BST() : root(NULL) {}

template <typename T>
typename BST<T>::node_ptr BST<T>::Insert(node_ptr nod, T n)
{
    if (nod == NULL)
    {
        node_ptr tmp = new node;
        tmp->data = n;
        tmp->left = NULL;
        tmp->right = NULL;

        return tmp;
    }

    if (n < nod->data)
    {
        nod->left = Insert(nod->left, n);
    }
    else
    {
        nod->right = Insert(nod->right, n);
    }
    return nod;
}

template <typename T>
void BST<T>::Search(node_ptr nod, T n)
{
    Queue<char> answer;

    answer.Enqueue('H');

    while (1)
    {
        if (nod->data > n)
        {
            answer.Enqueue('L');
            nod = nod->left;
        }
        else if (nod->data < n)
        {
            answer.Enqueue('R');
            nod = nod->right;
        }
        else
        {
            break;
        }

        if (!nod)
        {
            cout << -1 << endl;
            return;
        }
    }

    while (!answer.isEmpty())
    {
        cout << answer.Dequeue();
    }
    cout << endl;
}

template <typename T>
void BST<T>::FreeNode(node_ptr nod)
{
    if (nod != NULL)
    {
        FreeNode(nod->left);
        FreeNode(nod->right);
        delete nod;
    }
}

template <typename T>
BST<T>::~BST()
{
    FreeNode(root);
}