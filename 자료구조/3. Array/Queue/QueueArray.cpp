#include "../Array.h"

template <typename T>
arr::Queue<T>::Queue(int n) : size(n), q(new T[n]), front(-1), rear(-1) {}

template <typename T>
int arr::Queue<T>::isEmpty()
{
    if (rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
int arr::Queue<T>::isFull()
{
    if (rear >= size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
void arr::Queue<T>::Insert(T item)
{
    if (isFull())
    {
        return;
    }
    q[++rear] = item;
}

template <typename T>
int arr::Queue<T>::Delete()
{
    if (rear == front)
    {
        return isEmpty();
    }
    return q[++front]; // front값이 (첫 원소 위치-1)
}

template <typename T>
void arr::Queue<T>::Print()
{
    std::cout << "current Queue: ";

    for (int j = front + 1; j <= rear; j++)
    {
        std::cout << q[j] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
arr::Queue<T>::~Queue()
{
    delete[] q;
}

template <typename T>
int arr::Cqueue<T>::isEmpty()
{
    if (this->rear == -1 && this->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
template <typename T>
int arr::Cqueue<T>::isFull()
{
    if ((this->rear + 1) % this->size == this->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
void arr::Cqueue<T>::Insert(T item)
{
    if (isFull())
    {
        return;
    }
    else if (isEmpty())
    {
        this->front = 0;
    }
    this->q[(++this->rear) % this->size] = item;
}

template <typename T>
void arr::Cqueue<T>::Delete()
{
    if (isEmpty())
    {
        return;
    }
    if (this->rear == this->front)
    {
        this->rear = this->front = -1;
    }
    else
    {
        ++this->front;
    }
}

template <typename T>
void arr::Cqueue<T>::Print()
{
    if (!isEmpty())
    {
        std::cout << "current Queue: ";

        for (int j = this->front + 1; j <= this->rear; j++)
        {
            std::cout << this->q[j % this->size] << " ";
        }
    }
    std::cout << std::endl;
}