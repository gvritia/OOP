#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(); // создаём новый узел
    Node* last = *head_ref; // указ. на последний узел
    new_node->data = new_data; // Заполняеи данные нового узла
    new_node->next = NULL; // След. узел будет Null
    if (*head_ref == NULL) {
        new_node->prev = nullptr; // предыдущий узел будет NULL
        *head_ref = new_node; // новый узел становистя головой списка
        return;
    }
    while (last->next != NULL) { // находим последний узел
        last = last->next;
    }
    last->next = new_node; // устанавливем ссылку на новый узел
    new_node->prev = last; // устанавливем ссылку на предыдущий узел
}

void display(Node* node) {
    while (node != NULL) {
        cout << node->data << " <-> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// int main() {
//     Node* head = NULL;
//     append(&head, 1);
//     append(&head, 2);
//     append(&head, 3);
//     cout << "Содержимое двусязного списка" << endl;
//     display(head);
//     return 0;
// }