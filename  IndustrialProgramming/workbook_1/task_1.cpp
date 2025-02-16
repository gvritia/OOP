// алгоритм "Черепахи и Зайца" (Floyd's Cycle-Finding Algorithm)
// Представьте, что в списке некоторые узлы случайно «ссылаются» не только на следующий, но и пересекаются (указывают на узлы из середины списка).
// Нужно проверить, что таких «лишних» ссылок в структуре нет, то есть каждый узел ссылается ровно на один следующий элемент (или на NULL).
// Как обнаружить «проскок» или «перескок», не используя хеш-таблицу или другие явные структуры хранения посещённых узлов?


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void show(Node *head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
}

void push_back(Node *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i].data = i + 1;
        //Эта строчка связывает текущий узел (array[i]) со следующим узлом (array[i+1]).
        //То есть, поле next текущего узла теперь указывает на следующий узел в массиве.
        if (i < n - 1) {
            array[i].next = &array[i + 1];
        }
        else {
            array[i].next = nullptr;
        }
    }
}

int main() {
    const int n = 10;
    static struct Node array[n];
    struct Node *turtle, *rabbit;
    cout << "array elements\n";
    push_back(array, n);
    show(array);
    // Создаём цикл/проскок
    array[n - 5].next = &array[3];
    turtle = &array[0];
    rabbit = &array[1];
    while (rabbit != nullptr and rabbit->next != nullptr and turtle != rabbit) {
        // Floyd's Cycle-Finding Algorithm
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    if (rabbit != turtle) {
        cout << "\nNo loop\n";
    }
    else {
        cout << "\nLoop detected!\n" << "Cell " << turtle->data << " references cell " << turtle->next->data <<
                "\nDone!";
    }
    return 0;
}
