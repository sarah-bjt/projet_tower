#include <iostream>
#include "path.hpp"
#include <unordered_map>
#include <queue>
#include <vector>

std::vector<WeightedGraphEdge> WeightedGraph::getNeighbors(int vertex) const
{
    auto it = adjacency_list.find(vertex);
    if (it != adjacency_list.end()) {
        return it->second;
    } else {
        return {};
    }
}
//
std::unordered_map<int, std::pair<float, int>> dijkstra(WeightedGraph const& graph, int const& start, int const end) //Prend en paramètre un graphe, un sommet de départ et un sommet d'arrivée
{
    std::unordered_map<int, std::pair<float, int>> distances {}; //Tableau associatif associant à chaque sommet du graphe une paire (distance, sommet précédent). Ce tableau permet de stocker les distances les plus courtes du sommet de départ à chaque sommet.
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {}; //File de priorité stockant les sommets à visiter, triés par leur distance du sommet de départ

    distances[start] = std::make_pair(0.0f, -1); //On initialise le tableau associatif distances avec le premier sommet, définie à 0 et n'ayant pas de sommet précédent
    to_visit.push(std::make_pair(0.0f, start)); //On ajoute le premier sommet à la file de priorité
    
    while (!to_visit.empty()) //Tant que la file de priorité n'est pas vide, c'est-à-dire tant que l'on a pas tout visité
    {
        auto current = to_visit.top(); //On prend le sommet le plus proche du sommet de départ
        to_visit.pop(); //On le retire de la file

        if (current.second == end) //Si le sommet actuel est le sommet d'arrivée, on retourne le tableau associatif
        {
            distances;
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