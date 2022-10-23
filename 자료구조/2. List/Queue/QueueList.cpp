#include "../List.h"
#include "../DLL/DLL.cpp"
//부모 클래스의 생성자가 먼저 호출되고, 소멸자도 가장 나중에 호출된다.

template <typename T>
int lst::Queue<T>::isEmpty(){
    if(this->head->next==this->tail){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void lst::Queue<T>::Enqueue(T item){
    this->Add(item);
}

template <typename T>
T lst::Queue<T>::Dequeue(){//삭제
    typename DLL<T>::node_ptr i=this->head->next;

    T tmp=i->data;

    i->prev->next=i->next;
    i->next->prev=i->prev;
    delete i;

    return tmp;
}

template <typename T>
T lst::Queue<T>::Front(){
    return this->head->next->data;
}

template <typename T>
T lst::Queue<T>::Rear(){
    return this->tail->prev->data;
}