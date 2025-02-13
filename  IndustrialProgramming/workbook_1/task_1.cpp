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


int main() {
    const int n = 10;
    static struct Node array[n];
    struct Node *turtle, *rabbit;
    cout << "array elements\n";
    for (int i = 0; i < n - 1; i++) {
        array[i].data = i + 1;
        //Эта строчка связывает текущий узел (array[i]) со следующим узлом (array[i+1]).
        //То есть, поле next текущего узла теперь указывает на следующий узел в массиве.
        array[i].next = &array[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << array[i].data << " -> ";
    }
    cout << endl;
    array[n - 1].data = n - 1;
    // Создаём цикл/проскок
    array[n - 5].next = &array[3];
    turtle = &array[0];
    rabbit = &array[1];
    while (rabbit != nullptr and rabbit->next != nullptr and turtle != rabbit) { // Floyd's Cycle-Finding Algorithm
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    if (rabbit != turtle) {
        cout << "No loop\n";
    } else {
        cout << "Loop detected!" << endl;
        cout << "Cell " << turtle->data << " references cell " << turtle->next->data << endl;
        cout << "Done!";
    }
    return 0;
}
