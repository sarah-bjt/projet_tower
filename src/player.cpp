#include "player.hpp"

#include "enemy.hpp"
#include <iostream>

void Player::increaseMoney(int reward){
    this->money += reward;
}

void Player::decreaseMoney(int price){
    this->money -= price;
}

// // int Player::increaseScore()
// // {
// //     if() //si tel ennemi est tué vous gagnez tant de points
// //     {
// //         score+=1;
// //     }
// // };