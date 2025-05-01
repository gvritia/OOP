// Компания разрабатывает систему сжатия данных для передачи текстовой информации. Вам необходимо реализовать алгоритм Хаффмана, чтобы минимизировать количество бит, используемых для представления текста.
// Реализовать следующие методы:
// а) Метод построения дерева;
// б) Метод построения списка частот символов;
// в) Метод шифрования (сжатия);
// г) Метод дешифровки;
// д) подсчет коэффициента сжатия.

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct HuffmanNode {
    char ch; // Символ (только для листьев)
    double freq; // Частота встречаемости символа
    HuffmanNode* left;
    HuffmanNode* right;
};

struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq; // меньше частота имеет высший приоритет
    }
};

// ф-ия построения частотного словаря
unordered_map<char, double> build_frequency_map(const string& text) {
    unordered_map<char, double> freqMap;
    for (char ch : text) { // подсчёт кол-во вхождения каждого символа
        freqMap[ch]++;
    }
    for (auto& pair : freqMap) { // Преобразуем количества в частоты
        pair.second /= text.length();
    }
    return freqMap;
}

void print_frequency_list(const unordered_map<char, double>& freqMap) {
    cout << "Frequency list:\n";
    for (const auto& pair : freqMap) {
        cout << pair.first << " (" << pair.second << ") --> ";
    }
    cout << endl;
}
// Ф-ия построения дерева Хаффмана
HuffmanNode* build_huffman_tree(const unordered_map<char, double>& freqMap) {
    // Очередь с приоритетом для хранения узлов
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
    // Создаем листья дерева для каждого символа
    for (const auto& pair : freqMap) {
        HuffmanNode* node = new HuffmanNode;
        node->ch = pair.first;
        node->freq = pair.second;
        node->left = nullptr;
        node->right = nullptr;
        pq.push(node);
    }
    // Строим дерево, объединяя узлы с наименьшими частотами
    while (pq.size() > 1) {
        // Извлекаем два узла с наименьшими частотами
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        // Создаем новый родительский узел
        HuffmanNode* parent = new HuffmanNode;
        parent->ch = '*'; // Внутренний узел помечаем *
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}
// Рекурсивная функция генерации кодов Хаффмана
void generate_codes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right) { // Если достигли листа, сохраняем код
        huffmanCode[root->ch] = code;
    }
    // Рекурсивно обходим левое и правое поддеревья
    generate_codes(root->left, code + "0", huffmanCode);
    generate_codes(root->right, code + "1", huffmanCode);
}
// Функция кодирования текста
string encode_text(const string& text, const unordered_map<char, string>& huffmanCode) {
    string encoded;
    // Для каждого символа в тексте добавляем его код Хаффмана
    for (char ch : text) {
        encoded += huffmanCode.at(ch);
    }
    return encoded;
}
// Функция декодирования текста
string decode_text(const string& encoded, HuffmanNode* root) {
    string decoded;
    HuffmanNode* current = root;
    for (char bit : encoded) { // Проходим по каждому биту закодированной строки
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        // Если достигли листа, добавляем символ и возвращаемся к корню
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}
// Функция расчета коэффициента сжатия
double calc_compression_ratio(const string& original, const string& encoded) {
    double originalSize = original.length() * 8;
    double compressedSize = encoded.length();
    return (compressedSize/ originalSize) * 100;
}

void delete_tree(HuffmanNode* root) {
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void run_test(const string& testName, const string& input) {
    cout << "\n=== Running test: " << testName << " ===\n";
    cout << "Input text: " << input << endl;
    unordered_map<char, double> freqMap = build_frequency_map(input);
    print_frequency_list(freqMap);
    HuffmanNode* root = build_huffman_tree(freqMap);
    unordered_map<char, string> huffmanCode;
    generate_codes(root, "", huffmanCode);
    string encoded = encode_text(input, huffmanCode);
    cout << "Encoded: " << encoded << endl;
    double ratio = calc_compression_ratio(input, encoded);
    cout << "Compression ratio: " << ratio << "%" << endl;
    string decoded = decode_text(encoded, root);
    cout << "Decoded: " << decoded << endl;
    if (input == decoded) {
        cout << "TEST PASSED: Original and decoded texts match!\n";
    } else {
        cout << "TEST FAILED: Original and decoded texts don't match!\n";
    }
    delete_tree(root);
}

int main() {
    run_test("Simple text", "hello world");
    run_test("Repeated characters", "aaaaabbbbcccdde");
    run_test("Single word", "programming");
    run_test("Special characters", "Huffman@123!");
    run_test("Long text", "the quick brown fox jumps over the lazy dog");
    run_test("Two same characters", "aa");
    run_test("Two different characters", "ab");
    run_test("Two different characters", "mama mila ramu");
    string userText;
    cout << "\nEnter your own text (at least 2 characters): ";
    getline(cin, userText);
    if (userText.length() >= 2) {
        run_test("User input test", userText);
    }
    else {
        cout << "Text must contain at least 2 characters.\n";
    }
    return 0;
}