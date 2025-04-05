#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void merge_ropes(vector<int>& ropes) {
    // Создаем минимальную кучу (по возрастанию)
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int length : ropes) {
        heap.push(length);
    }
    int count = 0;
    cout << "Merging ropes in this order:\n";
    while (heap.size() > 1) {
        int first = heap.top();
        heap.pop();
        int second = heap.top();
        heap.pop();
        int k = first + second;
        count += k;
        cout << "Merge " << first << " and " << second << " => cost: " << k << endl;
        heap.push(k);
    }
    cout << "Total cost: " << count << endl;
}

int main() {
    // Проверка
    vector<int> ropes1 = {4, 3, 2, 6};
    vector<int> ropes2 = {1, 2, 3, 4, 5};
    vector<int> ropes3 = {5, 5, 5, 5};
    vector<int> ropes4 = {10};
    vector<int> ropes5 = {8, 4, 6, 12};
    vector<int> ropes6 = {20, 4, 8, 2};
    vector<int> ropes7 = {1, 100, 200, 300};
    vector<int> ropes8 = {1, 2};
    vector<int> ropes9 = {5, 7, 9, 3, 2, 1};
    cout << "\n--- Test 1 ---\n";
    merge_ropes(ropes1);
    cout << "\n--- Test 2 ---\n";
    merge_ropes(ropes2);
    cout << "\n--- Test 3 ---\n";
    merge_ropes(ropes3);
    cout << "\n--- Test 4 ---\n";
    merge_ropes(ropes4);
    cout << "\n--- Test 5 ---\n";
    merge_ropes(ropes5);
    cout << "\n--- Test 6 ---\n";
    merge_ropes(ropes6);
    cout << "\n--- Test 7 ---\n";
    merge_ropes(ropes7);
    cout << "\n--- Test 8 ---\n";
    merge_ropes(ropes8);
    cout << "\n--- Test 9 ---\n";
    merge_ropes(ropes9);
    return 0;
}
