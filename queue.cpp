//alaaamer0508@gmail.com

#include "queue.hpp"
#include "stdexcept"

namespace graph{
    Queue::Queue(int cap)
    {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }
    Queue::~Queue()
    {
        delete [] data;
    }
    void Queue::enqueue(int val)
    {
        if(size==capacity)
        {
            throw std::underflow_error("Queue is full");
        }
        data[rear] = val;
        rear = (rear+1)%capacity;
        size++;
    }
    int Queue::dequeue()
    {
        if (Queue::isEmpty())
        {
            throw std::underflow_error("Queue is empty");
        }
        int val = data[front];
        front = (front + 1)% capacity;
        size--;
        return val;
    }
    bool Queue::isEmpty() const
    {
        return size == 0;
    }
}