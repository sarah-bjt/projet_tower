#include "player.hpp"

#include <iostream>

void Player::increaseMoney(int reward){
    this->money += reward;
}

void Player::decreaseMoney(int price){
    this->money -= price;
}

void Player::increaseScore(int new_score){
    this->score += new_score;
}