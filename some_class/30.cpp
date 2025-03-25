// Чхобадзе Максиме Кахаберович ЭФБО-16-24

// 30. Класс "Клавиатура"
// Создайте класс Keyboard с методом type, который генерирует
// исключение, если клавиатура не подключена.
// Тестирование: Проверьте корректность обработки исключения при
// попытке печати без подключения.

#include <iostream>
#include <stdexcept>

using namespace std;

class Keyboard {
    bool isConnected;

public:
    Keyboard(bool connected = false) : isConnected(connected) {
    }

    void connect() {
        isConnected = true;
    }

    void disconnect() {
        isConnected = false;
    }

    void type() {
        if (!isConnected) {
            throw runtime_error("Keyboard is not connected!");
        }
        cout << "Typing on keyboard..." << endl;
    }
};

int main() {
    Keyboard kb;

    try {
        kb.type(); // Попытка печатать без подключения
    }
    catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    kb.connect();
    try {
        kb.type(); // Теперь печать работает
    }
    catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
