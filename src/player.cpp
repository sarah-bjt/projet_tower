#include <iostream>
#include "player.hpp"
#include "enemy.hpp"


// std::string Player::chooseName()
// {
//     std::cout << "Entrez un nom : " << std::endl;
//     std::cin >> name;
// };

// int Player::increaseMoney()
// {
//     if() //Si tel ennemi est tué vous gagnez tant de points
//     {
//         money+=5;
//     }
// };
<<<<<<< HEAD

int Player::buy()
{
    if(money > price) //Si votre qté d'argent est >= au prix, vous pouvez l'acheter et on retire la qté d'argent de notre somme d'argent
    {
        money-= price;
    }
    else 
    {
        std::cout << "Vous n'avez pas assez d'argent" << std::endl;
    }
};
=======
// // 
// int Player::buy()
// {
//     if() //Si votre qté d'argent est >= au prix, vous pouvez l'acheter et on retire la qté d'argent de notre somme d'argent
//     {
//         money-=
//     }
//     else 
//     {
//         std::cout << "Vous n'avez pas assez d'argent" << std::endl;
//     }
// };
>>>>>>> dbff94099c6b608263d88d6dfe972891b9278e47

// int Player::increaseScore()
// {
//     if() //si tel ennemi est tué vous gagnez tant de points
//     {
//         score+=1;
//     }
<<<<<<< HEAD
// };

void addTower(const Tower_Type& tower)
{
    towers.push_back(tower);
}
=======
// };
>>>>>>> dbff94099c6b608263d88d6dfe972891b9278e47
