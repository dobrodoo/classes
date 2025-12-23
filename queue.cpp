//
// Created by Александр on 26.11.2025.
//

#include "queue.h"
#include <algorithm>

ArrayQueue::ArrayQueue(int size) : size(size), head(0), tail(0), n(0) {
    p = new int[size];
}

ArrayQueue::ArrayQueue(const ArrayQueue& q) : size(q.size), head(q.head), tail(q.tail), n(q.n) {
    p = new int[size];
    for (int i = 0; i < size; i++) {
        p[i] = q.p[i];
    }
}

ArrayQueue::~ArrayQueue() {
    delete[] p;
}

void ArrayQueue::enqueue(int value) {
    if (isFull()) throw FullQueueException();
    p[tail] = value;
    tail = (tail + 1) % size;
    n++;
}

int ArrayQueue::dequeue() {
    if (isEmpty()) throw EmptyQueueException();
    int value = p[head];
    head = (head + 1) % size;
    n--;
    return value;
}

int ArrayQueue::front() const {
    if (isEmpty()) throw EmptyQueueException();
    return p[head];
}

bool ArrayQueue::isEmpty() const { return n == 0; }
bool ArrayQueue::isFull() const { return n == size; }
int ArrayQueue::getSize() const { return size; }
int ArrayQueue::getCount() const { return n; }

int* ArrayQueue::toArray() const {
    int* arr = new int[n];
    int current = head;
    for (int i = 0; i < n; i++) {
        arr[i] = p[current];
        current = (current + 1) % size;
    }
    return arr;
}

void ArrayQueue::fromArray(int* arr, int count) {
    head = tail = n = 0;
    for (int i = 0; i < count && i < size; i++) {
        enqueue(arr[i]);
    }
}

static void quickSort(int* arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

static bool binarySearch(int* arr, int size, int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return true;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

void sortQueue(ArrayQueue& q) {
    int count = q.getCount();
    int* arr = q.toArray();
    quickSort(arr, 0, count - 1);
    q.fromArray(arr, count);
    delete[] arr;
}

bool binarySearchInQueue(ArrayQueue& q, int value) {
    int count = q.getCount();
    int* arr = q.toArray();
    quickSort(arr, 0, count - 1);
    bool result = binarySearch(arr, count, value);
    delete[] arr;
    return result;
}