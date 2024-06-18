#pragma once

#include "tower.hpp"
#include "enemy.hpp"
#include "wave.hpp"
#include "map.hpp"
#include "App.hpp"

struct Game{
public :
    std::vector<Tower> all_towers {};  //En fait ce serait un tableau de tower
    std::vector<Wave> waves {}; //(enemy dans wave...)
    Map map; //pour faire apparaitre la map
    Player player;

    //méthode pour créer le jeu
    void create_game(std::string player_name);
    //méthode pour commencer le jeu et utiliser toutes les autres méthodes des autres struct
    void start();
    void update(int player_action,std::pair<double, double> mouse_position);

    // Indicateur pour savoir si le jeu est terminé
    void set_game_over_flag(bool flag) {game_over_flag = flag;};
    bool is_game_over() const {return game_over_flag;};

private:
    bool game_over_flag = false;  // Indicateur pour savoir si le jeu est terminé
};

