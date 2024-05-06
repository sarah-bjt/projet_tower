#pragma once

enum class Tower_Type {
    Wood,
    Rock,
    Long_ranged,
    Short_ranged
};

struct Tower{
    int tower_id; //identifiant de la tour
    int fire_power;  // La puissance de tire de la tour
    int fire_distance; //discreet ??  // La distance max pour qu'une bullet atteigne un ennemi
    float fire_rythm;  // L'intervalle en millième de secondes entre chaque bullet de tirée.
    int price; // Le prix en fonction du type de tour
    Tower_Type type; //Le type de la tour
    //---- tower_sprite;  //Le lien vers le sprite de la tour (en fonction de son type)

    //Wave wave;
    //Bullet bullet
    void tower_map_apparition(int x_box, int y_box);  //méthode pour faire apparaître les sprites des towers sur la map
    void tower_interface_apparition(); //méthode pour faire apparaître en continu les sprites des towers sur la boutique de l'interface
    void tower_aiming();  //La méthode pour détecter un ennemi à partir de fire_distance
    void tower_fire(int x_pos_enemy, int y_pos_enemy);  //méthode pour faire feu sur un ennemi quand il y a détection
};