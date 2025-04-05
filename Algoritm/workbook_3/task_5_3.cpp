#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Если правый потомок больше "наибольшего" на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Если наибольший элемент — не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Рекурсивно восстанавливаем кучу
    }
}

// пирамидальная сортировка
void heapSort(vector<int> &arr) {
    int n = arr.size();
    // Построение кучи (перестройка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (максимум) в конец
        swap(arr[0], arr[i]);
        // Восстанавливаем кучу
        heapify(arr, i, 0);
    }
}

void print_arr(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {45, 28, 54, 43, 70, 60, 65};
    vector<int> arr2 = {5, 1, 8, 3, 2};
    vector<int> arr3 = {100, 90, 80, 70, 60, 50};
    vector<int> arr4 = {1, 2, 3, 4, 5};
    vector<int> arr5 = {10};
    // Тест 1
    cout << "\n-- Test 1 --\nOriginal: ";
    print_arr(arr1);
    heapSort(arr1);
    cout << "Sorted: ";
    print_arr(arr1);
    // Тест 2
    cout << "\n-- Test 2 --\nOriginal: ";
    print_arr(arr2);
    heapSort(arr2);
    cout << "Sorted: ";
    print_arr(arr2);
    // Тест 3
    cout << "\n-- Test 3 --\nOriginal: ";
    print_arr(arr3);
    heapSort(arr3);
    cout << "Sorted: ";
    print_arr(arr3);
    // Тест 4
    cout << "\n-- Test 4 --\nOriginal: ";
    print_arr(arr4);
    heapSort(arr4);
    cout << "Sorted: ";
    print_arr(arr4);
    // Тест 5
    cout << "\n-- Test 5 --\nOriginal: ";
    print_arr(arr5);
    heapSort(arr5);
    cout << "Sorted: ";
    print_arr(arr5);
    return 0;
}
