#include <iostream>
#include <Windows.h>

void createArray(int*& arr, int size) 
{
    arr = new int[size];
}

void fillArray(int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 100;
    }
}

void printArray(int* arr, int size) 
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void freeMemory(int*& arr) 
{
    delete[] arr;
    arr = nullptr;
}

void addEnd(int*& arr, int& size, int newValue) 
{
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue;

    delete[] arr;
    arr = newArr;
    size = size + 1;
}

void insertIndex(int*& arr, int& size, int index, int newValue) 
{
    int* newArr = new int[size + 1];

    for (int i = 0; i < index; i++) 
    {
        newArr[i] = arr[i];
    }
    newArr[index] = newValue;

    for (int i = index; i < size; i++) 
    {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size = size + 1;
}

void removeIndex(int*& arr, int& size, int index) 
{
    int* newArr = new int[size - 1];

    for (int i = 0; i < index; i++) 
    {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) 
    {
        newArr[i - 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size = size - 1;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));

    int size = 5;
    int* ptr = nullptr;

    createArray(ptr, size);
    fillArray(ptr, size);

    std::cout << "Старт: ";
    printArray(ptr, size);

    std::cout << "+ В конец число 99: ";
    addEnd(ptr, size, 99);
    printArray(ptr, size);

    std::cout << "+ На позицию 2 число 55: ";
    insertIndex(ptr, size, 2, 55);
    printArray(ptr, size);

    std::cout << "Удаляем элемент: ";
    removeIndex(ptr, size, 4);
    printArray(ptr, size);

    freeMemory(ptr);

    return 0;
}
