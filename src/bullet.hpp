#pragma once

struct Bullet{
    int size;  //Taille de la bullet
    float speed;
    //une instance qui contiendra le dessin de la balle

    void bullet_draw(); //méthode pour dessiner la balle
    void bullet_fire(float pos_X, float pos_Y); //méthode qui récupère la position/direction de l'ennemi et fais bouger la balle
    void bullet_disappear();  //méthode qui contiendra la condition que la position soit atteinte pour faire disparaitre le dessin
};