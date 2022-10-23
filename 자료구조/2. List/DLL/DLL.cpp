#ifndef DLL_cpp
#define DLL_cpp
#include "../List.h"

template <typename T>
lst::DLL<T>::DLL():head(new node),tail(new node){
    head->next=tail;
    head->prev=NULL;

    tail->prev=head;
    tail->next=NULL;
}

template <typename T>
void lst::DLL<T>::Add(T data){
    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;
    temp->next=tail;
    temp->prev=tail->prev;

    tail->prev->next=temp;
    tail->prev=temp;
}

template <typename T>
void lst::DLL<T>::Delete(T data){
    for(node_ptr i=head->next;i!=tail;i=i->next){
        if(i->data==data){
            i->prev->next=i->next;
            i->next->prev=i->prev;
            delete i;
            break;
        }
    }
}

template <typename T>
void lst::DLL<T>::Print(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터: ";

    for(node_ptr i=head->next;i!=tail;i=i->next){
        std::cout<<i->data<<" ";
    }

    std::cout<<std::endl;
}

template <typename T>
void lst::DLL<T>::Reverse(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터(역순): ";

    for(node_ptr i=tail->prev;i!=head;i=i->prev){
        std::cout<<i->data<<" ";
    }

    std::cout<<std::endl;
}


template <typename T>
lst::DLL<T>::~DLL(){
    tail=NULL;

    while(head){
        node_ptr temp=head;
        head=head->next;
        delete temp;
    }
}

#endif