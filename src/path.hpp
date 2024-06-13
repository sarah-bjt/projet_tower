#pragma once
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
    std::vector<WeightedGraphEdge> getNeighbors(int vertex) const;
};//