#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;

void heapify(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void insert(int valuse) {
    heap.push_back(valuse);
    heapify(heap.size() - 1);
}

void print_heap() {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Тест 1
    cout << "unsorted 20, 10, 15, 5, 30" << endl;
    insert(20);
    insert(10);
    insert(15);
    insert(5);
    insert(30);
    cout << "sorted array: ";
    print_heap();
    heap.clear();
    // Тест 2
    cout << "\nunsorted: 5, 10, 15, 20, 25" << endl;
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    cout << "sorted: ";
    print_heap();
    heap.clear();
    // Тест 3
    cout << "\nunsorted: 3, 1, 4, 1, 5, 9" << endl;
    insert(3);
    insert(1);
    insert(4);
    insert(1);
    insert(5);
    insert(9);
    cout << "sorted: ";
    print_heap();

    return 0;
}
