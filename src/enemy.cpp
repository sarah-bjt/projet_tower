#include <iostream>
#include "enemy.hpp"

void Enemy::enemy_apparition(int x_origin, int y_origin){  
    if(this->type == Enemy_Type::Fast){
        //Applique dans la case sélectionnée le sprite de la ennemi fast
        std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
    }
    else if(this->type == Enemy_Type::Normal){
        //Applique dans la case sélectionnée le sprite de la ennemi normal
        std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
    }
    else if(this->type == Enemy_Type::Robust){
        //Applique dans la case sélectionnée le sprite de la ennemi robust
        std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
    }
}

bool Enemy::alive(){   //cette méthode vérifie les points de vie des ennemis
    if(this->life > 0){  //si les points de vie sont au dessus de 0
        return true;  //alors il est toujours vivant (donc true)
    }
    else {
        return false;  //sinon il est mort (donc false)
    }
}

void Enemy::enemy_animation(){  
    int switch_sprite {0};
    while(this->alive()){
        if(switch_sprite%2 == 0){
            //Afficher le sprite d'animation n°1 avec this->pos_X et this->pos_Y
        }
        else {
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
        }
    }
}

void Enemy::enemy_death(){
    if(!this->alive()){
        //Faire disparaitre le sprite de l'ennemi à tout jamais (ça va faire un trou dans la vague d'ennemi et c'est normal)
        //Et faire augmenter le score du joueur
    }
}

void Enemy::enemy_arrives(){   //on va devoir relier à Party.cpp/.hpp (position d'apparition des ennemis, position de la sortie à protéger)
    //if(this->pos_X == (la position X de la sortie) && this->pos_Y == (la position Y de la sortie)){ --> ça ce sera plutôt dans une autre fonction qui fera appel à celle là
        //faire disparaitre le sprite de l'ennemi sans faire augmenter le score du joueur
}