#pragma once

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

#include "path.hpp"
#include <vector>

enum class Enemy_Type {
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
    int anim;
    int current_target;
    std::vector<int> path;
    GLuint texture {0};

    //Wave wave;
    void enemy_apparition(img::Image image);  //méthode pour faire apparaître les sprites des ennemis sur la map quand ils arrivent
    bool alive(float bullet_x, float bullet_y, int power_impact); //méthode qui permettra au jeu de vérifier simultanément si l'ennemi est toujours en vie ou mort
    img::Image enemy_animation();   //méthode pour faire les sprites animés des ennemis (ils marchent)
    bool enemy_death(float bullet_x, float bullet_y, int power_impact);   //méthode pour compter lorsqu'un ennemi est mort dû au joueur, et faire augmenter l'argent du joueur en fonction de money_reward
    void enemy_arrives();   //méthode pour comptabiliser lorsqu'un ennemi disparait par le portail sans se faire tuer par le joueur (il vit).
    void enemy_forward(const double time_elapse, const WeightedGraph& graph); //, bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT
    // ça c'est la fonction qui va permettre que les ennemis prennent la même directions sans pour autant agir en bloc
};