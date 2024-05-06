#pragma once

enum class Enemy_Type {
    Fast,
    Normal,
    Robust
};

struct Enemy{
    int enemy_id; //identifiant de l'ennemi
    int life;  // Les points de vie d'un ennemi
    int speed;  // La vitesse en cases d'un ennemi
    int money_reward;   // La récompense en argent qu'un ennemi rapporte au joueur une fois mort
    Enemy_Type type; //Le type de l'ennemi

    int pos_X;
    int pos_Y; //Sa position qui va évoluée avec le temps

    //Wave wave;
    void enemy_apparition(int x_origin, int y_origin);  //méthode pour faire apparaître les sprites des ennemis sur la map quand ils arrivent
    bool alive(); //méthode qui permettra au jeu de vérifier simultanément si l'ennemi est toujours en vie ou mort
    void enemy_animation();   //méthode pour faire les sprites animés des ennemis (ils marchent)
    void enemy_death();   //méthode pour compter lorsqu'un ennemi est mort dû au joueur, et faire augmenter l'argent du joueur en fonction de money_reward
    void enemy_arrives();   //méthode pour comptabiliser lorsqu'un ennemi disparait par le portail sans se faire tuer par le joueur (il vit).
};