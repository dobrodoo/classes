//
// Created by Александр on 26.11.2025.
//

#include "myArray.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <utility>

using namespace std;

// Конструктор по умолчанию
myArray::myArray() : data(nullptr), size(0) {}

// Конструктор с размером
myArray::myArray(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

// Конструктор с массивом
myArray::myArray(int* arr, int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
    }
}

// Конструктор копирования
myArray::myArray(const myArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Оператор присваивания
myArray& myArray::operator=(const myArray& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Деструктор
myArray::~myArray() {
    delete[] data;
}

// Установка значения
void myArray::setValue(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

// Перегрузка оператора + (создание нового массива)
myArray myArray::operator+(int value) const {
    myArray result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + value;
    }
    return result;
}

// Перегрузка оператора - (создание нового массива)
myArray myArray::operator-(int value) const {
    myArray result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] - value;
    }
    return result;
}

// Перегрузка оператора += (изменение текущего массива)
myArray& myArray::operator+=(int value) {
    for (int i = 0; i < size; i++) {
        data[i] += value;
    }
    return *this;
}

// Перегрузка оператора -= (изменение текущего массива)
myArray& myArray::operator-=(int value) {
    for (int i = 0; i < size; i++) {
        data[i] -= value;
    }
    return *this;
}

// Вывод массива
void myArray::print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ========== Реализация статических методов ArrayUtils ==========

bool ArrayUtils::getPalindromeFromNumber(int number, string& result) {
    int digitCount[10] = {0};
    string numStr = to_string(number);

    for (char c : numStr) {
        digitCount[c - '0']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount > 1) {
        result = "Невозможно составить палиндром";
        return false;
    }

    string leftHalf = "";
    char middleChar = '\0';

    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > 0) {
            leftHalf.append(digitCount[i] / 2, '0' + i);
            if (digitCount[i] % 2 != 0) {
                middleChar = '0' + i;
            }
        }
    }

    string rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());

    if (middleChar != '\0') {
        result = leftHalf + middleChar + rightHalf;
    } else {
        result = leftHalf + rightHalf;
    }

    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
        if (!result.empty() && result[result.length() - 1] == '0') {
            result.pop_back();
        }
    }

    return true;
}

bool ArrayUtils::sortArray(int arr[], int size, int sortType) {
    switch(sortType) {
        case 1:
            insertionSort(arr, size);
            return true;
        case 2:
            selectionSort(arr, size);
            return true;
        case 3:
            bubbleSort(arr, size);
            return true;
        default:
            return false;
    }
}

void ArrayUtils::insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void ArrayUtils::selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void ArrayUtils::bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int ArrayUtils::binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

bool ArrayUtils::findRectangleInMatrix(int matrix[5][5], int num1, int num2, int num3, int num4) {
    vector<pair<int, int>> positions1, positions2, positions3, positions4;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == num1) positions1.push_back({i, j});
            if (matrix[i][j] == num2) positions2.push_back({i, j});
            if (matrix[i][j] == num3) positions3.push_back({i, j});
            if (matrix[i][j] == num4) positions4.push_back({i, j});
        }
    }

    for (auto& p1 : positions1) {
        for (auto& p2 : positions2) {
            for (auto& p3 : positions3) {
                for (auto& p4 : positions4) {
                    vector<pair<int, int>> points = {p1, p2, p3, p4};

                    sort(points.begin(), points.end());
                    points.erase(unique(points.begin(), points.end()), points.end());

                    if (points.size() != 4) continue;

                    sort(points.begin(), points.end());

                    set<int> x_coords, y_coords;
                    for (auto& p : points) {
                        x_coords.insert(p.first);
                        y_coords.insert(p.second);
                    }

                    if (x_coords.size() == 2 && y_coords.size() == 2) {
                        vector<int> xs(x_coords.begin(), x_coords.end());
                        vector<int> ys(y_coords.begin(), y_coords.end());

                        bool hasAllPoints = true;
                        for (int x : xs) {
                            for (int y : ys) {
                                bool found = false;
                                for (auto& p : points) {
                                    if (p.first == x && p.second == y) {
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    hasAllPoints = false;
                                    break;
                                }
                            }
                        }

                        if (hasAllPoints) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

vector<pair<int, int>> ArrayUtils::findSaddlePoints(int** matrix, int size) {
    vector<pair<int, int>> saddlePoints;

    for (int i = 0; i < size; i++) {
        int minInRow = INT_MAX;
        vector<int> minCols;

        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                minCols.clear();
                minCols.push_back(j);
            } else if (matrix[i][j] == minInRow) {
                minCols.push_back(j);
            }
        }

        for (int col : minCols) {
            bool isMaxInCol = true;

            for (int row = 0; row < size; row++) {
                if (matrix[row][col] > matrix[i][col]) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMaxInCol) {
                saddlePoints.push_back({i, col});
            }
        }
    }

    return saddlePoints;
}