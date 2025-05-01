// Реализуйте представление ориентированного графа согласно структуре Вирта. Обеспечьте ввод графа с клавиатуры (задание списка вершин и рёбер),
// построение связной структуры в памяти и вывод списка смежности для каждой вершины.
// Дополнительно реализуйте простейший алгоритм обхода графа в глубину (DFS), используя разработанную структуру.

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class DirectedGraph {
private:
    map<string, vector<string>> adjList; // список смежности для орграфа

public:
    // Добавление вершины (если её ещё нет)
    void addVertex(const string& v) {
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = {};
        }
    }
    // Добавление направленного ребра u -> v
    void addEdge(const string& u, const string& v) {
        addVertex(u);
        addVertex(v);
        adjList[u].push_back(v);
    }
    // Вывод списка смежности
    void printAdjacencyList() {
        cout << "Adjacency list:\n";
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    // Поиск в глубину (DFS)
    void dfs(const string& start) {
        set<string> visited;
        cout << "DFS traversal from " << start << ": ";
        dfsUtil(start, visited);
        cout << endl;
    }

private:
    // Рекурсивная функция DFS
    void dfsUtil(const string& vertex, set<string>& visited) {
        visited.insert(vertex);
        cout << vertex << " ";
        for (const string& neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }
};

void runTest(int testNumber, const vector<pair<string, string>>& edges, const string& startVertex) {
    cout << "\n--- Test " << testNumber << " ---\n";
    DirectedGraph g;
    // Добавляем рёбра
    for (const auto& e : edges) {
        g.addEdge(e.first, e.second);
    }
    g.printAdjacencyList();
    g.dfs(startVertex);
}

int main() {
    // Test 1: Простой линейный граф A → B → C → D
    runTest(1,
        {{"A", "B"}, {"B", "C"}, {"C", "D"}},
        "A"
    );
    // Test 2: Ветвление A → B и A → C
    runTest(2,
        {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"C", "E"}},
        "A"
    );
    // Test 3: Граф с циклом A → B → C → A
    runTest(3,
        {{"A", "B"}, {"B", "C"}, {"C", "A"}},
        "A"
    );
    // Test 4: Несвязный граф (A → B, E → F)
    runTest(4,
        {{"A", "B"}, {"E", "F"}},
        "A"
    );
    return 0;
}

