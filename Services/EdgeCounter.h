#include <iostream>
#include <vector>

#include "../Models/Edge.h"

int count_edges(const std::vector<std::vector<Edge>>& graph) {
    int sum = 0;
    for (const auto& adj_list : graph) {
        sum += static_cast<int>(adj_list.size());
    }
    return sum / 2;
}
