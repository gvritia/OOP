#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int start; // время начало
    int end;  // время конца
};

// Функция сравнения для сортировки задач по времени окончания
bool compare_tasks(const Task &a, const Task &b) {
    return a.end < b.end; // Сортируем по возрастанию времени окончания
}
// Основная функция для выбора максимального количества непересекающихся задач
vector<Task> selectMaxTasks(vector<Task> tasks) {
    // Сортируем задачи по времени окончания
    sort(tasks.begin(), tasks.end(), compare_tasks);
    vector<Task> selectedTasks; // Вектор для выбранных задач
    if (tasks.empty()) {
        return selectedTasks;
    }
    selectedTasks.push_back(tasks[0]); // выбираем первую задачу с самым ранним окончанием
    int lastEnd = tasks[0].end;// Запоминаем время окончания выбранной задачи

    for (size_t i = 1; i < tasks.size(); i++) {
        if (tasks[i].start >= lastEnd) {
            // Если текущая задача начинается после окончания последней выбранно. Добавляем ее в выбранные
            selectedTasks.push_back(tasks[i]);
            lastEnd = tasks[i].end;
        }
    }
    return selectedTasks;
}

void print_test_result(const vector<Task>& tasks, int testNumber) {
    vector<Task> result = selectMaxTasks(tasks);
    cout << "Test " << testNumber << ":\n";
    cout << "Input tasks: ";
    for (const auto &task : tasks) {
        cout << "[" << task.start << ", " << task.end << "] ";
    }
    cout << "\nMaximum non-overlapping tasks: " << result.size() << endl;
    cout << "Selected tasks: ";
    for (const auto &task : result) {
        cout << "[" << task.start << ", " << task.end << "] ";
    }
    cout << "\n\n";
}

int main() {
    // Тест 1: Базовый случай
    vector<Task> test1 = {{1, 3}, {2, 5}, {3, 6}, {5, 7}, {8, 9}};
    print_test_result(test1, 1);
    // Тест 2: Все задачи пересекаются
    vector<Task> test2 = {{1, 4}, {2, 5}, {3, 6}, {4, 7}};
    print_test_result(test2, 2);
    // Тест 3: Одна задача
    vector<Task> test3 = {{5, 7}};
    print_test_result(test3, 3);
    // Тест 4: Нет пересекающихся задач
    vector<Task> test4 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    print_test_result(test4, 4);
    // Тест 5: Сложный случай с множеством пересечений
    vector<Task> test5 = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    print_test_result(test5, 5);
    // Тест 6: Крайний случай - пустой ввод
    vector<Task> test6 = {};
    print_test_result(test6, 6);
    // Тест 7: Задачи с одинаковым временем окончания
    vector<Task> test7 = {{1, 3}, {2, 3}, {4, 6}, {3, 6}, {7, 8}};
    print_test_result(test7, 7);
    return 0;
}