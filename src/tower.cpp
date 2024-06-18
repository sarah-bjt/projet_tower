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


float time_to_wait {0.0f};  //Initialisation de la valeur qui permettra de faire un temps d'attente entre chaque balle tirée sur les ennemis

void Tower::tower_map_apparition(){  //méthode pour faire apparaitre les tours en fonction du type de tour
    if(this->type == Tower_Type::Wood){
        //Applique dans la case sélectionnée le sprite de la tour en bois
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
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos); //La taille des tours vont légèrement dépassé les 120.0f/720.0f d'une case

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
        //Applique dans la case sélectionnée le sprite de la tour en pierre
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
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos); //La taille des tours vont légèrement dépassé les 120.0f/720.0f d'une case

            glTexCoord2d(1,1);
            glVertex2f(this->x_pos+(170.0f/720.0f), this->y_pos+(170.0f/720.0f));

            glTexCoord2d(0,1);
            glVertex2f(this->x_pos, this->y_pos+(170.0f/720.0f));
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void Tower::tower_aiming(std::vector<Enemy>& enemys, Player& player){
    bool not_alive {false};// Ce booléen permettra de vérifier si un ennemi a été tuer par la tour, puis si c'est le cas de mettre à jour le player qu'on aura récupérer à l'appel de la fonction

    for(int i {0}; i<enemys.size(); i++){ 
        //verification des distances entre les ennemys et la tour en fonction de la distance de visée
        bool dist_X {(enemys[i].pos_X+((120.0f/720.0f)/2.0f) > this->x_pos+((120.0f/720.0f)/2.0f) - this->fire_distance*(120.0f/720.0f)) && (enemys[i].pos_X+((120.0f/720.0f)/2.0f) < this->x_pos+((120.0f/720.0f)/2.0f) + this->fire_distance*(120.0f/720.0f))};
        bool dist_Y {(enemys[i].pos_Y+((120.0f/720.0f)/2.0f) > this->y_pos+((120.0f/720.0f)/2.0f) - this->fire_distance*(120.0f/720.0f)) && (enemys[i].pos_Y+((120.0f/720.0f)/2.0f) < this->y_pos+((120.0f/720.0f)/2.0f) + this->fire_distance*(120.0f/720.0f))};  

        if(dist_X && dist_Y && enemys[i].enemy_id!=-1){  //Si l'ennemi se trouve dans la zone de tire et qu'il n'est pas déjà mort 
            if(time_to_wait >= this->fire_rythm || time_to_wait == 0.0f){ //Si la fin de la pause depuis le précédent tir a été atteinte. On peut connaitre le temps d'attente avec fire_rythm
                this->tower_fire(enemys[i]);  //On tire une balle sur l'ennemi détecté
                not_alive = !enemys[i].alive();  //On vérifie s'il est mort ou vivant

                if(not_alive){  //si l'ennemi est mort
                    enemys[i].enemy_id = -1;  //On change son statut en mort
                    player.increaseMoney(enemys[i].money_reward);  //On augmente l'argent (oeufs) du joueur en envoyant la valeur de l'ennemi (money_reward) à la méthode
                    if(enemys[i].type == Enemy_Type::Normal){  //Ensuite on augmente le score du joueur en fonction du type d'ennemi
                        player.increaseScore(1);
                    }
                    else {
                        player.increaseScore(2);
                    }
                    not_alive = false;  //On remet l'initialisation de la vérification pour les prochains ennemis
                }

                time_to_wait = 0.0f; //On remet le temps de pause à 0
            }
            time_to_wait += 0.01f;  //On incrémente le temps de pause
        }
    }
}

void Tower::tower_fire(Enemy& enemy){   //Cette méthode récupère l'ennemi visé
    this->bullet = Bullet{0.01f, 1.5f, this->x_pos+((120.0f/720.0f)/2.0f), this->y_pos+((120.0f/720.0f)/2.0f)}; //On créé une instance Bullet, initialiser aux positions de la tour à laquelle elle appartient
    this->bullet.bullet_fire(enemy, this->fire_power);  //On tire la balle en appelant la méthode bullet_fire de notre instance Bullet
}
