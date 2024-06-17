#pragma once

#include <glad/glad.h>
#include <simpletext.h>
#include <queue>
#include"player.hpp"

class App {
public:
    App(const std::string& player_name);
    int score;
    int money;

    void setup();
    void update(Player& player);
    
    // GLFW callbacks binding
    void key_callback(int key, int scancode, int action, int mods);
    void mouse_button_callback(int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset);
    void cursor_position_callback(double xpos, double ypos);
    void size_callback(int width, int height);

    std::pair<double, double> getMousePosition() const { return mouse_position; }

private:

    std::pair<double, double> mouse_position {0.0, 0.0}; // Pair de coordonnées x et y de la souris

    void render();

    int _width {};
    int _height {};
    double _previousTime {};
    float _viewSize {};

    // Add your variables here
    GLuint _tex_tower_rock {};
    GLuint _tex_tower_wood {};
    GLuint _tex_egg {};
    std::string _player_name;
    GLuint _tex_win {};
    GLuint _tex_lose {};
    bool game_over = false;
    bool player_won = false;

    SimpleText TextRenderer {};
};