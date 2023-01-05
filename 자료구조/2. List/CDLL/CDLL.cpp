#include "../List.h"

template <typename T>
lst::CDLL<T>::CDLL():head(new node){
    head->next=head;
    head->prev=head;
}

template <typename T>
void lst::CDLL<T>::Add(T data){
    node_ptr temp=NULL;
    temp=new node;
    temp->data=data;

    head->next->prev->next=temp;
    if(temp!=head->next){
        temp->prev=head->next->prev;
    }
    head->next->prev=temp;
    temp->next=head->next;
}

template <typename T>
void lst::CDLL<T>::Delete(T data){
    node_ptr i=head->next;
    do{
        if(i->data==data){
            if(i==head->next){
                if(head->next->next==head->next){
                    head->next=head;
                }
                else{
                    head->next=i->next;
                }
            }
            i->prev->next=i->next;
            i->next->prev=i->prev;
            delete i;
            return;
        }

        i=i->next;
    }while(i!=head->next);
}

template <typename T>
void lst::CDLL<T>::Print(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터: ";

    node_ptr i=head->next;
    do{
        std::cout<<i->data<<" ";

        i=i->next;
    }while(i!=head->next);

    std::cout<<std::endl;
}

template <typename T>
void lst::CDLL<T>::Reverse(){
    std::cout<<std::endl;
    std::cout<<"현재 데이터(역순): ";

    node_ptr i=head->next->prev;
    do{
        std::cout<<i->data<<" ";

        i=i->prev;
    }while(i!=head->next->prev);

    std::cout<<std::endl;
}

template <typename T>
void lst::CDLL<T>::Josephus(int n,int k){
    for(int i=1;i<=n;i++){
        this->Add(i);
    }

    node_ptr cur=head->next;
    int i=1;

    std::cout<<"Josephus Permutation: ";

    while(cur->next!=cur){
        if(i==k){
            int tmp=cur->data;
            std::cout<<tmp<<" ";
            cur=cur->next;
            this->Delete(tmp);
            i=0;
        }
        else{
            cur=cur->next;
        }
        i++;
    } 
    std::cout<<cur->data<<std::endl;

    std::cout<<"Last: "<<cur->data<<std::endl;
}


template <typename T>
lst::CDLL<T>::~CDLL(){
    head->next->prev->next=NULL;

    while(head){
        node_ptr tmp=head;
        head=head->next;
        delete tmp;
    }
}