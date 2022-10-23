#include <iostream>
using namespace std;

template <typename T>
class SLL
{ // Singly Linked List
protected:
    struct node
    {
        T data;
        node *next;
    };
    typedef node *node_ptr;
    node_ptr head, tail, top;
    // head and tail is dummy node.
    // So we can generalize add node and delete node.
    // top is top of stack.(before tail node)

public:
    SLL();
    void Add(T data); // add node before tail node
    void Delete(T data);
    void Print();
    ~SLL();
};

template <typename T>
class Stack : public SLL<T>
{
public:
    Stack(){};
    int isEmpty();
    void Push(T item);
    void Pop();
    void Top();
    ~Stack(){};
};

int main()
{
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    Stack<int> list;

    while (s)
    {
        cin >> m;

        switch (m)
        {
        case 'p':
            cin >> n;
            list.Push(n);
            break;

        case 'r':
            if (list.isEmpty())
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                list.Pop();
            }
            break;

        case 't':
            list.Top();
            break;

        case 'e':
            cout << list.isEmpty() << endl;
            break;

        case 'd':
            list.SLL::Print();
            break;

        case 'x':
            s--;
            break;
        }
    }
    return 0;
}

template <typename T>
SLL<T>::SLL() : head(new node), tail(new node), top(head)
{
    head->next = tail;
    tail->next = NULL;
}

template <typename T>
void SLL<T>::Add(T data)
{
    node_ptr temp = NULL;
    temp = new node;
    temp->data = data;
    temp->next = top->next;

    top->next = temp;
    top = top->next;
}

template <typename T>
void SLL<T>::Delete(T data)
{
    node_ptr before = head;

    for (node_ptr i = head->next; i != tail; i = i->next)
    {
        if (i->data == data)
        {
            before->next = i->next;
            if (top == i)
            {
                top = before;
            }
            delete i;
            break;
        }
        before = i;
    }
}

template <typename T>
void SLL<T>::Print()
{
    for (node_ptr i = head->next; i != tail; i = i->next)
    {
        cout << i->data << " ";
    }

    cout << endl;
}

template <typename T>
SLL<T>::~SLL()
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
int Stack<T>::isEmpty()
{
    if (this->top == this->head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
void Stack<T>::Push(T item)
{
    this->Add(item);
}

template <typename T>
void Stack<T>::Pop()
{
    this->Delete(this->top->data);
}

template <typename T>
void Stack<T>::Top()
{
    cout << this->top->data << endl;
}