#pragma once

#ifndef PATH_HPP
#define PATH_HPP

#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>


struct WeightedGraphEdge // Structure pour définir une arrête dans un graphe
{
    int to {}; // Destination de l'arrête
    float weight {1.0f}; // Poids de l'arrête
};

struct WeightedGraph // Structure pour définir un graphe pondéré
{
    std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list {}; // Liste d'adjacence
    std::vector<std::pair<float, float>> node_positions; // Tableau de positions des noeuds
    std::vector<WeightedGraphEdge> getNeighbors(int vertex) const; // Fonction pour trouver les voisins d'un noeud
};

std::pair<float, float> get_node_position(int node, const WeightedGraph& graph); // Fonction pour trouver la position d'un noeud

void read_itd_file(const std::string& filepath, WeightedGraph& graph); // Déclaration de la fonction de lecture du fichier itd

#endif