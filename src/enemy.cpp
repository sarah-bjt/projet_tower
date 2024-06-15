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

void Enemy::enemy_apparition(img::Image image){
    if(this->enemy_id == -1 || this->enemy_id == -2) return;  

    this->texture = loadTexture(image);
    glPushMatrix();
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

bool Enemy::alive(float bullet_x, float bullet_y, int power_impact){   //cette méthode vérifie les points de vie des ennemis
    if(bullet_x < this->pos_X+0.02f && bullet_y > this->pos_Y-0.02f){
        this->life -= power_impact;
    }
    //std::cout << this->life << std::endl;
    if(this->life > 0){  //si les points de vie sont au dessus de 0
        return true;  //alors il est toujours vivant (donc true)
    }
    else {
        return false;  //sinon il est mort (donc false)
    }
}

img::Image Enemy::enemy_animation(){  
    if(this->enemy_id != -1 && this->enemy_id != -2){
        if(this->anim%50 >= 0 && this->anim%50 <= 10){
            //Afficher le sprite d'animation n°1 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_repos {img::load(make_absolute_path("images/images_objects/mash/mash1.png", true), 4, true)};
                this->anim++;
                return fast_repos;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_repos {img::load(make_absolute_path("images/images_objects/bird/bird1.png", true), 4, true)};
                this->anim++;
                return normal_repos;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_repos {img::load(make_absolute_path("images/images_objects/robust/robust_repos.png", true), 4, true)};
                this->anim++;
                return robust_repos;
            }
        }
        else if(this->anim%50>10 && this->anim%50 <= 20){
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash2.png", true), 4, true)};
                this->anim++;
                return fast_march;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird2.png", true), 4, true)};
                this->anim++;
                return normal_march;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours3.png", true), 4, true)};
                this->anim++;
                return robust_march;
            }
        }
        else if(this->anim%50 > 20 && this->anim%50 <= 30){
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash3.png", true), 4, true)};
                this->anim++;
                return fast_march;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird3.png", true), 4, true)};
                this->anim++;
                return normal_march;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours2.png", true), 4, true)};
                this->anim++;
                return robust_march;
            }
        }
        else if(this->anim%50 > 30 && this->anim%50 <= 40){
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash4.png", true), 4, true)};
                this->anim++;
                return fast_march;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird4.png", true), 4, true)};
                this->anim++;
                return normal_march;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours1.png", true), 4, true)};
                this->anim++;
                return robust_march;
            }
        }
        else if(this->anim%50 > 40 && this->anim%50 <= 50){
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash5.png", true), 4, true)};
                this->anim++;
                return fast_march;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird5.png", true), 4, true)};
                this->anim++;
                return normal_march;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump1.png", true), 4, true)};
                this->anim++;
                return robust_march;
            }
        }
        else {
            //Afficher le sprite d'animation n°2 avec this->pos_X et this->pos_Y
            if(this->type == Enemy_Type::Fast){
                //Applique dans la case sélectionnée le sprite de la ennemi fast
                //std::cout << "L'ennemi de type fast sera positionnée à la position initiale donnée " << std::endl;
                img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash6.png", true), 4, true)};
                this->anim++;
                return fast_march;
            }
            else if(this->type == Enemy_Type::Normal){
                //Applique dans la case sélectionnée le sprite de la ennemi normal
                //std::cout << "L'ennemi de type normal sera positionnée à la position initiale donnée " << std::endl;
                img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird6.png", true), 4, true)};
                this->anim++;
                return normal_march;
            }
            else if(this->type == Enemy_Type::Robust){
                //Applique dans la case sélectionnée le sprite de la ennemi robust
                //std::cout << "L'ennemi de type robust sera positionnée à la position initiale donnée " << std::endl;
                img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump2.png", true), 4, true)};
                this->anim++;
                return robust_march;
            }
        }
    }
}

bool Enemy::enemy_death(float bullet_x, float bullet_y, int power_impact){
    if(!this->alive(bullet_x, bullet_y, power_impact)){
        std::cout << "MORT" << std::endl;
        return true;
        //Faire disparaitre le sprite de l'ennemi à tout jamais (ça va faire un trou dans la vague d'ennemi et c'est normal)
        //Et faire augmenter le score du joueur
        // CODE A IMPLEMENTER QUAND J'AURAIS LE FCIHIER JOUEUR :
        /*
        player.money += this->money_reward;  //en utilisant la méthode increaseMoney()
        if(this->type == Enemy_Type::Fast){
            player.score += 2;  //en utilisant la méthode increaseScore()
        }
        else if(this->type == Enemy_Type::Robust){
            player.score += 3;
        }
        else {
            player.score += 1;
        }
        */
    }

    return false;
}

bool Enemy::enemy_arrives(){   //on va devoir relier à Party.cpp/.hpp (position d'apparition des ennemis, position de la sortie à protéger)
    //conditions exemple mais faudra aller les chercher dans les infos de path, party, levels...
    if(this->pos_Y+0.1f <= -0.5f){ //this->pos_X+0.1f >= 0.5f, --> ça ce sera plutôt dans une autre fonction qui fera appel à celle là
        std::cout << "arrivé" << std::endl;
        return true;
    }
    return false;
    //faire disparaitre le sprite de l'ennemi sans faire augmenter le score du joueur
}

void Enemy::enemy_forward(const double time_elapse, bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT){
    if(this->enemy_id == -1 || this->enemy_id == -2) return;  

    if(horizontal && !vertical){   // Vérifie les directions demandées pour toute la vague d'ennemis
        if(RIGHT && !LEFT){
            this->pos_X+=this->speed*time_elapse;  //modifie la position de l'ennemi directement en ajoutant le temps direct multiplié par la vitesse de l'ennemi.  
        }
        else if(!RIGHT && LEFT){
            this->pos_X-=this->speed*time_elapse;
        }
    }
    else if(!horizontal && vertical){
        if(UP && !DOWN){
            this->pos_Y+=this->speed*time_elapse;
        }
        else if(!UP && DOWN){
            this->pos_Y-=this->speed*time_elapse;
        }
    }
    this->enemy_apparition(this->enemy_animation()); //Apelle la méthode d'apparition de l'ennemi
}