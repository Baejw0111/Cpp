#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *s;//Array of stack
    int size, top;

public:
    Stack(int n);
    int isEmpty();
    int isFull();
    void Push(T item);
    void Pop();
    void Top();
    void Print();
    ~Stack();
};

int main()
{
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.

    cin >> n;
    Stack<int> list(n);

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

        case 'f':
            cout<<list.isFull()<<endl;
            break;

        case 't':
            list.Top();
            break;

        case 'e':
            cout << list.isEmpty() << endl;
            break;

        case 'd':
            list.Print();
            break;

        case 'x':
            s--;
            break;
        }
    }
    return 0;
}

template <typename T>
Stack<T>::Stack(int n) : size(n), s(new T[n]), top(-1) {}

template <typename T>
int Stack<T>::isEmpty()
{
    if (top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
int Stack<T>::isFull()
{
    if (top >= size - 1)
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
    if (isFull())
    {
        cout << "The stack is full" << endl;
        return;
    }
    s[++top] = item;
}

template <typename T>
void Stack<T>::Pop()
{
    top--;
}

template <typename T>
void Stack<T>::Top()
{
    cout << s[top] << endl;
}

template <typename T>
void Stack<T>::Print()
{
    for (int i = 0; i < top + 1; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] s;
}