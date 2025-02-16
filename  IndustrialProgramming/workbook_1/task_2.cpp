#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void show(Node *head) {
    while(head != nullptr) {
        cout<<head->data<<" -> ";
        head = head->next;
    }
}
void push_back(Node *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i].data = i + 1;
        if (i < n - 1) {
            array[i].next = &array[i + 1];
        }
        else {
            array[i].next = nullptr;
        }
    }
}

int main() {
    const int n = 30;
    int x, i1 = 0, i2 = 0;
    static struct Node array[n];
    // Node *less_x = new Node;
    // Node *greater_x = new Node;
    cout<<"Enter value of x: ";
    cin>>x;
    push_back(array, n);
    show(array);
    // for (int i = 0; i < n - 1; i++) {
    //     if (array[i].data < x) {
    //         less_x[i1].data = array[i].data;
    //         less_x[i1].next = &less_x[i1 + 1];
    //         i1++;
    //
    //     }
    //     else {
    //         greater_x[i2].data = array[i].data;
    //         greater_x[i2].next = &greater_x[i2 + 1];
    //         i2++;
    //     }
    // }
    // less_x[i1].next = nullptr;
    // greater_x[i2].next = nullptr;
    Node *less_x = nullptr, *greater_x = nullptr;
    Node *less_tail = nullptr, *greater_tail = nullptr;

    for (int i = 0; i < n; i++) {
        if (array[i].data < x) {
            if (less_x == nullptr) {
                less_x = &array[i];
                less_tail = &array[i];
            }
            else {
                less_tail->next = &array[i];
                less_tail = &array[i];
            }
        }
        else {
            if (greater_x == nullptr) {
                greater_x = &array[i];
                greater_tail = &array[i];
            }
            else {
                greater_tail->next = &array[i];
                greater_tail = &array[i];
            }
        }
    }

    if (less_tail != nullptr) {
        less_tail->next = nullptr;
    }
    if (greater_tail != nullptr) {
        greater_tail->next = nullptr;
    }
    cout<<"\nLess x:\n";
    show(less_x);
    cout<<"\nGreater x:\n";
    show(greater_x);
    return 0;
}