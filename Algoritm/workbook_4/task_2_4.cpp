#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWorld;
    int childCount; // Количество активных потомков

    TrieNode() : isEndOfWorld(false), childCount(0) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

TrieNode* root = new TrieNode();

void insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
            node->childCount++;
        }
        node = node->children[index];
    }
    node->isEndOfWorld = true;
}

bool search(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWorld;
}

int count_words_recursive(TrieNode* node) {
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

int count_words(const string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return 0;
        }
        node = node->children[index];
    }
    return count_words_recursive(node);
}

// Рекурсивная функция для удаления слова из Trie
bool deleteHelper(TrieNode* node, const string& word, int depth = 0) {
    if (node == nullptr) {
        return false;
    }
    // Дошли до конца слова
    if (depth == word.length()) {
        if (!node->isEndOfWorld) {
            return false;
        }
        node->isEndOfWorld = false; // Удаляем метку конца слова
        return (node->childCount == 0); // Можно удалить узел, если нет потомков
    }

    int index = word[depth] - 'a';
    if (node->children[index] == nullptr) {
        return false;
    }

    bool shouldDeleteChild = deleteHelper(node->children[index], word, depth + 1);

    if (shouldDeleteChild) {
        delete node->children[index];
        node->children[index] = nullptr;
        node->childCount--;
        return (node->childCount == 0 && !node->isEndOfWorld);
    }

    return false;
}

void deleteWord(const string& word) {
    deleteHelper(root, word);
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
    // Тест 1: Удаление существующего слова и проверка
    cout << "Test 1: Delete 'hello'" << endl;
    cout << "Before deletion - search('hello'): " << (search("hello") ? "Found" : "Not found") << endl;
    deleteWord("hello");
    cout << "After deletion - search('hello'): " << (search("hello") ? "Found" : "Not found") << endl << endl;

    // Тест 2: Удаление несуществующего слова
    cout << "Test 2: Delete 'nonexistent'" << endl;
    cout << "Before deletion - search('nonexistent'): " << (search("nonexistent") ? "Found" : "Not found") << endl;
    deleteWord("nonexistent");
    cout << "After deletion - search('nonexistent'): " << (search("nonexistent") ? "Found" : "Not found") << endl << endl;

    // Тест 3: Удаление слова, которое является префиксом другого
    cout << "Test 3: Delete 'her' (prefix of 'hero')" << endl;
    cout << "Before deletion - search('her'): " << (search("her") ? "Found" : "Not found") << endl;
    cout << "Before deletion - search('hero'): " << (search("hero") ? "Found" : "Not found") << endl;
    deleteWord("her");
    cout << "After deletion - search('her'): " << (search("her") ? "Found" : "Not found") << endl;
    cout << "After deletion - search('hero'): " << (search("hero") ? "Found" : "Not found") << endl << endl;

    // Тест 4: Удаление слова и проверка счетчика слов с префиксом
    cout << "Test 4: Delete 'heaven' and check prefix count" << endl;
    cout << "Before deletion - count_words('hea'): " << count_words("hea") << endl;
    deleteWord("heaven");
    cout << "After deletion - count_words('hea'): " << count_words("hea") << endl << endl;

    // Тест 5: Удаление всех слов и проверка пустоты дерева
    cout << "Test 5: Delete all words and check emptiness" << endl;
    deleteWord("world");
    deleteWord("heaven");
    deleteWord("heavy");
    deleteWord("hero");
    deleteWord("heat");
    deleteWord("heap");
    deleteWord("her");
    deleteWord("hex");
    deleteWord("hint");
    cout << "Count of words with empty prefix: " << count_words("") << endl;
    return 0;
}