// Разработайте программу, которая позволяет пользователю выбрать способ задания графа: с помощью матрицы смежности или матрицы инцидентности.
// Программа должна запросить у пользователя количество вершин и рёбер, после чего предложить ввести соответствующую матрицу.
// Также необходимо реализовать простой алгоритм обхода графа: поиск в глубину (DFS) или поиск в ширину (BFS) и вывести порядок обхода вершин.
// 🔍 Замечание: программа должна определять автоматически является ли граф ориентированным или неориентированным.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix; // Матрица смежности
    int num_vertices;              // Количество вершин
    bool directed;                 // Ориентированный ли граф

public:
    Graph(int n) {
        num_vertices = n;
        directed = false;
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    // Ввод матрицы смежности вручную (без клавиатуры)
    void set_adjacency_matrix(const vector<vector<int>>& matrix) {
        adjMatrix = matrix;
        directed = false;
        for (int i = 0; i < num_vertices; ++i)
            for (int j = 0; j < num_vertices; ++j)
                if (adjMatrix[i][j] != adjMatrix[j][i])
                    directed = true;
    }

    // Ввод матрицы инцидентности вручную (без клавиатуры)
    void set_incidence_matrix(const vector<vector<int>>& incMatrix) {
        int numEdges = incMatrix[0].size();
        adjMatrix.assign(num_vertices, vector<int>(num_vertices, 0));
        directed = false;

        for (int j = 0; j < numEdges; ++j) {
            int from = -1, to = -1;
            for (int i = 0; i < num_vertices; ++i) {
                if (incMatrix[i][j] == 1) {
                    if (from == -1)
                        from = i;
                    else
                        to = i;
                } else if (incMatrix[i][j] == -1) {
                    from = i;
                    directed = true;
                }
            }
            if (from != -1 && to != -1) {
                adjMatrix[from][to] = 1;
                if (!directed)
                    adjMatrix[to][from] = 1;
            }
        }
    }

    void bfs(int start) {
        vector<bool> visited(num_vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int i = 0; i < num_vertices; ++i) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void print_graph_type() {
        if (directed)
            cout << "Graph is directed.\n";
        else
            cout << "Graph is undirected.\n";
    }
};

int main() {
    // Test 1
    cout << "--- Test 1: Adjacency matrix (undirected) ---\n";
    Graph g1(4);
    g1.set_adjacency_matrix({
        {0,1,0,0},
        {1,0,1,1},
        {0,1,0,0},
        {0,1,0,0}
    });
    g1.print_graph_type();
    g1.bfs(0);
    // Test 2
    cout << "\n--- Test 2: Adjacency matrix (directed) ---\n";
    Graph g2(3);
    g2.set_adjacency_matrix({
        {0,1,0},
        {0,0,1},
        {1,0,0}
    });
    g2.print_graph_type();
    g2.bfs(0);
    // Test 3
    cout << "\n--- Test 3: Disconnected graph (adjacency matrix) ---\n";
    Graph g3(4);
    g3.set_adjacency_matrix({
        {0,1,0,0},
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    });
    g3.print_graph_type();
    g3.bfs(0);
    // Test 4
    cout << "\n--- Test 4: Empty graph (adjacency matrix) ---\n";
    Graph g4(3);
    g4.set_adjacency_matrix({
        {0,0,0},
        {0,0,0},
        {0,0,0}
    });
    g4.print_graph_type();
    g4.bfs(0);
    // Test 5
    cout << "\n--- Test 5: Incidence matrix (undirected) ---\n";
    Graph g5(3);
    g5.set_incidence_matrix({
        {1, 0},
        {1, 1},
        {0, 1}
    });
    g5.print_graph_type();
    g5.bfs(0);
    // Test 6
    cout << "\n--- Test 6: Incidence matrix (directed) ---\n";
    Graph g6(3);
    g6.set_incidence_matrix({
        {-1, 0},
        { 1, -1},
        { 0, 1}
    });
    g6.print_graph_type();
    g6.bfs(0);
    return 0;
}
