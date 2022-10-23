#include "../List.h"

template <typename T>
lst::SLL<T>::SLL():head(new node),tail(new node),cur(head){
    head->next=tail;
    tail->next=NULL;
}

template <typename T>
void lst::SLL<T>::Add(T data){
    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;
    temp->next=cur->next;

    cur->next=temp;
    cur=cur->next;
}

template <typename T>
void lst::SLL<T>::Delete(T data){
    node_ptr before=head;

    for(node_ptr i=head->next;i!=tail;i=i->next){
        if(i->data==data){
            before->next=i->next;
            if(cur==i){
                cur=before;
            }
            delete i;
            break;
        }
        before=i;
    }
}

template <typename T>
void lst::SLL<T>::Print(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터: ";

    for(node_ptr i=head->next;i!=tail;i=i->next){
        std::cout<<i->data<<" ";
    }

    std::cout<<std::endl;
}

template <typename T>
lst::SLL<T>::~SLL(){
    tail=NULL;
    while(head){
        node_ptr temp=head;
        head=head->next;
        delete temp;
    }
}