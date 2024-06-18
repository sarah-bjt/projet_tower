#pragma once

class EventDispatcher {
public:
    EventDispatcher();
    ~EventDispatcher();

    static EventDispatcher& instance();

    void enemy_happen(int enemyId);
    bool isGameOver() const; // Déclaration de la fonction pour vérifier si le jeu est perdu
    bool isGameWon() const;  // Déclaration de la fonction pour vérifier si le jeu est gagné

private:
    bool game_over_flag = false;
    bool game_won_flag = false;

};
