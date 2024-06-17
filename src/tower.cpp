#include "tower.hpp"

#include "bullet.hpp"
#include "wave.hpp"
#include "enemy.hpp"
#include <vector>

#include "App.hpp"

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include <iostream>
#include <sstream>
#include "simpletext.h"


float time_to_wait {0.0f};

const int window_width = 1280;
const int window_height = 720;

void Tower::tower_map_apparition(){   //prend en paramètres les coordonées du coin gauche/haut de la case où la tour devra se construire
    if(this->type == Tower_Type::Wood){
        //Applique dans la case sélectionnée le sprite de la tour wood
        //std::cout << "La tour de type Wood sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
        img::Image wood_tower {img::load(make_absolute_path("images/images_objects/wood_tower.png", true), 4, true)};
    
        glPushMatrix();

        GLuint wood_tower_texture = loadTexture(wood_tower);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, wood_tower_texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->x_pos, this->y_pos);

            glTexCoord2d(1,0);
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos);

            glTexCoord2d(1,1);
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos+(170.0f/720.0f));

            glTexCoord2d(0,1);
            glVertex2f(this->x_pos, this->y_pos+(170.0f/720.0f));
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    else if(this->type == Tower_Type::Rock){
        //Applique dans la case sélectionnée le sprite de la tour rock
        //std::cout << "La tour de type Rock sera positionnée à : X=" << x_box << " et Y=" << y_box << std::endl;
        img::Image rock_tower {img::load(make_absolute_path("images/images_objects/rock_tower.png", true), 4, true)};
    
        glPushMatrix();

        GLuint rock_tower_texture = loadTexture(rock_tower);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, rock_tower_texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->x_pos, this->y_pos);

            glTexCoord2d(1,0);
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos);

            glTexCoord2d(1,1);
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos+(170.0f/720.0f));

            glTexCoord2d(0,1);
            glVertex2f(this->x_pos, this->y_pos+(170.0f/720.0f));
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

void Tower::tower_aiming(std::vector<Enemy>& enemys){
    bool not_alive {false};
    //il faudra que je sois relié à wave pour avoir un tableau de Enemy
    for(int i {0}; i<enemys.size(); i++){ 
        bool dist_X {(enemys[i].pos_X+((120.0f/720.0f)/2.0f) > this->x_pos+((120.0f/720.0f)/2.0f) - this->fire_distance*(120.0f/720.0f)) && (enemys[i].pos_X+((120.0f/720.0f)/2.0f) < this->x_pos+((120.0f/720.0f)/2.0f) + this->fire_distance*(120.0f/720.0f))};
        bool dist_Y {(enemys[i].pos_Y+((120.0f/720.0f)/2.0f) > this->y_pos+((120.0f/720.0f)/2.0f) - this->fire_distance*(120.0f/720.0f)) && (enemys[i].pos_Y+((120.0f/720.0f)/2.0f) < this->y_pos+((120.0f/720.0f)/2.0f) + this->fire_distance*(120.0f/720.0f))};  //verif des distances pour les ennemys dans le périmètre de la tour
        if(dist_X && dist_Y && enemys[i].enemy_id!=-1){  //Si l'ennemi se trouve dans la zone de tire et qu'il n'est pas déjà mort 
            if(time_to_wait >= this->fire_rythm || time_to_wait == 0.0f){
                std::cout << "a capté" << std::endl;
                this->tower_fire(enemys[i]);
                not_alive = !enemys[i].alive(this->bullet.X, this->bullet.Y, this->fire_power);

                if(not_alive){  //si l'ennemi est mort et qu'il n'est pas DEJA mort alors on change son statut en mort
                    enemys[i].enemy_id = -1;
                    not_alive = false;
                }

                time_to_wait = 0.0f;
            }
            time_to_wait += 0.01f;
        }
    }
    //on récupère la position de chaque ennemi de la vague (tableau)
    //on calcule la distance entre leur position et celle de la tour
}

void Tower::tower_fire(Enemy& enemy){
    this->bullet = Bullet{0.01f, 1.5f, this->x_pos+((120.0f/720.0f)/2.0f), this->y_pos+((120.0f/720.0f)/2.0f)}; //, 0.0f, 0.0f
    this->bullet.bullet_fire(enemy);
}

// LES DEUX FONCTIONS PRÉCÉDENTES DEVRONT ÊTRE UTILISÉES DANS UN WHILE DANS GAME.CPP OU PARTY.CPP ...