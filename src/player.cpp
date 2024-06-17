#include "player.hpp"

#include "enemy.hpp"
#include <iostream>

std::string Player::chooseName()
{
    std::cout << "Entrez un nom : " << std::endl;
    std::cin >> name;
    return name;
};

// // int Player::increaseMoney()
// // {
// //     if() //Si tel ennemi est tué vous gagnez tant de points
// //     {
// //         money+=5;
// //     }
// // };

// // int Player::increaseScore()
// // {
// //     if() //si tel ennemi est tué vous gagnez tant de points
// //     {
// //         score+=1;
// //     }
// // };