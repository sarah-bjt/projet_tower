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

void Tower::tower_map_apparition(){   //prend en paramètres les coordonées du coin gauche/haut de la case où la tour devra se construire
    if(this->type == Tower_Type::Wood){
        //Applique dans la case sélectionnée le sprite de la tour wood
        //std::cout << "La tour de type Wood sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
        img::Image wood_tower {img::load(make_absolute_path("images/images_objects/wood_tower.png", true), 3, true)};
    
        glPushMatrix();

        GLuint wood_tower_texture = loadTexture(wood_tower);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, wood_tower_texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->x_pos, this->y_pos);

            glTexCoord2d(1,0);
            glVertex2f(this->x_pos+0.2f, this->y_pos);

            glTexCoord2d(1,1);
            glVertex2f(this->x_pos+0.2f, this->y_pos+0.2f);

            glTexCoord2d(0,1);
            glVertex2f(this->x_pos, this->y_pos+0.2f);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    else if(this->type == Tower_Type::Rock){
        //Applique dans la case sélectionnée le sprite de la tour rock
        //std::cout << "La tour de type Rock sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
        img::Image rock_tower {img::load(make_absolute_path("images/images_objects/rock_tower.png", true), 3, true)};
    
        glPushMatrix();

        GLuint rock_tower_texture = loadTexture(rock_tower);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, rock_tower_texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->x_pos, this->y_pos);

            glTexCoord2d(1,0);
            glVertex2f(this->x_pos+0.2f, this->y_pos);

            glTexCoord2d(1,1);
            glVertex2f(this->x_pos+0.2f, this->y_pos+0.2f);

            glTexCoord2d(0,1);
            glVertex2f(this->x_pos, this->y_pos+0.2f);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    // else if(this->type == Tower_Type::Long_ranged){
    //     //Applique dans la case sélectionnée le sprite de la tour long_ranged
    //     std::cout << "La tour de type Long_ranged sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    // }
    // else if(this->type == Tower_Type::Short_ranged){
    //     //Applique dans la case sélectionnée le sprite de la tour short_ranged
    //     std::cout << "La tour de type Short_ranged sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
    // }
}

void Tower::tower_interface_apparition(){    //peut être qu'au final on aura pas besoin de cette méthode
    //Applique définitivement les sprites de chaque tower dans la boutique de l'interface
}

void Tower::tower_aiming(){
    //il faudra que je sois relié à wave pour avoir un tableau de Enemy
    //on récupère la position de chaque ennemi de la vague (tableau)
    //on calcule la distance entre leur position et celle de la tour
    if(true){  //si la distance est <= à fire_distance
        this->tower_fire(13, 45);  //on appelle la fonction qui tire les bullet, en référant la position de l'enemi visé
    }
}

void Tower::tower_fire(int x_pos_enemy, int y_pos_enemy){
    //on va utiliser le (tableau) bullet
    //utiliser une méthode d'animation de la struct Bullet pour la lancer
    this->bullet = Bullet{0.01f, 0.5f, 0.0f, 0.0f};
    this->bullet.bullet_fire(-0.5f, 0.5f);
}

// LES DEUX FONCTIONS PRÉCÉDENTES DEVRONT ÊTRE UTILISÉES DANS UN WHILE DANS GAME.CPP OU PARTY.CPP ...