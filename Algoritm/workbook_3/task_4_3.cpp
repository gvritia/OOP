// Реализовать очередь с приоритетом без использования кучи, используя связный список.

#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node *next;
};

class PriorityQueue {
private:
    Node *head;

public:
    PriorityQueue() : head(nullptr) {
    }
    void insert(int data, int priority) {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->priority = priority;
        new_node->next = nullptr;
        if (head == nullptr || priority < head->priority) {
            new_node->next = head;
            head = new_node;
        } else {
            Node *current = head;
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void extract_minimum() {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Extracted: " << temp->data << " (priority: " << temp->priority << ")\n";
        head = head->next;
        delete temp;
    }

    void peek() {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Top element: " << head->data << " (priority: " << head->priority << ")\n";
        }
    }

    void print_queue() {
        Node *current = head;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << "[" << current->data << " (priority:" << current->priority << ")] -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
    ~PriorityQueue() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    cout << "\n--- Test pq ---\n";
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(5, 1);
    pq.insert(20, 3);
    pq.insert(15, 2);
    pq.print_queue();
    pq.peek();
    pq.extract_minimum();
    pq.print_queue();
    pq.extract_minimum();
    pq.print_queue();
    cout << "\n--- Test pq1 ---\n";
    PriorityQueue pq1;
    pq1.insert(30, 5);
    pq1.insert(25, 2);
    pq1.insert(40, 4);
    pq1.insert(10, 1);
    pq1.print_queue();
    pq1.peek();
    pq1.extract_minimum();
    pq1.print_queue();
    cout << "\n--- Test pq2 ---\n";
    PriorityQueue pq2;
    pq2.insert(100, 3);
    pq2.insert(90, 3);
    pq2.insert(80, 3);
    pq2.insert(70, 2);
    pq2.insert(60, 1);
    pq2.print_queue();
    pq2.extract_minimum();
    pq2.print_queue();
    pq2.extract_minimum();
    pq2.print_queue();
    return 0;
}

