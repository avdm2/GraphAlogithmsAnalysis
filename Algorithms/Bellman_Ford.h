#include <iostream>
#include <vector>
#include <climits>

#include "../Models/Edge.h"
#include "../Services/Timer.h"

using Graph = std::vector<std::vector<Edge>>;

std::pair<uint64_t, std::vector<int>> bellman_ford(const Graph& graph) {
    auto time = std::chrono::high_resolution_clock::now();

    int start = 0;
    int n = static_cast<int>(graph.size());
    std::vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            if (distance[u] != INT_MAX) {
                for (auto edge : graph[u]) {
                    distance[edge.to] = std::min(distance[edge.to], distance[u] + edge.weight);
                }
            }
        }
    }

    return {get_time(time), distance};
}
