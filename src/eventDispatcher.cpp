#include "eventDispatcher.hpp"
#include <iostream>

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {}

EventDispatcher& EventDispatcher::instance() {
    static EventDispatcher instance;
    return instance;
}

void EventDispatcher::enemyReachedEnd(int enemyId) {
    if (enemyId == -2) {  // Vérifier si l'ennemi a atteint la fin du parcours
        game_over_flag = true;

        // Vous pouvez également déclencher d'autres actions lorsque le jeu est terminé
        std::cout << "Game Over!" << std::endl;
    }
}

bool EventDispatcher::isGameOver() const {
    return game_over_flag;
}
