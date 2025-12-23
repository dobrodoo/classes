//#include <iostream>
//#include "queue.h"
#include <windows.h>
//
//using namespace std;
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//
//    ArrayQueue q1(3);
//
////    for (int i = 1; i <= 5; i++) {
////        q1.enqueue(i * 10);
////    }
//    q1.enqueue(1);
//    q1.enqueue(2);
//    cout << q1.dequeue() << "\n";
//    q1.enqueue(3);
//    q1.enqueue(4);
//    cout << q1.dequeue() << '\n';
//    q1.enqueue(5);
//    cout << q1.dequeue() << '\n';
//    cout << q1.dequeue() << '\n';
//    cout << q1.dequeue() << '\n';
//
//    return 0;
//}
//    int* arr1 = q1.toArray();
//    for (int i = 0; i < q1.getCount(); i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//    delete[] arr1;
//
//    while (!q1.isEmpty()) {
//        cout << q1.dequeue() << " ";
//    }
//    cout << endl;
//
//    ArrayQueue q2(10);
//
//    int values[] = {64, 34, 25, 12, 22, 11, 90};
//    for (int val : values) {
//        q2.enqueue(val);
//    }
//
//    int* arr2 = q2.toArray();
//    for (int i = 0; i < q2.getCount(); i++) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//    delete[] arr2;
//
//    sortQueue(q2);
//
//    arr2 = q2.toArray();
//    for (int i = 0; i < q2.getCount(); i++) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//    delete[] arr2;
//
//    ArrayQueue q3(10);
//
//    int values2[] = {5, 3, 8, 1, 2, 7, 4};
//    for (int val : values2) {
//        q3.enqueue(val);
//    }
//
//    cout << "Очередь: ";
//    int* arr3 = q3.toArray();
//    for (int i = 0; i < q3.getCount(); i++) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;
//    delete[] arr3;
//
//    int testValues[] = {3, 6, 1, 10};
//    for (int val : testValues) {
//        if (binarySearchInQueue(q3, val)) {
//            cout << "Элемент " << val << " найден" << endl;
//        } else {
//            cout << "Элемент " << val << " не найден" << endl;
//        }
//    }
//    ArrayQueue q4(3);
//    try {
//        q4.dequeue();
//    } catch (ArrayQueue::EmptyQueueException) {
//        cout << "Исключение: пустая очередь" << endl;
//    }
//
//    try {
//        for (int i = 0; i < 4; i++) {
//            q4.enqueue(i);
//        }
//    } catch (ArrayQueue::FullQueueException) {
//        cout << "Исключение: полная очередь" << endl;
//    }
//
//    return 0;
//}
//
//
#include "myArray.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Вспомогательные функции для вывода
void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix5x5(int matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void task1() {
    cout << "\n Задача 1: Палиндром из числа " << endl;

    int number;
    cout << "Введите натуральное число: ";
    cin >> number;

    string result;
    if (ArrayUtils::getPalindromeFromNumber(number, result)) {
        cout << "Палиндром: " << result << endl;
    } else {
        cout << result << endl;
    }
}

void task2() {
    cout << "\n Задача 2: Сортировка массива " << endl;

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
    printArray(arr, size);

    bool success = ArrayUtils::sortArray(arr, size, sortType);
    if (!success) {
        cout << "Неверный тип сортировки!" << endl;
        delete[] arr;
        return;
    }

    cout << "Отсортированный массив: ";
    printArray(arr, size);

    delete[] arr;
}

void task3() {
    cout << "\n Задача 3: Бинарный поиск " << endl;

    int size;
    cout << "Введите размерность массива: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Введите элементы массива (в отсортированном виде!):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Массив: ";
    printArray(arr, size);

    int key;
    cout << "Введите искомый элемент: ";
    cin >> key;

    int index = ArrayUtils::binarySearch(arr, size, key);

    if (index != -1) {
        cout << "Элемент найден на позиции: " << index << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }

    delete[] arr;
}

void task4() {
    cout << "\n Задача 4: Прямоугольник в матрице 5x5 " << endl;

    ifstream inFile("in4.txt");
    ofstream outFile("out4.txt");

    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла in4.txt" << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла out4.txt" << endl;
        inFile.close();
        return;
    }

    int matrix[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            inFile >> matrix[i][j];
        }
    }

    int num1, num2, num3, num4;
    inFile >> num1 >> num2 >> num3 >> num4;

    inFile.close();

    outFile << "Матрица:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }

    outFile << "\nВершины прямоугольника: "
            << num1 << " " << num2 << " " << num3 << " " << num4 << endl;

    bool found = ArrayUtils::findRectangleInMatrix(matrix, num1, num2, num3, num4);

    if (found) {
        outFile << "Прямоугольник с вершинами из заданных чисел существует!" << endl;
        cout << "Прямоугольник найден. Результат в файле out4.txt" << endl;
    } else {
        outFile << "Прямоугольник с вершинами из заданных чисел не существует." << endl;
        cout << "Прямоугольник не найден. Результат в файле out4.txt" << endl;
    }

    outFile.close();
}

