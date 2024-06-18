#pragma once

class EventDispatcher {
public:
    EventDispatcher();
    ~EventDispatcher();

    static EventDispatcher& instance();

    void enemyReachedEnd(int enemyId);
    bool isGameOver() const; // Déclaration de la fonction pour vérifier si le jeu est terminé

    // Autres méthodes pour d'autres événements liés au jeu

private:
    bool game_over_flag = false;

    // Méthodes ou structures de données pour gérer les abonnements aux événements, si nécessaire
};
