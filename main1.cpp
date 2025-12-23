#include "myArray.h"
#include <iostream>
#include <string>

using namespace std;

void task1() {
    cout << "\n=== Задача 1: Палиндром из числа ===" << endl;

    int number;
    cout << "Введите натуральное число: ";
    cin >> number;

    string result;
    if (myArray::getPalindromeFromNumber(number, result)) {
        cout << "Палиндром: " << result << endl;
    } else {
        cout << result << endl;
    }
}

void task2() {
    cout << "\n=== Задача 2: Сортировка массива ===" << endl;

    int size;
    cout << "Введите размерность массива: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nВыберите тип сортировки:" << endl;
    cout << "1 - Сортировка вставками" << endl;
    cout << "2 - Сортировка выбором" << endl;
    cout << "3 - Сортировка обменом (пузырьковая)" << endl;
    cout << "Ваш выбор: ";

    int sortType;
    cin >> sortType;

    cout << "\nИсходный массив: ";
    myArray::printArray(arr, size);

    myArray::sortArray(arr, size, sortType);

    cout << "Отсортированный массив: ";
    myArray::printArray(arr, size);

    delete[] arr;
}

void task3() {
    cout << "\n=== Задача 3: Бинарный поиск ===" << endl;

    int size;
    cout << "Введите размерность массива: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Введите элементы массива (в отсортированном виде!):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Введите искомый элемент: ";
    cin >> key;

    int index = myArray::binarySearch(arr, size, key);

    if (index != -1) {
        cout << "Элемент найден на позиции: " << index << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }

    delete[] arr;
}

void task4() {
    cout << "\n=== Задача 4: Прямоугольник в матрице 5x5 ===" << endl;

    int matrix[5][5];
    cout << "Введите элементы матрицы 5x5:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
        }
    }

    int num1, num2, num3, num4;
    cout << "Введите четыре числа для вершин прямоугольника:" << endl;
    cout << "Число 1: ";
    cin >> num1;
    cout << "Число 2: ";
    cin >> num2;
    cout << "Число 3: ";
    cin >> num3;
    cout << "Число 4: ";
    cin >> num4;

    cout << "\nМатрица:" << endl;
    myArray::printMatrix5x5(matrix);

    if (myArray::findRectangleInMatrix(matrix, num1, num2, num3, num4)) {
        cout << "Прямоугольник с вершинами из заданных чисел существует!" << endl;
    } else {
        cout << "Прямоугольник с вершинами из заданных чисел не существует." << endl;
    }
}

void task5() {
    cout << "\n=== Задача 5: Седловые точки ===" << endl;

    int size;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> size;

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nМатрица:" << endl;
    myArray::printMatrix(matrix, size);

    myArray::findSaddlePoints(matrix, size);

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int choice;

    do {
        cout << "Выберите задачу: ";
        cin >> choice;

        switch(choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}