#include <iostream>
using namespace std;

template <typename T>
class DLL{ //Doubly Linked List
protected:
    struct node{
        T data;
        node *prev,*next;
    };
    typedef node* node_ptr;
    node_ptr head,tail;//head and tail as dummy node

public:
    DLL();
    void Add(T data);
    void Print();
    ~DLL();
};

template <typename T>
class Queue:public DLL<T>{
//front=head->next,rear=tail->prev

public:
    Queue(){};
    int isEmpty();
    void Enqueue(T item);
    void Dequeue();
    void Front();
    void Rear();
    void Clear();
    ~Queue(){};
};

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    Queue<int> list;

    while(s){
        cin>>m;

        switch (m)
        {
            case 'e':
                cin>>n;
                list.Enqueue(n);
                break;
                
            case 'd':
                list.Dequeue();
                break;

            case 'm':
                cout<<list.isEmpty()<<endl;
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
                s=0;
                break;
        }

    }
    return 0;
}

template <typename T>
DLL<T>::DLL():head(new node),tail(new node){
    head->next=tail;
    head->prev=NULL;

    tail->prev=head;
    tail->next=NULL;
}

template <typename T>
void DLL<T>::Add(T data){
    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;
    temp->next=tail;
    temp->prev=tail->prev;

    tail->prev->next=temp;
    tail->prev=temp;
}

template <typename T>
void DLL<T>::Print(){
    if(head->next==tail){
        cout<<"The queue is empty";
    }
    else{
        for(node_ptr i=head->next;i!=tail;i=i->next){
            cout<<i->data<<" ";
        }
    }

    cout<<endl;
}

template <typename T>
DLL<T>::~DLL(){
    tail=NULL;

    while(head){
        node_ptr temp=head;
        head=head->next;
        delete temp;
    }
}

template <typename T>
int Queue<T>::isEmpty(){
    if(this->head->next==this->tail){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void Queue<T>::Enqueue(T item){
    this->Add(item);
}

template <typename T>
void Queue<T>::Dequeue(){
    if(isEmpty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        typename DLL<T>::node_ptr i=this->head->next;

        T tmp=i->data;

        i->prev->next=i->next;
        i->next->prev=i->prev;
        delete i;

    }
}

template <typename T>
void Queue<T>::Front(){
    if(isEmpty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<this->head->next->data<<endl;
    }
}

template <typename T>
void Queue<T>::Rear(){
    if(isEmpty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<this->tail->prev->data<<endl;
    }
}

template <typename T>
void Queue<T>::Clear(){
    typename DLL<T>::node_ptr temp=this->head->next;
    while(temp!=this->tail){
        typename DLL<T>::node_ptr tmp=temp;
        temp=temp->next;
        this->head->next=temp;
        temp->prev=this->head;
        delete tmp;
    }
}