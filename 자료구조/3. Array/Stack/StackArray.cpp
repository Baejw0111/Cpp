#include "../Array.h"

template <typename T>
arr::Stack<T>::Stack(int n):
    size(n),s(new T[n]),top(-1){}

template <typename T>
int arr::Stack<T>::isEmpty(){
    if(top<0){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
int arr::Stack<T>::isFull(){
    if(top>=size-1){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
void arr::Stack<T>::Push(T item){
    if(isFull()){
        return;
    }
    s[++top]=item;
}

template <typename T>
int arr::Stack<T>::Pop(){//삭제
    if(top==-1){
        return isEmpty();
    }
    return s[top--];
}

template <typename T>
void arr::Stack<T>::Print(){
    std::cout<<"Current Stack: ";
    for(int i=0;i<top+1;i++){
        std::cout<<s[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T>
arr::Stack<T>::~Stack(){
    delete[] s;
}