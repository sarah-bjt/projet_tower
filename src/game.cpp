#include "game.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <iostream>
#include <vector>

// pour faire apparaitre les towers
void t_button_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	std::cout << "key pressed: " << key << ", " << scancode << std::endl;
	if (key = 82, scancode = 19)
	{
		std::cout<<"met une tour de pierres"<<std::endl;
	}
};

int var {0};

void Game::create_game(){
    all_towers.push_back(Tower {1, 50, 3, 1.5f, 150, Tower_Type::Rock, -0.2f, -0.2f});
    wave = Wave {};
    wave.wave_setup();
}

void Game::start(){
    map.map_apparition(map1);
    all_towers[0].tower_map_apparition();
    wave.wave_forward();
    all_towers[0].tower_aiming(this->wave.enemys);
    for(auto& enemy : this->wave.enemys){
        enemy.enemy_arrives();
    }
    var++;
}


