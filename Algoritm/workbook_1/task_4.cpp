// Создать двоичное дерево поиска (в узлах хранятся целые положительные числа). Программа должна запрашивать количество элементов дерева, далее значения, хранящиеся в элементах, создаются генератором случайных чисел. Для готового дерева реализовать операции:
// а) добавление нового узла в дерево;
// б) обход дерева (прямой, обратный или симметричный – по выбору) и печать элементов дерева на экран;
// в) вычисление глубины (высоты) дерева;
// г) поиск конкретного элемента в дереве
// д) удаление определенного узла в дереве.

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
    if (root == nullptr) {
        cout << "Element not found" << endl;
    }
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
        cout << "go to the right branch: "<< root->data << endl;
        find_element(root, value);
    }
}

Node* delete_node(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    else if (value < root->data) {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data) {
        root->right = delete_node(root->right, value);
    }
    else{
        if (root->left == nullptr) {
            Node* new_root = root->right;
            delete root;
            return new_root;
        }
        else if (root->right == nullptr) {
            Node* new_root = root->left;
            delete root;
            return new_root;
        }
        Node* new_root = root->left;
        while (new_root->right != nullptr) {
            new_root = new_root->right;
        }
        root->data = new_root->data;
        root->left = delete_node(root->left, new_root->data);
    }
    return root;
}

//прямой обход дерева
void show(Node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        show(root->left);
        show(root->right);
    }
}

int tree_height(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return max(left_height, right_height) + 1;
}

int main() {
    srand(time(nullptr));
    Node* root = nullptr;
    int n, x, x1, x2;
    cout << "Enter the number of elements in tree: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        x = rand() % 100;
        root = insert(root, x);
        cout << x << " ";
    }
    cout << "\nTree is: ";
    show(root);
    cout << endl;
    cout << "Tree height: "<< tree_height(root);
    cout<< "\nEnter the value to find: ";
    cin >> x1;
    find_element(root, x1);
    cout<< "\nEnter the value to be deleted: ";
    cin >> x2;
    root = delete_node(root, x2);
    show(root);
    cout << "\nTree heihgt: "<< tree_height(root);
    return 0;
}