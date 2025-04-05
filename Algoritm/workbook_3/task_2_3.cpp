#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // снизу вверх
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // сверху вниз
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1; // индекс левого потомка
            int right = 2 * index + 2; // индекс правого потомка
            int largest = index;
            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Конструктор по умолчанию — создаёт пустую кучуA
    MaxHeap() {
    }

    // Конструктор, создающий кучу из массива
    MaxHeap(const vector<int> &arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int get_max() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void remove_max() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    void print_heap() const {
        cout << "Heap: ";
        for (int val: heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Creating heap from array: [3, 10, 5, 6, 2, 1]" << endl;
    vector<int> data = {3, 10, 5, 6, 2, 1};
    MaxHeap heap1(data);
    heap1.print_heap();
    cout << "Current max: " << heap1.get_max() << endl;
    cout << "Removing max" << endl;
    heap1.remove_max();
    heap1.print_heap();
    cout << "Inserting 15 into the heap" << endl;
    heap1.insert(15);
    heap1.print_heap();
    cout << "New max: " << heap1.get_max() << endl;
    cout << "\nCreating empty heap and inserting elements: 7, 8, 9" << endl;
    MaxHeap heap2;
    heap2.insert(7);
    heap2.insert(8);
    heap2.insert(9);
    heap2.print_heap();
    cout << "Max of new heap: " << heap2.get_max() << endl;
    cout << "\nInserting multiple values: 20, 1, 30, 4" << endl;
    heap2.insert(20);
    heap2.insert(1);
    heap2.insert(30);
    heap2.insert(4);
    heap2.print_heap();
    cout << "Max after insertions: " << heap2.get_max() << endl;
    return 0;
}
