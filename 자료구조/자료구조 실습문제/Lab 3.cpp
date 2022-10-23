#include <iostream>
using namespace std;

template <typename T>
class DLL{ //Doubly Linked List
    struct node{
        T data;
        node *prev,*next;
    };
    typedef node* node_ptr;
    node_ptr head,tail;//head and tail is dummy node.
    int len;

public:
    DLL();
    void Add(T data);
    void Insert(T data,int index);
    void Remove(T data);     
    void Delete(int index);
    void Print();
    void Len();
    void ReversePrint();
    void ReverseSort();
    void Erase();
    ~DLL();
};

int main(){
    int s=0,n,m;//'s' is for switch of loop. 'n' and 'm' is temporary variable used in loop
    char mode;//for mode input
    DLL<int> list;

    while(s==0){
        cin>>mode;

        switch (mode)
        {
            case 'a':
                cin>>n;
                list.Add(n);
                break;
                
            case 'i':
                cin>>n>>m;
                list.Insert(n,m);
                break;

            case 'r':
                cin>>n;
                list.Remove(n);
                break;

            case 'd':
                cin>>n;
                list.Delete(n);
                break;

            case 'p':
                list.Print();
                break;

            case 'l':
                list.Len();
                break;

            case 't':
                list.ReversePrint();
                break;
            
            case 'v':
                list.ReverseSort();
                break;

            case 'e':
                list.Erase();
                break;

            case 'x':
                s++;
                break;
        }

    }
    return 0;
}

template <typename T>
DLL<T>::DLL():head(new node),tail(new node),len(0){//initialize
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

    len++;//increase length
}

template <typename T>
void DLL<T>::Insert(T data,int index){
    if(index<=0){//index is subzero or zero, return this operation
        return;
    }
    else if(index>=len+1){//index is over range, execute Add func
        Add(data);
        return;
    }

    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;

    node_ptr cur=head->next;//'cur' point current node
    //We'll go through the entire list with this
    int n=1;//start with index 1

    while(n<index){//until index==n
        cur=cur->next;
        n++;
    }
    
    //link new node with previous node and current node 
    temp->next=cur;
    temp->prev=cur->prev;

    cur->prev->next=temp;
    cur->prev=temp;

    len++;
}

template <typename T>
void DLL<T>::Remove(T data){
    for(node_ptr i=head->next;i!=tail;i=i->next){
        if(i->data==data){
            i->prev->next=i->next;
            i->next->prev=i->prev;
            delete i;
            len--;//decrease length
            return;
        }
    }

    //if there isn't target data in list
    cout<<"Not found"<<endl;
    return;
}

template <typename T>
void DLL<T>::Delete(int index){
    if(len<index||index<=0){//if index is out of range
        return;
    }

    node_ptr cur=head->next;
    int n=1;

    while(n<index){
        cur=cur->next;
        n++;
    }

    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;

    delete cur;

    len--;
}

template <typename T>
void DLL<T>::Print(){
    for(node_ptr i=head->next;i!=tail;i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
}

template <typename T>
void DLL<T>::Len(){
    cout<<len<<endl;
}

template <typename T>
void DLL<T>::ReversePrint(){
    for(node_ptr i=tail->prev;i!=head;i=i->prev){
        cout<<i->data<<" ";
    }
    cout<<endl;
}

template <typename T>
void DLL<T>::ReverseSort(){
    if(len<=1){//when reversing list is meaningless
        return;
    }

    for(node_ptr i=head;i;i=i->prev){
        node_ptr tmp=i->prev;
        i->prev=i->next;
        i->next=tmp;
    }

    node_ptr temp=head;
    head=tail;
    tail=temp;

}

template <typename T>
void DLL<T>::Erase(){
    for(node_ptr i=head->next;i!=tail;){//deallocation all node except head node and tail node
        node_ptr temp=i;
        i=i->next;
        delete temp;
        len--;
    }

    head->next=tail;
    tail->prev=head;
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