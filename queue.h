//
// Created by Александр on 26.11.2025.
//

#ifndef QUEUE_H
#define QUEUE_H

class ArrayQueue {
private:
    int size;
    int* p;
    int head;
    int tail;
    int n;

public:
    class EmptyQueueException {};
    class FullQueueException {};

    explicit ArrayQueue(int size);
    ArrayQueue(const ArrayQueue& q);
    ~ArrayQueue();

    void enqueue(int value);
    int dequeue();
    int front() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    int getCount() const;

    int* toArray() const;
    void fromArray(int* arr, int count);
};

void sortQueue(ArrayQueue& q);
bool binarySearchInQueue(ArrayQueue& q, int value);

#endif