#include "path.hpp"

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<WeightedGraphEdge> WeightedGraph::getNeighbors(int vertex) const
{
    auto it = adjacency_list.find(vertex); // Cherche le sommet dans la liste d'adjacence
    if (it != adjacency_list.end()) {
        return it->second; // Si le sommet est trouvé, on retourne les sommets liés (les voisins)
    } else {
        return {};
    }
}

std::unordered_map<int, std::pair<float, int>> dijkstra(WeightedGraph const& graph, int const& start, int const end) //Prend en paramètre un graphe, un sommet de départ et un sommet d'arrivée
{
    std::unordered_map<int, std::pair<float, int>> distances {}; //Tableau associatif associant à chaque sommet du graphe une paire (distance, sommet précédent). Ce tableau permet de stocker les distances les plus courtes du sommet de départ à chaque sommet.
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {}; //File de priorité stockant les sommets à visiter, triés par leur distance du sommet de départ

    distances[start] = std::make_pair(0.0f, -1); //On initialise le tableau associatif distances avec le premier sommet, définie à 0 et n'ayant pas de sommet précédent
    to_visit.push(std::make_pair(0.0f, start)); //On ajoute le premier sommet à la file de priorité
    
    while (!to_visit.empty()) //Boucle tant que la file de priorité n'est pas vide, c'est-à-dire tant que l'on a pas tout visité
    {
        auto current = to_visit.top(); //On prend le sommet le plus proche du sommet de départ
        to_visit.pop(); //On le retire de la file

        if (current.second == end) //Si le sommet actuel est le sommet d'arrivée, on retourne le tableau associatif
        {
            return distances; // On retourne le tableau associatif contentant les distances
        }

        for (auto& neighbor : graph.getNeighbors(current.second)) //On parcourt les voisins du sommet actuel à partir de la liste d'adjacence
        {
            auto find_node { distances.find(neighbor.to) }; //On vérifie si le sommet a déjà été visité 
            bool const visited { find_node != distances.end() };

            if (!visited) //Si le sommet n'a pas été visité
            {
                distances[neighbor.to] = std::make_pair(current.first + neighbor.weight, current.second); //On met à jour sa distance
                to_visit.push(std::make_pair(distances[neighbor.to].first, neighbor.to)); //On l'ajoute dans la file
            }
            else //Si le sommet a déjà été visité
            {
                if (distances[neighbor.to].first > current.first + neighbor.weight) //Si la distance dans le tableau associatif est plus grande
                {
                    distances[neighbor.to] = std::make_pair(current.first + neighbor.weight, current.second); //Comme on a un chemin plus court, on met à jour le tableau associatif
                    to_visit.push(std::make_pair(distances[neighbor.to].first, neighbor.to)); //On ajoute le sommet dans la file
                }
            } 
        }
    }

    return distances; //On renvoie le tableau associatif contenant les plus courts chemins
}

void read_itd_file(const std::string& filepath, WeightedGraph& graph)
{
    // Ouverture du fichier ITD
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl; // Si le fichier ne peut pas s'ouvrir, on affiche une erreur
        return;
    }

    std::string line; // Variable pour stocker chaque ligne lue du fichier ITD
    while (std::getline(file, line))
    {
        std::istringstream iss(line); // Flux pour lire et analyser chaque ligne
        std::string keyword;

        if (line.find("node") == 0) { // Lecture des lignes commençant par "node"
            int node_id;
            float x, y;

            if (iss >> keyword >> node_id >> x >> y) { // On extrait les données des lignes commençant par "node"
                graph.node_positions.emplace_back(x, y); // Ajout du nœud au graphe avec sa position
            } else {
                std::cerr << "Error parsing node line: " << line << std::endl;
            }
        }
    }

    int start_node = 0;
    int end_node = 15;

    auto distances = dijkstra(graph, start_node, end_node);
}

std::pair<float, float> get_node_position(int node, const WeightedGraph& graph) {
    if (node < graph.node_positions.size()) { // On vérifie que le nœud existe dans le vecteur des positions des nœuds
        return std::make_pair(-1.81f + graph.node_positions[node].first*(120.0f/720.0f), 0.85f - graph.node_positions[node].second*(120.0f/720.0f)); // Calcul des positions x et y transformées
    } else {
        return std::make_pair(-1.0f, -1.0f); // Gestion d'erreur si le nœud n'existe pas
    }
}