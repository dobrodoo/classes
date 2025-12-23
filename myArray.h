#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

class myArray {
private:
    int* data;
    int size;

public:
    myArray();
    explicit myArray(int size);
    myArray(int* arr, int size);
    myArray(const myArray& other);
    myArray& operator=(const myArray& other);
    ~myArray();

    int getSize() const { return size; }
    int* getData() const { return data; }

    void setValue(int index, int value);

    myArray operator+(int value) const;  // Прибавление числа ко всем элементам
    myArray operator-(int value) const;  // Вычитание числа из всех элементов
    myArray& operator+=(int value);      // Прибавление с изменением
    myArray& operator-=(int value);      // Вычитание с изменением

    void print() const;
};

class ArrayUtils {
public:
    static bool getPalindromeFromNumber(int number, std::string& result);

    static bool sortArray(int arr[], int size, int sortType);
    static void insertionSort(int arr[], int size);
    static void selectionSort(int arr[], int size);
    static void bubbleSort(int arr[], int size);

    static int binarySearch(int arr[], int size, int key);

    static bool findRectangleInMatrix(int matrix[5][5], int num1, int num2, int num3, int num4);

    static std::vector<std::pair<int, int>> findSaddlePoints(int** matrix, int size);
};

#endif