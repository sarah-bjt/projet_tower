#pragma once

#include "App.hpp"
#include "path.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include <sstream>
#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include <vector>

enum class Enemy_Type {  //Les trois différents types d'ennemis possibles
    Fast,
    Normal,
    Robust
};

struct Enemy{
    int enemy_id; //identifiant de l'ennemi et sert à faire un statut de vie ou de mort
    int life;  // Les points de vie d'un ennemi
    float speed;  // La vitesse en cases d'un ennemi
    int money_reward;   // La récompense en argent qu'un ennemi rapporte au joueur une fois mort
    Enemy_Type type; //Le type de l'ennemi

    float pos_X;
    float pos_Y; //Sa position qui va évoluée avec le temps
    int anim;  //Le suivie d'animation pour switch les sprites de l'ennemi
    int current_target;  // Le noeud à atteindre pour l'ennemi
    std::vector<int> path;  //La liste de tous les noeuds du graphe
    GLuint texture {0};  //Le contenant de texture de l'ennemi

    void enemy_apparition(img::Image image);  //méthode pour faire apparaître les sprites des ennemis sur la map quand ils arrivent
    bool alive(); //méthode qui permettra au jeu de vérifier simultanément si l'ennemi est toujours en vie ou mort
    img::Image enemy_animation();   //méthode pour faire les sprites animés des ennemis (ils marchent). Une partie de ce code est mis en commentaire car c'est un début pour une amélioration future
    void enemy_arrives();   //méthode pour changer le statut d'un ennemi lorsqu'il disparait par le portail sans se faire tuer par le joueur (il vit).
    void enemy_forward(const double time_elapse, const WeightedGraph& graph); //Méthode permettant de faire évoluer la position des ennemis durant leur marche dans la map
};
