// Реализуйте функцию, которая находит количество слов в префиксном дереве, начинающихся с заданного префикса.

#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode *children[26];
    bool isEndOfWorld;

    TrieNode() : isEndOfWorld(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

TrieNode *root = new TrieNode();

void insert(const string &word) {
    TrieNode *node = root;
    for (char ch: word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWorld = true;
}

bool search(const string &word) {
    TrieNode *node = root;
    for (char ch: word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWorld;
}

int count_words_recursive(TrieNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int count = 0;
    if (node->isEndOfWorld) {
        count++;
    }
    for (int i = 0; i < 26; i++) {
        count += count_words_recursive(node->children[i]);
    }
    return count;
}

int count_words(const string &prefix) {
    TrieNode *node = root;
    for (char ch: prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return 0;
        }
        node = node->children[index];
    }
    return count_words_recursive(node);
}

int main() {
    insert("hello");
    insert("world");
    insert("heaven");
    insert("heavy");
    insert("hero");
    insert("heat");
    insert("heap");
    insert("her");
    insert("hex");
    insert("hint");

    // Тест 1: Префикс "he" (должно быть 7 слов)
    cout << "Test 1: Prefix 'he'" << endl;
    cout << "Expected: 7, Actual: " << count_words("he") << endl << endl;

    // Тест 2: Префикс "hea" (должно быть 4 слова)
    cout << "Test 2: Prefix 'hea'" << endl;
    cout << "Expected: 4, Actual: " << count_words("hea") << endl << endl;

    // Тест 3: Префикс "her" (должно быть 2 слова)
    cout << "Test 3: Prefix 'her'" << endl;
    cout << "Expected: 2, Actual: " << count_words("her") << endl << endl;

    // Тест 4: Префикс "hi" (должно быть 1 слово)
    cout << "Test 4: Prefix 'hi'" << endl;
    cout << "Expected: 1, Actual: " << count_words("hi") << endl << endl;

    // Тест 5: Префикс "wor" (должно быть 1 слово)
    cout << "Test 5: Prefix 'wor'" << endl;
    cout << "Expected: 1, Actual: " << count_words("wor") << endl << endl;

    // Тест 6: Префикс "x" (нет таких слов, должно быть 0)
    cout << "Test 6: Prefix 'x'" << endl;
    cout << "Expected: 0, Actual: " << count_words("x") << endl << endl;

    // Тест 7: Пустой префикс (должно быть 10 слов, все слова в дереве)
    cout << "Test 7: Empty prefix ''" << endl;
    cout << "Expected: 10, Actual: " << count_words("") << endl << endl;

    // Тест 8: Префикс "hello" (должно быть 1 слово)
    cout << "Test 8: Prefix 'hello'" << endl;
    cout << "Expected: 1, Actual: " << count_words("hello") << endl << endl;

    return 0;
}