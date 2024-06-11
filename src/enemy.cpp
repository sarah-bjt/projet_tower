#include <iostream>
#include "enemy.hpp"

#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

void Enemy::enemy_apparition(){  
    if(!this->texture ==0) return;

    if(this->type == Enemy_Type::Fast){
        //Applique dans la case sélectionnée le sprite de la ennemi fast
        //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
        img::Image fast_repos {img::load(make_absolute_path("images/images_objects/robust/robust_repos.png", true), 3, true)};
    
        glPushMatrix();
        //glTranslatef(pos_X, pos_Y,0.0f);

        this->texture = loadTexture(fast_repos);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->pos_X, this->pos_Y);

            glTexCoord2d(1,0);
            glVertex2f(this->pos_X+0.2f, this->pos_Y);

            glTexCoord2d(1,1);
            glVertex2f(this->pos_X+0.2f, this->pos_Y+0.2f);

            glTexCoord2d(0,1);
            glVertex2f(this->pos_X, this->pos_Y+0.2f);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    else if(this->type == Enemy_Type::Normal){
        //Applique dans la case sélectionnée le sprite de la ennemi normal
        //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
        img::Image normal_repos {img::load(make_absolute_path("images/images_objects/robust/robust_repos.png", true), 3, true)};
    
        glPushMatrix();

        this->texture = loadTexture(normal_repos);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->pos_X, this->pos_Y);

            glTexCoord2d(1,0);
            glVertex2f(this->pos_X+0.2f, this->pos_Y);

            glTexCoord2d(1,1);
            glVertex2f(this->pos_X+0.2f, this->pos_Y+0.2f);

            glTexCoord2d(0,1);
            glVertex2f(this->pos_X, this->pos_Y+0.2f);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    else if(this->type == Enemy_Type::Robust){
        //Applique dans la case sélectionnée le sprite de la ennemi robust
        //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
        img::Image robust_repos {img::load(make_absolute_path("images/images_objects/robust/robust_repos.png", true), 3, true)};
    
        glPushMatrix();

        this->texture = loadTexture(robust_repos);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
            glTexCoord2d(0,0);
            glVertex2f(this->pos_X, this->pos_Y);

            glTexCoord2d(1,0);
            glVertex2f(this->pos_X+0.2f, this->pos_Y);

            glTexCoord2d(1,1);
            glVertex2f(this->pos_X+0.2f, this->pos_Y+0.2f);

            glTexCoord2d(0,1);
            glVertex2f(this->pos_X, this->pos_Y+0.2f);
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

bool Enemy::alive(float bullet_x, float bullet_y, int power_impact){   //cette méthode vérifie les points de vie des ennemis
    if(bullet_x < this->pos_X+0.02f && bullet_y > this->pos_Y-0.02f){
        this->life -= power_impact;
    }
    std::cout << this->life << std::endl;
    if(this->life > 0){  //si les points de vie sont au dessus de 0
        return true;  //alors il est toujours vivant (donc true)
    }
    else {
        return false;  //sinon il est mort (donc false)
    }
}

void Enemy::enemy_animation(float bullet_x, float bullet_y, int power_impact){  
    int switch_sprite {0};
    while(this->alive(bullet_x, bullet_y, power_impact)){
        if(switch_sprite%2 == 0){
            //Afficher le sprite d'animation n°1 avec this->pos_X et this->pos_Y
        }
        else {
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
        }
    }
}

void Enemy::enemy_death(float bullet_x, float bullet_y, int power_impact){
    if(!this->alive(bullet_x, bullet_y, power_impact)){
        std::cout << "MORT" << std::endl;
        
        glDeleteTextures(1, &this->texture);
        this->texture = 0;

        //Faire disparaitre le sprite de l'ennemi à tout jamais (ça va faire un trou dans la vague d'ennemi et c'est normal)
        //Et faire augmenter le score du joueur
    }
}

void Enemy::enemy_arrives(){   //on va devoir relier à Party.cpp/.hpp (position d'apparition des ennemis, position de la sortie à protéger)
    //if(this->pos_X == (la position X de la sortie) && this->pos_Y == (la position Y de la sortie)){ --> ça ce sera plutôt dans une autre fonction qui fera appel à celle là
        //faire disparaitre le sprite de l'ennemi sans faire augmenter le score du joueur
}

void Enemy::enemy_forward(const double time_elapse, bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT){
    if(!this->texture == 0) return;

    if(horizontal && !vertical){   // Vérifie les directions demandées pour toute la vague d'ennemis
        if(RIGHT && !LEFT){
            this->pos_X+=this->speed*time_elapse;  //modifie la position de l'ennemi directement en ajoutant le temps direct multiplié par la vitesse de l'ennemi.
            this->enemy_apparition();  //Apelle la méthode d'apparition de l'ennemi
        }
        else if(!RIGHT && LEFT){
            this->pos_X-=this->speed*time_elapse;
            this->enemy_apparition();
        }
    }
    else if(!horizontal && vertical){
        if(UP && !DOWN){
            this->pos_Y+=this->speed*time_elapse;
            this->enemy_apparition();
        }
        else if(!UP && DOWN){
            this->pos_Y-=this->speed*time_elapse;
            this->enemy_apparition();
        }
    }
}