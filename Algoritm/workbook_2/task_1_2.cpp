#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int balance;
};

Node* createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->balance = 0;
    return node;
}

Node* insert(Node *root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

int height(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// Функция для вычисления баланса узла
void calculateBalance(Node *root) {
    if (root == nullptr) {
        return;
    }
    root->balance = height(root->right) - height(root->left); // Разница высот
    calculateBalance(root->left);
    calculateBalance(root->right);
}

// Симметричный обход
void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << "(" << root->balance << ") ";
        inOrder(root->right);
    }
}

void deleteTree(Node *root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 35);
    calculateBalance(root);
    cout << "Sorted elems with balance: ";
    inOrder(root);
    deleteTree(root);
    return 0;
}