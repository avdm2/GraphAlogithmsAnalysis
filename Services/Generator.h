#pragma once

#include <iostream>
#include <vector>

#include "../Models/Edge.h"

std::vector<std::vector<Edge>> get_complete_graph(int size) {
    srand(time(nullptr));
    std::vector<std::vector<Edge>> graph(size);
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int weight = rand() % 10 + 1;
            graph[i].push_back({j, weight});
            graph[j].push_back({i, weight});
        }
    }
    return graph;
}

std::vector<std::vector<Edge>> get_connected_graph(int size) {
    srand(time(nullptr));
    std::vector<std::vector<Edge>> graph(size);
    for (int i = 1; i < size; ++i) {
        int weight = rand() % 10 + 1;
        graph[i].push_back({i - 1, weight});
        graph[i - 1].push_back({i, weight});
    }

    int extra_edges = size / 2;
    for (int i = 0; i < extra_edges; ++i) {
        int u = rand() % size, v = rand() % size;
        if (u != v) {
            int weight = rand() % 10 + 1;
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
    }
    return graph;
}

std::vector<std::vector<Edge>> get_sparse_graph(int size) {
    srand(time(nullptr));
    std::vector<std::vector<Edge>> graph(size);
    for (int i = 1; i < size; ++i) {
        int weight = rand() % 10 + 1;
        graph[i].push_back({i - 1, weight});
        graph[i - 1].push_back({i, weight});
    }
    return graph;
}