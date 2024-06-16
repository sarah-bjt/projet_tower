#pragma once

#ifndef PATH_HPP
#define PATH_HPP

#include <vector>
#include <unordered_map>
#include <utility>


struct WeightedGraphEdge
{
    int to {};
    float weight {1.0f};
};

struct WeightedGraph
{
    std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list {};
    std::vector<std::pair<float, float>> node_positions;

    std::vector<WeightedGraphEdge> getNeighbors(int vertex) const;
};

// Déclaration de la fonction
std::pair<float, float> get_node_position(int node, const WeightedGraph& graph);

// Déclaration de la fonction de lecture du fichier itd
void read_itd_file(const std::string& filepath, WeightedGraph& graph);

#endif