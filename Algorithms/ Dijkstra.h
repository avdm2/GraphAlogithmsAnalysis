#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#include "../Models/Edge.h"
#include "../Services/Timer.h"

using Graph = std::vector<std::vector<Edge>>;

std::pair<uint64_t, std::vector<int>> dijkstra(const Graph& graph) {
    auto time = std::chrono::high_resolution_clock::now();

    int start = 0;
    int n = static_cast<int>(graph.size());
    std::vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.emplace(0, start);

    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if (d_v != distance[v])
            continue;

        for (auto edge : graph[v]) {
            if (distance[v] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[v] + edge.weight;
                q.emplace(distance[edge.to], edge.to);
            }
        }
    }

    return {get_time(time), distance};
}
