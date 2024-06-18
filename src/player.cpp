#include "player.hpp"

#include <iostream>

void Player::increaseMoney(int reward){
    this->money += reward; // Si un ennemi est tué, le reward est ajouté à la somme d'argent
}

void Player::decreaseMoney(int price){
    this->money -= price; // Si un achat est effectué, le prix est soustrait à la somme d'argent
}

void Player::increaseScore(int new_score){
    this->score += new_score; // Si un ennemi est tué, les points de récompenses sont ajouté au score total
}