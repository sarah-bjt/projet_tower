#include <iostream>
#include "player.hpp"
#include "enemy.hpp"


std::string Player::chooseName()
{
    std::cout << "Entrez un nom : " << std::endl;
    std::cin >> name;
};

int Player::increaseMoney()
{
    if() //Si tel ennemi est tué vous gagnez tant de points
    {
        money+=5;
    }
};
// 
int Player::buy()
{
    if() //Si votre qté d'argent est >= au prix, vous pouvez l'acheter et on retire la qté d'argent de notre somme d'argent
    {
        money-=
    }
    else 
    {
        std::cout << "Vous n'avez pas assez d'argent" << std::endl;
    }
};

int Player::increaseScore()
{
    if() //si tel ennemi est tué vous gagnez tant de points
    {
        score+=1;
    }
};