void task5() {
    cout << "\n Задача 5: Седловые точки" << endl;

    ifstream inFile("in5.txt");
    ofstream outFile("out5.txt");

    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла in5.txt" << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла out5.txt" << endl;
        inFile.close();
        return;
    }

    int size;
    inFile >> size;

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inFile >> matrix[i][j];
        }
    }

    inFile.close();

    outFile << "Матрица " << size << "x" << size << ":" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            outFile << matrix[i][j] << "\t";
        }
        outFile << endl;
    }
    outFile << endl;

    vector<pair<int, int>> saddlePoints = ArrayUtils::findSaddlePoints(matrix, size);

    if (saddlePoints.empty()) {
        outFile << "Седловых точек не найдено." << endl;
        cout << "Седловых точек не найдено. Результат в файле out6.txt" << endl;
    } else {
        outFile << "Найдены седловые точки (" << saddlePoints.size() << "):" << endl;
        for (auto& point : saddlePoints) {
            outFile << "Строка " << point.first + 1
                    << ", Столбец " << point.second + 1
                    << ", Значение: " << matrix[point.first][point.second] << endl;
        }
        cout << "Найдено " << saddlePoints.size() << " седловых точек. Результат в файле out6.txt" << endl;
    }

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    outFile.close();
}

void task6() {
    cout << "\n Задача 6: Перегрузка операторов + и - " << endl;

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    myArray arr(size);

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        arr.setValue(i, value);
    }

    cout << "\nИсходный массив: ";
    arr.print();

    int value;
    cout << "\nВведите число для прибавления ко всем элементам: ";
    cin >> value;

    myArray arr_plus = arr + value;
    cout << "Массив после прибавления " << value << ": ";
    arr_plus.print();

    cout << "\nВведите число для вычитания из всех элементов: ";
    cin >> value;

    myArray arr_minus = arr - value;
    cout << "Массив после вычитания " << value << ": ";
    arr_minus.print();

    cout << "\nДемонстрация операторов += и -= на копии исходного массива:" << endl;
    myArray arr_copy = arr;

    cout << "Введите число для оператора +=: ";
    cin >> value;
    arr_copy += value;
    cout << "Массив после arr += " << value << ": ";
    arr_copy.print();

    cout << "Введите число для оператора -=: ";
    cin >> value;
    arr_copy -= value;
    cout << "Массив после arr -= " << value << ": ";
    arr_copy.print();
}

int main() {
    int choice;
    SetConsoleOutputCP(CP_UTF8);

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
            case 6:
                task6();
                break;
            case 0:
                break;
            default:
                cout << "Неверный выбор" << endl;
        }
    } while (choice != 0);

    return 0;
}