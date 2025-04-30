#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

// Простая структура графа на списке смежности
class SimpleGraph {
private:
    map<string, vector<string>> adjList; // Список смежности
    set<string> allVertices;             // Все вершины (для проверки изолированных)

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
