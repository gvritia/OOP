#include <iostream>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* create_node(int value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->right = nullptr;
    new_node->left = nullptr;
    return new_node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return create_node(value);
    }
    else if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void find_element(Node* root, int value) {
    if (root->data == value) {
        cout << "Element found " << root->data <<  endl;
    }
    else if (value < root->data) {
        root = root->left;
        cout << "go to the left branch: "<< root->data << endl;
        find_element(root, value);
    }
    else if (value > root->data) {
        root = root->right;
        cout << "go to the left branch: "<< root->data << endl;
        find_element(root, value);
    }
    else {
        cout << "Element not found" << endl;
    }
}

int main() {
    srand(time(nullptr));
    Node* root = nullptr;
    int n;
    cout << "Enter the number of elements in tree: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        root = insert(root, rand() % 100);
    }
    return 0;
}