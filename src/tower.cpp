#include <iostream>
#include "tower.hpp"
#include "bullet.hpp"

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"


const int window_width = 1280;
const int window_height = 720;

void Tower::tower_map_apparition(int x_box, int y_box){   //prend en paramètres les coordonées du coin gauche/haut de la case où la tour devra se construire
    if(this->type == Tower_Type::Wood){
        //Applique dans la case sélectionnée le sprite de la tour wood
        std::cout << "La tour de type Wood sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    }
    else if(this->type == Tower_Type::Rock){
        //Applique dans la case sélectionnée le sprite de la tour rock
        std::cout << "La tour de type Rock sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    }
    else if(this->type == Tower_Type::Long_ranged){
        //Applique dans la case sélectionnée le sprite de la tour long_ranged
        std::cout << "La tour de type Long_ranged sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    }
    else if(this->type == Tower_Type::Short_ranged){
        //Applique dans la case sélectionnée le sprite de la tour short_ranged
        std::cout << "La tour de type Short_ranged sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    }
}

void Tower::tower_interface_apparition(){    //peut être qu'au final on aura pas besoin de cette méthode
    //Applique définitivement les sprites de chaque tower dans la boutique de l'interface
}

void Tower::tower_aiming(){
    //il faudra que je sois relié à wave pour avoir un tableau de Enemy
    //on résupère la position de chaque ennemi de la vague (tableau)
    //on calcule la distance entre leur position et celle de la tour
    if(true){  //si la distance est <= à fire_distance
        this->tower_fire(13, 45);  //on appelle la fonction qui tire les bullet, en référant la position de l'enemi visé
    }
}

void Tower::tower_fire(int x_pos_enemy, int y_pos_enemy){
    //on va utiliser le (tableau) bullet
    //utiliser une méthode d'animation de la struct Bullet pour la lancer
}

// LES DEUX FONCTIONS PRÉCÉDENTES DEVRONT ÊTRE UTILISÉES DANS UN WHILE DANS GAME.CPP OU PARTY.CPP ...