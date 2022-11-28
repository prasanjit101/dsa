#include <iostream>

using namespace std;

class Queue
{
protected:
    int *queue;
    int length;
    int size;
    short int front;
    short int rear;

public:
    Queue(int size)
    {
        this->length = 0;
        this->size = size;
        queue = new int[size];
        front = 0;
        rear = size - 1;
    }
    ~Queue();
    void enqueue(int data)
    {
        if (this->length == 0)
        {
            queue[front] = data;
            this->length++;
        }
        else if (this->length == this->size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = data;
            this->length++;
        }
    }
    int dequeue()
    {
        if (this->length == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int data = queue[front];
            front = (front + 1) % size;
            this->length--;
            return data;
        }
    }
    void print()
    {
        if (this->length == 0)
        {
            cout << "Queue is empty";
        }
        else
        {
            for (int i = 0; i < this->length; i++)
            {
                cout << queue[(front + i) % size] << " ";
            }
        }
    }
    bool isempty()
    {
        return this->length == 0;
    }
};

class dequeue : public Queue
{
public:
    dequeue(int size) : Queue(size) {}
    void enqueue_front(int data)
    {
        if (this->length == 0)
        {
            queue[front] = data;
            this->length++;
        }
        else if (this->length == this->size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            front = (front - 1 + size) % size;
            queue[front] = data;
            this->length++;
        }
    }
    void enqueue_rear(int data)
    {
        if (this->length == 0)
        {
            queue[front] = data;
            this->length++;
        }
        else if (this->length == this->size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = data;
            this->length++;
        }
    }
    int dequeue_front()
    {
        if (this->length == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int data = queue[front];
            front = (front + 1) % size;
            this->length--;
            return data;
        }
    }
    int dequeue_rear()
    {
        if (this->length == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int data = queue[rear];
            rear = (rear - 1 + size) % size;
            this->length--;
            return data;
        }
    }
};

class PriorityQueue : public Queue
{
public:
    PriorityQueue(int size) : Queue(size) {}
    void enqueue(int data)
    {
        if (this->length == 0)
        {
            queue[front] = data;
            this->length++;
        }
        else if (this->length == this->size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            int i = this->length - 1;
            while (i >= 0 && queue[i] > data)
            {
                queue[i + 1] = queue[i];
                i--;
            }
            queue[i + 1] = data;
            this->length++;
        }
    }
};
