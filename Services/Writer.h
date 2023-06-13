#include <iostream>
#include <fstream>

void write_header() {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << "GraphType;VertexAmount;EdgeAmount;Algorithm;Time" << "\n";
    file.close();
}

void write_CSV(const std::string& graph_type, const int& vertex_amount, const int& edge_amount,
               const std::string& algorithm, const uint64_t& time) {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << graph_type << ";" << vertex_amount << ";" << edge_amount << ";" << algorithm << ";" << time << "\n";
    file.close();
}

void clear_CSV() {
    std::ofstream file("../Output/data.csv", std::ios::out);
    file.close();
}