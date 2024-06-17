#include "player.hpp"

#include "enemy.hpp"
#include <iostream>

void Player::increaseMoney(int reward){
    this->money += reward;
}

// // int Player::increaseScore()
// // {
// //     if() //si tel ennemi est tué vous gagnez tant de points
// //     {
// //         score+=1;
// //     }
// // };