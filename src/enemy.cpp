#include "enemy.hpp"

#include "App.hpp"
#include "path.hpp"
#include "eventDispatcher.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include <iostream>
#include <sstream>
#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

void Enemy::enemy_apparition(img::Image image){  //Cette méthode permet de faire apparaitre les sprites des ennemis au fur et à mesure que leur position change
    if(this->enemy_id == -1 || this->enemy_id == -2) return; // si l'ennemi est mort ou est arrivé alors on ne fait rien.

    if(this->type == Enemy_Type::Robust){  // Si l'ennemi est de type robust, il aura une taille plus grande
        this->texture = loadTexture(image);
        glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, this->texture);
            glColor3ub(255, 255, 255);
            glBegin(GL_QUADS);
                glTexCoord2d(0,0);
                glVertex2f(this->pos_X, this->pos_Y);

                glTexCoord2d(1,0);
                glVertex2f(this->pos_X+(200.0f/720.0f), this->pos_Y);  // Donc la taille est de 200.0f/720.0f au lieu de 120.0f/720.0f

                glTexCoord2d(1,1);
                glVertex2f(this->pos_X+(200.0f/720.0f), this->pos_Y+(200.0f/720.0f));

                glTexCoord2d(0,1);
                glVertex2f(this->pos_X, this->pos_Y+(200.0f/720.0f));
            glEnd();
            glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    else {  //Sinon les autres types d'ennemis ont la même taille
        this->texture = loadTexture(image);
        glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, this->texture);
            glColor3ub(255, 255, 255);
            glBegin(GL_QUADS);
                glTexCoord2d(0,0);
                glVertex2f(this->pos_X, this->pos_Y);

                glTexCoord2d(1,0);
                glVertex2f(this->pos_X+(120.0f/720.0f), this->pos_Y);

                glTexCoord2d(1,1);
                glVertex2f(this->pos_X+(120.0f/720.0f), this->pos_Y+(120.0f/720.0f));

                glTexCoord2d(0,1);
                glVertex2f(this->pos_X, this->pos_Y+(120.0f/720.0f));
            glEnd();
            glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
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

img::Image Enemy::enemy_animation(){  //Cette méthode change la texture de l'ennemi en fonction d'un switch animation
    if(this->anim%20 >= 0 && this->anim%20 < 10){
        //Afficher le sprite d'animation n°1 avec this->pos_X et this->pos_Y
        if(this->type == Enemy_Type::Fast){
            //Applique dans la case sélectionnée le sprite de la ennemi fast
            img::Image fast_repos {img::load(make_absolute_path("images/images_objects/mash/mash2.png", true), 4, true)};
            this->anim++;
            return fast_repos;
        }
        else if(this->type == Enemy_Type::Normal){
            //Applique dans la case sélectionnée le sprite de la ennemi normal
            img::Image normal_repos {img::load(make_absolute_path("images/images_objects/bird/bird1.png", true), 4, true)};
            this->anim++;
            return normal_repos;
        }
        else if(this->type == Enemy_Type::Robust){
            //Applique dans la case sélectionnée le sprite de la ennemi robust
            img::Image robust_repos {img::load(make_absolute_path("images/images_objects/robust/ours2.png", true), 4, true)};
            this->anim++;
            return robust_repos;
        }
    }
//--------- CETTE PARTIE EST LE CODE D'AMELIORATION FUTUR POUR QUE LES ANIMATIONS SOIENT PLUS FLUIDES. ATTENTION LES FONCTIONS A LA SUITE DE CETTE PARTIE SONT NECESSAIRE POUR LE FONCTIONNEMENT DU PROJET.
        // LA SUITE UTILISEE EST DEJA DECOMMENTEE

        // else if(this->anim%110>10 && this->anim%110 <= 20){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash2.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird2.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours3.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 20 && this->anim%110 <= 30){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash3.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird3.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours2.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 30 && this->anim%110 <= 40){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash4.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird4.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours1.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 40 && this->anim%110 <= 50){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash5.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird5.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump1.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 50 && this->anim%110 <= 60){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash6.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird6.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump2.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 60 && this->anim%110 <= 70){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash1.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird7.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump3.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 70 && this->anim%110 <= 80){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash2.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird8.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump4.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 80 && this->anim%110 <= 90){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash3.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird9.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours_jump5.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }
        // else if(this->anim%110 > 90 && this->anim%110 < 100){
        //     if(this->type == Enemy_Type::Fast){
        //         //Applique dans la case sélectionnée le sprite de la ennemi fast
        //         img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash4.png", true), 4, true)};
        //         this->anim++;
        //         return fast_march;
        //     }
        //     else if(this->type == Enemy_Type::Normal){
        //         //Applique dans la case sélectionnée le sprite de la ennemi normal
        //         img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird10.png", true), 4, true)};
        //         this->anim++;
        //         return normal_march;
        //     }
        //     else if(this->type == Enemy_Type::Robust){
        //         //Applique dans la case sélectionnée le sprite de la ennemi robust
        //         img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours1.png", true), 4, true)};
        //         this->anim++;
        //         return robust_march;
        //     }
        // }

// ----------- C'EST LA FIN DU CODE D'AMELIORATION*

    else {
        if(this->type == Enemy_Type::Fast){
            //Applique dans la case sélectionnée le sprite de la ennemi fast
            img::Image fast_march {img::load(make_absolute_path("images/images_objects/mash/mash5.png", true), 4, true)};
            this->anim++;
            return fast_march;
        }
        else if(this->type == Enemy_Type::Normal){
            //Applique dans la case sélectionnée le sprite de la ennemi normal
            img::Image normal_march {img::load(make_absolute_path("images/images_objects/bird/bird11.png", true), 4, true)};
            this->anim++;
            return normal_march;
        }
        else if(this->type == Enemy_Type::Robust){
            //Applique dans la case sélectionnée le sprite de la ennemi robust
            img::Image robust_march {img::load(make_absolute_path("images/images_objects/robust/ours3.png", true), 4, true)};
            this->anim++;
            return robust_march;
        }
    }
}

void Enemy::enemy_arrives(){  //Cette méthode vérifie si les ennemis arrivent au dernier noeud, soit l'arrivée de la map
    int size {static_cast<int>(this->path.size())-1};       
    if(this->current_target > size){      // le 1 c'est le noeud qui indique la fin
        this->enemy_id = -2;            // le -2 indique que l'ennemi a attain la fin
        EventDispatcher::instance().enemy_happen(enemy_id);  // Cette méthode va faire apparaitre le message de game over si un seul ennemi arrive à passer
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Enemy::enemy_forward(const double time_elapse, const WeightedGraph& graph){  //Cette méthode fait avancer les ennemis à partir d'un graphe, et d'un temps donné. Elle fait appel à enemy_apparition
    if(this->enemy_id == -1 || this->enemy_id == -2) return;  // si l'ennemi est mort ou est arrivé alors on ne fait rien.

    if (this->path.empty() || this->current_target >= this->path.size()) return;  // Si le chemin est vide ou l'ennemi a atteint la fin du chemin

    int target_node = this->path[this->current_target];
    std::pair<float, float> target_position = get_node_position(target_node, graph);  //On récupère le numéro du prochain noeud du graphe à atteindre

    float dist_x = target_position.first - this->pos_X;
    float dist_y = target_position.second - this->pos_Y;
    float distance = sqrt(dist_x * dist_x + dist_y * dist_y);  //On calcule la distance entre l'ennemi et la prochaine destination

    if (distance < this->speed * time_elapse) {  // Si l'ennemi atteint le nœud cible
        this->pos_X = target_position.first;
        this->pos_Y = target_position.second;  //Alors on met à jour la position de l'ennemi pour pouvoir calculer le prochain calcul de vecteur, pour la prochaine direction
        this->current_target++;
    } else {
        this->pos_X += this->speed * time_elapse * (dist_x / distance);  //Sinon on continue à déplacer notre ennemi vers le noeud cible
        this->pos_Y += this->speed * time_elapse * (dist_y / distance);
    }

    this->enemy_apparition(this->enemy_animation()); //Apelle la méthode d'apparition de l'ennemi, en faisant appel à la méthode d'animation pour switcher les sprites
}
