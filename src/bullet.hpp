#pragma once
#include "enemy.hpp"

struct Bullet{
    float size;  //Taille de la bullet
    float speed; //vitesse de la bullet
    float X, Y;  //La position du centre de la balle
    float _directX, _directY;  //Instances permettant de calculer la direction vers laquelle la balle doit aller

    void bullet_draw(); //méthode pour dessiner la balle, que l'on va laisser en commentaire car ça serait une amélioration pour plus tard
    void bullet_fire(Enemy& enemy, int power_impact); //méthode qui récupère la position/direction de l'ennemi et fais bouger la balle
    void bullet_disappear();  //méthode pour faire disparaitre le dessin, que l'on va laisser en commentaire car ça serait une amélioration pour plus tard
};
