#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void push_back(Node *&head, int new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head; // new с началом
    head = head->prev;
    head->next = new_node; // конец с new
    new_node->prev = head; // new с бывшим концом
    head = head->next; // возвращаемся в начало
    head = head->next;
    head->prev = new_node; // начало с new
}

void Cycle_Finding(Node* head) {
    Node *turtle = head, *rabbit = head->next;
    while (rabbit != nullptr and rabbit->next != nullptr and turtle != rabbit) {
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    if (rabbit != turtle) {
        cout << "No loop\n";
    }
    else {
        cout << "Loop detected!\n" << "Cell " << turtle->data << " references cell " << turtle->next->data <<
                "\nDone!";
    }
}

void delete_node(Node *&head, int del_value) {
    Node* current = head;
    while (current->data != del_value) {
        current = current->next;
        if (current == head)
            return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (current == head) {
        head = current->next;
    }
    delete current;
}

void createCircularList(Node *&head, int x) {
    head = new Node();
    head->data = 1;
    head->next = head;
    head->prev = head;
    Node* tail = head;
    for (int i = 2; i <= x; ++i) {
        Node* newNode = new Node();
        newNode->data = i;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;       \
    }
}
void show(Node* head, int x) {
    int i = 0;
    while (i < x + 5) {
        cout << head->data << " <-> ";
        head = head->next;
        i++;
    }
    cout << "...\n";
}



int main() {
    int n = 10;
    Node* head = nullptr;
    createCircularList(head, n);
    cout<<"Nodes in the Circular List: ";
    show(head, n);
    cout<<"New Nodes in the Circular List: ";
    push_back(head, 11);
    push_back(head, 12);
    push_back(head, 13);
    show(head, n);
    cout<<"Deleting Nodes in the Circular List: ";
    delete_node(head, 5);
    show(head, n);
    Cycle_Finding(head);
    return 0;
}