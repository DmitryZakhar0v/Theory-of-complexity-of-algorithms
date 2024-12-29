#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

/**
* @brief Алгоритм Дейкстры
* @param start Стартовая вершина
* @param n Число вершин
* @param graph Исходный граф
* @return Массив с минимальными расстояниями до вершин
*/
std::vector<int> dijkstra(const int start, const int n, const std::vector<std::vector<int>> graph);


std::vector<int> dijkstra(const int start, const int n, const std::vector<std::vector<int>> graph) {
    const int inf = std::numeric_limits<int>::max();
    std::vector<int> distance(n, inf);
    std::vector<bool> visited(n, false);
    distance[start] = 0;

    for (size_t i = 0; i < n; i++) {
        int w = -1;
        for (size_t j = 0; j < n; ++j) {
            if (!visited[j] && (w == -1 || distance[j] < distance[w])) {
                w = j;
            }
        }

        if (distance[w] == inf) {
            break;
        }
        visited[w] = true;

        for (size_t k = 0; k < n; k++) {
            if (graph[w][k] != inf && !visited[k]) {
                int weight = graph[w][k];
                if (distance[w] + weight < distance[k]) {
                    distance[k] = distance[w] + weight;
                }
            }
        }
    }
    return distance;
}


int main()
{
    const int inf = std::numeric_limits<int>::max();
    const int start = 0;

    std::vector<std::vector<int>> graph = {
        {0, 10, inf, 30, 100},
        {50, inf, inf, inf, inf},
        {inf, inf, inf, inf, 10},
        {inf, inf, 20, inf, 60},
        {inf, inf, inf, inf, inf}
    };

    const int n = graph.size();
    std::vector<int> result = dijkstra(start, n, graph);
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
}
