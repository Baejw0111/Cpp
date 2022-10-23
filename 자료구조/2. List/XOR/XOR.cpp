#include "../List.h"
#define LLI long long int

template <typename T>
lst::XOR<T>::XOR():head(new node),tail(new node){
    head->npx=(node_ptr)(0^(LLI)(tail));
    tail->npx=(node_ptr)(0^(LLI)(head));
}

template <typename T>
typename lst::XOR<T>::node_ptr lst::XOR<T>::Prev(node_ptr cur,node_ptr next){
    return (node_ptr)(((LLI)(cur->npx)^(LLI)(next)));
}

template <typename T>
typename lst::XOR<T>::node_ptr lst::XOR<T>::Next(node_ptr cur,node_ptr prev){
    return (node_ptr)(((LLI)(cur->npx)^(LLI)(prev)));
}

template <typename T>
void lst::XOR<T>::Add(T data){
    node_ptr prev=Prev(tail,0);

    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;
    temp->npx=(node_ptr)((LLI)(tail)^(LLI)(prev));   

    prev->npx=(node_ptr)((LLI)(prev->npx)^(LLI)(tail)^(LLI)(temp));
    tail->npx=(node_ptr)(0^(LLI)(temp));
}

template <typename T>
void lst::XOR<T>::Delete(T data){
    for(node_ptr i=Next(head,0),j=head,k=Next(i,j);i!=tail;j=i,i=k,k=Next(k,j)){
        if(i->data==data){
            j->npx=(node_ptr)((LLI)(j->npx)^(LLI)(i)^(LLI)(k));
            k->npx=(node_ptr)((LLI)(k->npx)^(LLI)(i)^(LLI)(j));

            delete i;
            break;
        }

    }
}

template <typename T>
void lst::XOR<T>::Print(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터: ";

    for(node_ptr i=Next(head,0),j=head,k=Next(i,j);i!=tail;j=i,i=k,k=Next(k,j)){
        std::cout<<i->data<<" ";
    }

    std::cout<<std::endl;
}


template <typename T>
lst::XOR<T>::~XOR(){
    tail=NULL;

    while(head){
        node_ptr temp=head;
        head=Next(head,0);
        delete temp;
        temp=NULL;
    }
}