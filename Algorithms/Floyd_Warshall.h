#include <iostream>
#include <vector>
#include <climits>

#include "../Models/Edge.h"
#include "../Services/Timer.h"

using Graph = std::vector<std::vector<Edge>>;

std::pair<uint64_t, std::vector<int>> floyd_warshall(const Graph& graph) {
    auto time = std::chrono::high_resolution_clock::now();

    int start = 0;
    int n = static_cast<int>(graph.size());
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
    std::vector<int> shortest_distances(n, INT_MAX);

    for (int i = 0; i < n; ++i) {
        for (auto edge : graph[i]) {
            dist[i][edge.to] = edge.weight;
        }
        dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        shortest_distances[i] = dist[start][i];
    }

    return {get_time(time), shortest_distances};
}

