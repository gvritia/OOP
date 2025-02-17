// #include <iostream>
//
// using namespace std;
// // Структура узла
// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };
//
// // Функция для создания нового узла
// Node* createNode(int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = nullptr;
//     newNode->prev = nullptr;
//     return newNode;
// }
//
// // Функция для добавления узла в конец кольцевого списка
// void append(Node*& head, int data) {
//     Node* newNode = createNode(data);
//     if (head == nullptr) {
//         head = newNode;
//         head->next = head;
//         head->prev = head;
//     }
//     else {
//         Node* tail = head->prev;
//         tail->next = newNode;
//         newNode->prev = tail;
//         newNode->next = head;
//         head->prev = newNode;
//     }
// }
//
// // Функция для удаления узла по значению
// void remove(Node*& head, int data) {
//     if (head == nullptr) return;
//
//     Node* current = head;
//     do {
//         if (current->data == data) {
//             if (current->next == current) { // Если это единственный узел
//                 delete current;
//                 head = nullptr;
//                 return;
//             }
//             current->prev->next = current->next;
//             current->next->prev = current->prev;
//             if (current == head) {
//                 head = current->next;
//             }
//             delete current;
//             return;
//         }
//         current = current->next;
//     } while (current != head);
// }
//
// // Функция для вывода элементов кольца
// void printList(Node* head) {
//     if (head == nullptr) {
//         cout << "Список пуст." << endl;
//         return;
//     }
//
//     Node* current = head;
//     do {
//         cout << current->data << " ";
//         current = current->next;
//     } while (current != head);
//     cout << endl;
// }
//
// // Функция для проверки, является ли список кольцевым
// bool isCircular(Node* head) {
//     if (head == nullptr) return true;
//
//     Node* current = head;
//     while (current->next != nullptr && current->next != head) {
//         current = current->next;
//     }
//     return current->next == head;
// }
//
// int main() {
//     Node* head = nullptr;
//
//     // Добавление элементов в список
//     append(head, 10);
//     append(head, 20);
//     append(head, 30);
//     append(head, 40);
//
//     // Вывод списка
//     cout << "Список после добавления элементов: ";
//     printList(head);
//
//     // Удаление элемента
//     remove(head, 20);
//     cout << "Список после удаления элемента 20: ";
//     printList(head);
//
//     // Проверка, является ли список кольцевым
//     if (isCircular(head)) {
//         cout << "Список является кольцевым." << endl;
//     } else {
//         cout << "Список не является кольцевым." << endl;
//     }
//
//     // Удаление всех элементов
//     remove(head, 10);
//     remove(head, 30);
//     remove(head, 40);
//
//     // Вывод пустого списка
//     cout << "Список после удаления всех элементов: ";
//     printList(head);
//
//     return 0;
// }

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