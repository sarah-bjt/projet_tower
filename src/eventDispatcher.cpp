#include "eventDispatcher.hpp"
#include <iostream>

// Constructeur par défaut de la classe EventDispatcher.
EventDispatcher::EventDispatcher() {}

// Destructeur par défaut de la classe EventDispatcher.
EventDispatcher::~EventDispatcher() {}

// Méthode statique pour accéder à l'unique instance de la classe EventDispatcher.
EventDispatcher& EventDispatcher::instance() {
    // Déclare une variable statique locale nommée 'instance' de type EventDispatcher.
    // La première fois que cette ligne est exécutée, l'objet 'instance' est créé et initialisé.
    // Les fois suivantes, cette ligne n'est pas réexécutée ; l'objet 'instance' déjà créé est utilisé.
    static EventDispatcher instance;

    // Retourne une référence à l'objet 'instance'.
    // Cela permet d'accéder à la même instance de EventDispatcher à chaque appel de la méthode 'instance'.
    return instance;
}

// indique si la partie est perdu ou gagné
void EventDispatcher::enemy_happen(int enemyId) {
    if (enemyId == -2) {  // Vérifier si l'ennemi a atteint la fin du parcours
        game_over_flag = true;
    }
    else if (enemyId == -1){ // Vérifier si tous les ennemis sont mort
        game_won_flag = true;
    }
}

bool EventDispatcher::isGameOver() const {
    return game_over_flag;
}

bool EventDispatcher::isGameWon() const {
    return game_won_flag;
}
