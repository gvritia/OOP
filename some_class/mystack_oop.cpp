#include <iostream>
#include <stack>

using namespace std;

class MyStack {
public:
    stack<int> my_stack;

    void push(int n) {
        my_stack.push(n);
    }

    void pop() {
        cout << my_stack.top() << endl;
        my_stack.pop();
    }

    void back() {
        cout << my_stack.top() << endl;
    }

    void size() {
        cout << my_stack.size() << endl;
    }

    void clear() {
        while (!my_stack.empty()) {
            my_stack.pop();
        }
    }
};

// int main() {
//     MyStack stack;
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     stack.push(40);
//     stack.push(50);
//     stack.back();
//     stack.size();
//     stack.pop();
//     stack.size();
//     stack.clear();
//     stack.size();
//     return 0;
// }