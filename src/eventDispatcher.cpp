#include "eventDispatcher.hpp"
#include <iostream>

EventDispatcher::EventDispatcher() {}

EventDispatcher::~EventDispatcher() {}

EventDispatcher& EventDispatcher::instance() {
    static EventDispatcher instance;
    return instance;
}

void EventDispatcher::enemy_happen(int enemyId) {
    if (enemyId == -2) {  // Vérifier si l'ennemi a atteint la fin du parcours
        game_over_flag = true;
    }
    else if (enemyId == -1){
        game_won_flag = true;
    }
}

bool EventDispatcher::isGameOver() const {
    return game_over_flag;
}

bool EventDispatcher::isGameWon() const {
    return game_won_flag;
}
