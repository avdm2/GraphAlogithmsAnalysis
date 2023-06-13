#include <iomanip>

#include "Generator.h"
#include "AverageCalculator.h"
#include "Writer.h"
#include "EdgeCounter.h"

#include "../Algorithms/ Dijkstra.h"
#include "../Algorithms/Bellman_Ford.h"
#include "../Algorithms/Floyd_Warshall.h"

void get_info(unsigned short& c, uint64_t &avg) {
    uint64_t ns = std::chrono::nanoseconds(avg).count(), mic = ns / 1000;
    ns %= 1000;

    uint64_t ms = mic / 1000;
    mic %= 1000;

    uint64_t secs = ms / 1000;
    ms %= 1000;

    uint64_t mins = secs / 60;
    secs %= 60;

    std::cout << ++c << "/189 (" << c / 189.0 * 100 << "%); AVG TIME = " << mins << "min " << secs << "sec " << ms <<"ms " << mic << "mic " << ns << "ns;\n";
}

void test_graph(unsigned short& c, const int& vertex_amount, const std::string& graph_type,
                const Graph& graph, const int& edge_amount) {
    std::cout << "==================TYPE: " << graph_type << "; VERTEX_AMOUNT = " << vertex_amount << "; METHOD = Dijkstra;==================\n";
    auto avg = average_time(graph, dijkstra);
    write_CSV(graph_type, vertex_amount, edge_amount, "Dijkstra", avg);
    get_info(c, avg);

    std::cout << "==================TYPE: " << graph_type << "; VERTEX_AMOUNT = " << vertex_amount << "; METHOD = BellmanFord;==================\n";
    avg = average_time(graph, bellman_ford);
    write_CSV(graph_type, vertex_amount, edge_amount, "BellmanFord", avg);
    get_info(c, avg);

    std::cout << "==================TYPE: " << graph_type << "; VERTEX_AMOUNT = " << vertex_amount << "; METHOD = FloydWarshall;==================\n";
    avg = average_time(graph, floyd_warshall);
    write_CSV(graph_type, vertex_amount, edge_amount, "FloydWarshall", avg);
    get_info(c, avg);
}

void run_tests() {
    unsigned short c = 0;
    std::cout << std::fixed << std::setprecision(2);

    for (int vertex_amount = 10; vertex_amount <= 1010; vertex_amount += 50) {
        Graph complete_graph = get_complete_graph(vertex_amount);
        Graph connected_graph = get_connected_graph(vertex_amount);
        Graph sparse_graph = get_sparse_graph(vertex_amount);

        std::vector<std::pair<std::string, Graph>> graphs = {std::make_pair("Complete", complete_graph),
                                                             std::make_pair("Connected", connected_graph),
                                                             std::make_pair("Sparse", sparse_graph)};

        for (auto& graph_info : graphs) {
            std::string graph_type = graph_info.first;
            Graph graph = graph_info.second;
            int edge_amount = count_edges(graph);

            test_graph(c, vertex_amount, graph_type, graph, edge_amount);
        }
    }
}
