#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;
    char color;
};

Node* createNode(int key, char color, Node* parent) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = parent;
    node->color = color;
    return node;
}

Node* insert(Node* root, int key, char color) {
    if (root == nullptr) {
        return createNode(key, color, nullptr);
    }
    if (key < root->key) {
        root->left = insert(root->left, key, color);
        root->left->parent = root;
    }
    else {
        root->right = insert(root->right, key, color);
        root->right->parent = root;
    }
    return root;
}

// Корень должен быть черным
bool isRootBlack(Node* root) {
    if (root == nullptr or root->color == 'B') {
        return true;
    }
    else {
        return false;
    }
}

// Красные узлы не должны иметь красных потомков
bool no_red(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->color == 'R') {
        if (node->left->color == 'R' or node->right->color == 'R') {
            return false;
        }
    }
    return no_red(node->left) and no_red(node->right);
}

// Одинаковое количество черных узлов в каждом пути от корня до листа
int countBlack(Node* node) {
    if (node == nullptr) {
        return 1;
    }
    int left = countBlack(node->left);
    int right = countBlack(node->right);
    if (left == -1 or right == -1 or left != right) {
        return -1;
    }
    int blackCount = left;
    if (node->color == 'B') {
        blackCount += 1;
    }
    return blackCount;
}

bool isRBTree(Node* root) {
    if (isRootBlack(root) and no_red(root) and countBlack(root) != -1) {
        return true;
    }
    else {
        return false;
    }
}

void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << "(" << root->color << ") ";
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
    Node* root = nullptr;
    root = insert(root, 10, 'B');
    root = insert(root, 5, 'R');
    root = insert(root, 20, 'R');
    root = insert(root, 3, 'B');
    root = insert(root, 7, 'B');
    root = insert(root, 15, 'B');
    root = insert(root, 25, 'B');
    // root = insert(root, 30, 'B');
    cout << "Tree: ";
    inOrder(root);
    cout << endl;

    if (isRBTree(root))
        cout << "Tree is RB Tree\n";
    else
        cout << "Tree is NOT RB Tree\n";
    deleteTree(root);
    return 0;
}