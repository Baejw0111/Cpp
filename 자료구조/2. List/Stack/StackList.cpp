#include "../List.h"
#include "../DLL/DLL.cpp"
//부모 클래스의 생성자가 먼저 호출되고, 소멸자도 가장 나중에 호출된다.

template <typename T>
int lst::Stack<T>::isEmpty(){
    if(this->head->next==this->tail){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void lst::Stack<T>::Push(T item){
    this->Add(item);
}

template <typename T>
T lst::Stack<T>::Pop(){//삭제
    typename DLL<T>::node_ptr i=this->tail->prev;

    T tmp=i->data;

    i->prev->next=i->next;
    i->next->prev=i->prev;
    delete i;

    return tmp;
}

template <typename T>
T lst::Stack<T>::Top(){
    return this->tail->prev->data;
}