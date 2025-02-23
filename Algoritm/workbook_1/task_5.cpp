#include <iostream>
using namespace std;

struct Node {
    int KeyMin;
    int KeyMax;
    Node *left;
    Node *right;
};

Node* build(int l, int r) {
    if (l > r) {
        return nullptr;
    }
    Node* node = new Node;
    node->KeyMin = l;
    node->KeyMax = r;
    node->left = nullptr;
    node->right = nullptr;
    if (l != r) {  // Разделение интервала
        int mid = (l + r) / 2;
        node->left = build(l, mid);
        node->right = build(mid, r);
    }
    return node;
}

void show(Node* root) {
    if (root != nullptr) {
        cout << "[" << root->KeyMin << ", " << root->KeyMax << "] ";
        show(root->left);
        show(root->right);
    }
}

int searchX(Node* root, int x) {
    if (root == nullptr) {
        return 0;
    }
    if (x >= root->KeyMin and x <= root->KeyMax){
        return 1 + searchX(root->left, x) + searchX(root->right, x);
    }
    return searchX(root->left, x) + searchX(root->right, x);
}

int main() {
    int l, r, x;
    cout << "Enter the start and end of the interval: ";
    cin >> l >> r;
    Node* root = build(l, r);
    cout << "\nTree is: ";
    show(root);
    cout << endl;
    cout << "\nEnter point X: ";
    cin >> x;
    cout << "\nNumber of intervals containing " << x << ": " << searchX(root, x) << endl;
    return 0;
}
