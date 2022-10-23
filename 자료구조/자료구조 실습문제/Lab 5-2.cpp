#include <iostream>
#include <string>
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
    T Pop();
    T Top();
    ~Stack(){};
};

int Calculate(char operat,int a,int b){
    int c=1;

    switch (operat)
    {
    case '+':
        c=a+b;
        break;
    
    case '-':
        c=a-b;
        break;

    case '*':
        c=a*b;
        break;

    case '/':
        c=a/b;
        break;

    case '^':
        for(int i=0;i<b;i++){
            c*=a;
        }
        break;
    }
    
    return c;
}

int main()
{
    string input;
    cin>>input;

    string preced_s="+-/*^";//precedence list as string

    Stack<int> Operand;//Operand Stack

    for(int i=0;i<input.length();i++){
        if(preced_s.find(input[i])==string::npos){
            Operand.Push(input[i]-'0');
        }//if input[i] is operand

        else{//if input[i] is operator

            Operand.Push(Calculate(input[i],Operand.Pop(),Operand.Pop()));
            //Operand.Print();
            //This is for debugging
        }
    }

    cout<<Operand.Pop()<<endl;

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
    cout<<"\ncurrent stack:";
    for (node_ptr i = head->next; i != tail; i = i->next)
    {
        cout << i->data << " ";
    }
    cout << endl;
    cout<<"Top:"<<top->data<<endl;
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
T Stack<T>::Pop()//pop top
{
    T tmp=this->top->data;
    typename SLL<T>::node_ptr before = this->head;

    for (typename SLL<T>::node_ptr i = this->head->next; i != this->tail; i = i->next)
    {
        if (i == this->top)
        {
            before->next = i->next;
            this->top = before;
            delete i;
            break;
        }
        before = i;
    }

    return tmp;
}

template <typename T>
T Stack<T>::Top()//return top
{
    return this->top->data;
}