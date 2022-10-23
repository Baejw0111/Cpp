#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Cqueue{
    T *q;
    int size,rear,front;

public:
    Cqueue(int n);
    int isEmpty();
    int isFull();
    void Insert(T item);
    void Delete();
    void Print();
    void Front();
    void Rear();
    void Clear();
    ~Cqueue();
};

int main()
{
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.

    cin >> n;
    Cqueue<int> list(n);

    while (s)
    {
        cin >> m;

        switch (m)
        {
        case 'e':
            cin >> n;
            list.Insert(n);
            break;

        case 'd':
            list.Delete();
            break;

        case 'm':
            cout << list.isEmpty() << endl;
            break;

        case 'u':
            cout<<list.isFull()<<endl;
            break;

        case 'c':
            list.Clear();
            break;

        case 'f':
            list.Front();
            break;

        case 'r':
            list.Rear();
            break;

        case 'p':
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
Cqueue<T>::Cqueue(int n):
size(n),q(new T[n]),front(-1),rear(-1){}

template <typename T>
int Cqueue<T>::isEmpty(){
    if(rear==-1&&front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
int Cqueue<T>::isFull(){
    if((rear+1)%size==front){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void Cqueue<T>::Insert(T item){
    if(isFull()){
        cout << "The queue is full" << endl;
        return;
    }
    else if(isEmpty()){
        front=0;
    }
    q[(++rear)%size]=item;
}

template <typename T>
void Cqueue<T>::Delete(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
        return;
    }
    else if(front==rear){
        Clear();
        return;
    }
    else{
        ++front;
    }
}

template <typename T>
void Cqueue<T>::Print(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
    }
    else{
        for(int j=front;j<=rear;j++){
            cout<<q[j%size]<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
void Cqueue<T>::Front(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
    }
    else{
        cout<<q[front]<<endl;
    }
}

template <typename T>
void Cqueue<T>::Rear(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
    }
    else{
        cout<<q[rear]<<endl;
    }
}

template <typename T>
void Cqueue<T>::Clear(){
    front=rear=-1;
}

template <typename T>
Cqueue<T>::~Cqueue(){
    delete[] q;
}