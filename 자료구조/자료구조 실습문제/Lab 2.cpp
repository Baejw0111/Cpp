#include <iostream>
using namespace std;

template <typename T>
class SLL{
    struct node{
        T data;
        node *next;
    };
    typedef node* node_ptr;
    node_ptr head,tail; //tail is for last node
    int len; //length of the list

public:
    SLL();
    void Add(T data);
    void Insert(T data,int index);
    void Remove(T data);     
    void Delete(int index);
    void Print();
    void Len();
    // void Reverse();
    // void Erase();
    ~SLL();
};

int main(){
    int s=0,n,m;//'s' is for switch of loop. 'n' and 'm' is temporary variable used in loop
    char mode;//for mode input
    SLL<int> list;

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
            
            // case 'v':
            //     list.Reverse();
            //     break;

            // case 'e':
            //     list.Erase();
            //     break;

            case 'x':
                s++;
                break;
        }

    }
    return 0;
}

template <typename T>
SLL<T>::SLL()://initialize
    head(NULL),tail(NULL),len(0){}

template <typename T>
void SLL<T>::Add(T data){
    node_ptr temp=NULL;//new node to add
    temp=new node;
    temp->data=data;
    temp->next=NULL;

    if(!head){//if list is empty
        head=temp;
        tail=head;
    }
    else{//if list is not empty
        tail->next=temp;
        tail=tail->next;
    }

    len++;//increase length
}

template <typename T>
void SLL<T>::Insert(T data,int index){
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
    temp->next=NULL;

    node_ptr cur=head,before=head;//'cur' point current node, 'before' point previous node of current node
    //We'll go through the entire list with these
    int n=1;//start with index 1

    while(n<index){//until index==n
        if(cur!=head){//when the current node pointer is head, don't move 'before' pointer
            before=before->next;
        }
        cur=cur->next;
        n++;
    }
    temp->next=cur;//link new node as previous node for target index node

    if(cur==head){//if target index is first index
        head=temp;
    }
    else{
        before->next=temp;
    }

    len++;
}

template <typename T>
void SLL<T>::Remove(T data){
    node_ptr cur=head,before=head;//same as before

    while(cur!=NULL&&cur->data!=data){//until current node pointer at the end, or current node data==target data
        if(cur!=head){//same as before
            before=before->next;
        }
        cur=cur->next;
    }

    if(cur==NULL){//if list is empty or data doesn't exist
        cout<<"Not found"<<endl;
        return;
    }
    else if(cur==head){//if data is in head
        head=head->next;
    }
    else{
        before->next=cur->next;
    }
    delete cur;//deallocation target node
    len--;//decrease length
}

template <typename T>
void SLL<T>::Delete(int index){
    if(len<index||index<=0){//if index is out of range
        return;
    }

    node_ptr cur=head,before=head;
    int n=1;

    while(n<index){
        if(cur!=head){
            before=before->next;
        }
        cur=cur->next;
        n++;
    }
    if(cur==head){
        head=head->next;
    }
    else{
        before->next=cur->next;
    }
    delete cur;

    len--;
}

template <typename T>
void SLL<T>::Print(){
    if(head){
        tail=head;
        for(;tail->next;tail=tail->next){
            cout<<tail->data<<" ";
        }
        cout<<tail->data<<" ";
        cout<<endl;
    }
}

template <typename T>
void SLL<T>::Len(){
    cout<<len<<endl;
}

// template <typename T>
// void SLL<T>::Reverse(){
//     if(len<=1){//when reversing list is meaningless
//         return;
//     }

//     node_ptr cur=head,post_head=tail;//post head is for new head node

//     tail=head;//tail will be used as 'before' pointer

//     while(cur!=post_head){
//         if(cur!=head){
//             tail=tail->next;
//         }
//         cur=cur->next;
//     }
//     cur->next=tail;//move current pointer to last node
//     cur=cur->next;//change link direction of last node

//     while(tail!=head){//until change all node link direction except head node
//         tail=head;
//         while(tail->next!=cur){
//             tail=tail->next;
//         }
//         cur->next=tail;
//         cur=cur->next;
//     }

//     tail->next=NULL;//change link direction of original head node
//     head=post_head;//update new head node
// }

// template <typename T>
// void SLL<T>::Erase(){
//     if(head){//if head is not NULL
//         tail=NULL;//NULL for tail first
//         while(head){//deallocation all node until it's done
//             node_ptr temp=head;
//             head=head->next;
//             delete temp;
//             len--;
//         }
//     }
// }

template <typename T>
SLL<T>::~SLL(){
    tail=NULL;
    if(head){
        while(head){
            node_ptr temp=head;
            head=head->next;
            delete temp;
        }
    }
}