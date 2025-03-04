#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int balance;
};

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

Node* turnright(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    root->balance = height(root->right) - height(root->left);
    new_root->balance = height(new_root->right) - height(new_root->left);
    return new_root;
}

Node* turnleft(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    root->balance = height(root->right) - height(root->left);
    new_root->balance = height(new_root->right) - height(new_root->left);
    return new_root;
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

Node* createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->balance = 0;
    return node;
}

Node* balance(Node *root) {
    if (root == nullptr){
        return root;
    }
    root->balance = height(root->right) - height(root->left); // Только для текущего узла
    if (root->balance == 2) {
        if (root->right->balance < 0) {
            root->right = turnright(root->right);
        }
        return turnleft(root);
    }
    else if (root->balance == -2) {
        if (root->left->balance > 0) {
            root->left = turnleft(root->left);
        }
        return turnright(root);
    }
    root->balance = height(root->right) - height(root->left);
    return root;
}

Node* balanced_insert(Node *root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = balanced_insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = balanced_insert(root->right, key);
    }
    return balance(root);
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

int main() {
    Node *root = nullptr;
    Node *root1 = nullptr;

    // Несбалансированное дерево
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 35);
    root = insert(root, 60);
    calculateBalance(root);
    cout << "Unbalanced tree: ";
    inOrder(root);
    deleteTree(root);

    // Сбалансированное АВЛ-дерево
    root1 = balanced_insert(root1, 30);
    root1 = balanced_insert(root1, 20);
    root1 = balanced_insert(root1, 40);
    root1 = balanced_insert(root1, 50);
    root1 = balanced_insert(root1, 35);
    root1 = balanced_insert(root1, 60);

    cout << "\nBalanced tree: ";
    inOrder(root1);
    deleteTree(root1);

    return 0;
}
