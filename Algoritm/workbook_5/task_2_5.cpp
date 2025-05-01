// В неком королевстве существует сеть дорог между городами, представленная в виде неориентированного графа. Из-за особенностей местного климата некоторые дороги становятся невидимыми: они есть, но их не видно на карте. Тем не менее, жители всё равно могут по ним перемещаться.
// Вам известны все города (вершины) и только те дороги, которые остались видимыми (рёбра). К счастью, вы также знаете, что изначально все города были соединены так, что можно было добраться от любого города до любого другого.
// Какое минимальное количество дорог необходимо «восстановить», чтобы вновь гарантировать связность всей карты?
//
// Вход:
// Вершины: A, B, C, D, E
// Видимые рёбра:
// A B
// C D
//
// Выход:
// В графе 3 компоненты связности: {A, B}, {C, D}, {E}
// Нужно добавить минимум 2 ребра, чтобы соединить все компоненты.
//
// 💡Подсказка:
// Количество недостающих рёбер для связности = количество компонент связности − 1.

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class SimpleGraph {
private:
    map<string, vector<string>> adjList;
    set<string> allVertices;

public:
    // Добавление вершины
    void addVertex(const string& v) {
        allVertices.insert(v);
        if (adjList.find(v) == adjList.end())
            adjList[v] = {};
    }
    // Добавление ребра (неориентированный граф)
    void addEdge(const string& u, const string& v) {
        addVertex(u);
        addVertex(v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // Поиск количества компонент связности с помощью BFS
    int countConnectedComponents() {
        set<string> visited;
        int components = 0;
        for (const string& vertex : allVertices) {
            if (visited.find(vertex) == visited.end()) {
                components++;
                bfs(vertex, visited);
            }
        }
        return components;
    }
    // BFS для обхода одной компоненты
    void bfs(const string& start, set<string>& visited) {
        queue<string> q;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            for (const string& neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
};

void runTest(const vector<string>& vertices, const vector<pair<string, string>>& edges) {
    SimpleGraph g;
    // Добавляем все вершины
    for (const string& v : vertices)
        g.addVertex(v);
    // Добавляем оставшиеся видимые рёбра
    for (const auto& e : edges)
        g.addEdge(e.first, e.second);
    // Вычисляем количество компонент связности
    int components = g.countConnectedComponents();
    int toRestore = components - 1;
    cout << "Connected components: " << components << endl;
    cout << "Minimum edges to restore: " << toRestore << endl;
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "--- Test 1: Simple 5-node graph with 2 edges ---\n";
    runTest(
        {"A", "B", "C", "D", "E"},
        {{"A", "B"}, {"C", "D"}}
    );
    cout << "--- Test 2: Fully connected graph ---\n";
    runTest(
        {"A", "B", "C"},
        {{"A", "B"}, {"B", "C"}, {"C", "A"}}
    );
    cout << "--- Test 3: No edges at all ---\n";
    runTest(
        {"X", "Y", "Z"},
        {}
    );
    cout << "--- Test 4: Two isolated nodes + connected chain ---\n";
    runTest(
        {"A", "B", "C", "D", "E"},
        {{"A", "B"}, {"B", "C"}}
    );
    cout << "--- Test 5: Already tree (connected, no cycle) ---\n";
    runTest(
        {"A", "B", "C", "D"},
        {{"A", "B"}, {"A", "C"}, {"C", "D"}}
    );
    return 0;
}
