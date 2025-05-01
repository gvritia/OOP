// В таблице приведено расстояние между кампусами РТУ МИРЭА
// Пр-т Вернадского, 78	Пр-т Вернадского, 86	Стромынка, 20	Малая Пироговская, 1	5-я улица Соколиной горы, 22	Усачева, 7
// Пр-т Вернадского, 78	-	1.97	21.6	10.7	22.3	10.4
// Пр-т Вернадского, 86	1.97	-	22.3	11.4	23	11.1
// Стромынка, 20	21.6	22.3	-	11.5	5.2	12
// Малая Пироговская, 1	10.7	11.4	11.5	-	13.4	0.68
// 5-я улица Соколиной горы, 22	22.3	23	5.2	13.4	-	13.8
// Усачева, 7	10.4	11.1	12	0.68	13.8	-
//
// С помощью алгоритма Прима выделить маршрут с минимальной общей длиной, связывающий все кампусы РТУ МИРЭА

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Структура для хранения ребра
struct Edge {
    string from;
    string to;
    double weight;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

class PrimMST {
private:
    map<string, vector<Edge>> adjList; // Список смежности
    vector<Edge> mstEdges;             // Выбранные рёбра
    double totalWeight = 0.0;

public:
    // Добавление ребра (двунаправленного)
    void addEdge(const string& u, const string& v, double w) {
        adjList[u].push_back({u, v, w});
        adjList[v].push_back({v, u, w});
    }
    // Реализация алгоритма Прима
    void run(const string& start) {
        set<string> visited;
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        visited.insert(start);
        for (const Edge& e : adjList[start]){
        pq.push(e);
        }
        while (!pq.empty()) {
            Edge current = pq.top();
            pq.pop();
            if (visited.count(current.to)) {
                continue;
            }
            visited.insert(current.to);
            mstEdges.push_back(current);
            totalWeight += current.weight;
            for (const Edge& next : adjList[current.to]){
                if (!visited.count(next.to)) {
                    pq.push(next);
                }
            }
        }
    }

    void printResult() {
        cout << "Minimum Spanning Tree:\n";
        for (const Edge& e : mstEdges){
            cout << e.from << " -> " << e.to << " (" << e.weight << " km)\n";
        }
        cout << "Total length: " << totalWeight << " km\n";
        cout << "-----------------------------------------\n";
    }
};

int main() {
    PrimMST mst;
    // Кампусы
    vector<string> campuses = {
        "Vernadskogo 78",
        "Vernadskogo 86",
        "Stromynka 20",
        "Malaya Pirogovskaya 1",
        "5-ya Sokolinnoy Gory 22",
        "Usacheva 7"
    };
    // Добавление рёбер с расстояниями
    mst.addEdge("Vernadskogo 78", "Vernadskogo 86", 1.97);
    mst.addEdge("Vernadskogo 78", "Stromynka 20", 21.6);
    mst.addEdge("Vernadskogo 78", "Malaya Pirogovskaya 1", 10.7);
    mst.addEdge("Vernadskogo 78", "5-ya Sokolinnoy Gory 22", 22.3);
    mst.addEdge("Vernadskogo 78", "Usacheva 7", 10.4);
    mst.addEdge("Vernadskogo 86", "Stromynka 20", 22.3);
    mst.addEdge("Vernadskogo 86", "Malaya Pirogovskaya 1", 11.4);
    mst.addEdge("Vernadskogo 86", "5-ya Sokolinnoy Gory 22", 23.0);
    mst.addEdge("Vernadskogo 86", "Usacheva 7", 11.1);
    mst.addEdge("Stromynka 20", "Malaya Pirogovskaya 1", 11.5);
    mst.addEdge("Stromynka 20", "5-ya Sokolinnoy Gory 22", 5.2);
    mst.addEdge("Stromynka 20", "Usacheva 7", 12.0);
    mst.addEdge("Malaya Pirogovskaya 1", "5-ya Sokolinnoy Gory 22", 13.4);
    mst.addEdge("Malaya Pirogovskaya 1", "Usacheva 7", 0.68);
    mst.addEdge("5-ya Sokolinnoy Gory 22", "Usacheva 7", 13.8);
    // Запуск Прима с произвольной вершины
    mst.run("Vernadskogo 78");
    mst.printResult();

    return 0;
}
