#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include<iostream>
#include <sstream>
#include "simpletext.h"
#include <GLFW/glfw3.h>
#include "player.hpp"
#include "eventDispatcher.hpp"


App::App(const std::string& player_name) : _previousTime(0.0), _viewSize(2.0),_player_name(player_name) {
    // chargement tower
    img::Image tower_rock {img::load(make_absolute_path("images/images_objects/rock_tower.png", true), 4, true)};
    img::Image tower_wood {img::load(make_absolute_path("images/images_objects/wood_tower.png", true), 4, true)};
    _tex_tower_rock = loadTexture(tower_rock);
    _tex_tower_wood = loadTexture(tower_wood);

    // chargement images de fin
    img::Image img_win {img::load(make_absolute_path("images/images_ends/you_win.png", true), 4, true)};
    img::Image img_lose {img::load(make_absolute_path("images/images_ends/game_over.png", true), 4, true)};
    _tex_win = loadTexture(img_win);
    _tex_lose = loadTexture(img_lose);   
}

void App::setup() {
    // couleur de fond
    glClearColor(192/255.0f, 226/255.0f, 157/255.0f,1);

    // Setup de text en noir renderer avec blending
    TextRenderer.ResetFont();
    TextRenderer.SetColor(SimpleText::TEXT_COLOR, SimpleText::Color::BLACK);
    TextRenderer.SetColorf(SimpleText::BACKGROUND_COLOR, 0.f, 0.f, 0.f, 0.f);
    TextRenderer.EnableBlending(true);
}

void App::update(Player& player) {
    // Info joueur
    // score
    this->score = player.score;
    const std::string player_score_text { "votre score : " + std::to_string(score) };
    TextRenderer.Label(player_score_text.c_str(), _width - _width/4, 140, SimpleText::CENTER);
    
    // argent (oeuf)
    this->money = player.money;
    const std::string player_money_text { "votre nombre d oeufs : " + std::to_string(this->money) };
    TextRenderer.Label(player_money_text.c_str(), _width - _width/4, 160, SimpleText::CENTER);

    render();
}

void App::render() {
    this->score=0;
    this->money=200;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // indication pour une fin de partie
    if (EventDispatcher::instance().isGameOver()) {
        game_over = true;
    }
    if (EventDispatcher::instance().isGameWon()) {
        player_won = true;
    }

    if (game_over) { // Afficher l'image de fin de jeu (écran de défaite)
        glPushMatrix();
        glTranslatef(0.95f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        draw_quad_with_texture(_tex_lose); 
        glPopMatrix();
    } 
    else if (player_won) { // Afficher l'image de victoire
        glPushMatrix();
        glTranslatef(0.95f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        draw_quad_with_texture(_tex_win); 
        glPopMatrix();
    } 
    else { // La partie continue

        // Phrases de bienvenue
        TextRenderer.Label("Oh non on m'a vole mes oeufs !", _width - _width/4, 40, SimpleText::CENTER);
        TextRenderer.Label("Au voleur !", _width - _width/4, 60, SimpleText::CENTER);
        const std::string player_name_text { "Bienvenue " + _player_name };
        TextRenderer.Label(player_name_text.c_str(),  _width - _width/4, 85, SimpleText::CENTER);
        TextRenderer.Label("Vous avez etonnamment beaucoup d oeufs !", _width - _width/4, 120, SimpleText::CENTER);
        TextRenderer.Label("POUR QUITER PRESS ECHAP !", _width - _width/4, 650, SimpleText::CENTER);
    

        // visuel de la outique
        // Pour Rock Tower - Tour de pierres
        glPushMatrix();
        glTranslatef(0.6f,0.2f,0);
        glColor3f(235/255.0f, 185/255.0f, 119/255.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.30f, -0.75f);
            glVertex2f(0.30f, -0.75f);
            glVertex2f(0.30f, 0.30f);
            glVertex2f(-0.30f, 0.30f);
        glEnd();
        glScalef(0.4f, 0.4f, 0.4f);
        draw_quad_with_texture(_tex_tower_rock);
        glPopMatrix();

        TextRenderer.Label("La tour en pierres", _width - _width/4 - 105, 390, SimpleText::CENTER);
        TextRenderer.Label("Prix : 90 oeufs", _width - _width/4 - 105, 410, SimpleText::CENTER);
        TextRenderer.Label("Puissance de tire : 80", _width - _width/4 - 105, 430, SimpleText::CENTER);
        TextRenderer.Label("POUR ACHETER ", _width - _width/4 - 105, 470, SimpleText::CENTER);
        TextRenderer.Label("PRESS P", _width - _width/4 - 105, 490, SimpleText::CENTER);

        // Pour Wood Tower - Tour en bois
        glPushMatrix();
        glTranslatef(1.35f,0.2f,0);
        glColor3f(235/255.0f, 185/255.0f, 119/255.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.30f, -0.75f);
            glVertex2f(0.30f, -0.75f);
            glVertex2f(0.30f, 0.30f);
            glVertex2f(-0.30f, 0.30f);
        glEnd();
        glScalef(0.4f, 0.4f, 0.4f);
        draw_quad_with_texture(_tex_tower_wood);
        glPopMatrix();

        TextRenderer.Label("La tour en bois", _width - _width/4 + 165, 390, SimpleText::CENTER);
        TextRenderer.Label("Prix : 60 oeufs", _width - _width/4 + 165, 410, SimpleText::CENTER);
        TextRenderer.Label("Puissance de tire : 20", _width - _width/4 + 165, 430, SimpleText::CENTER);
        TextRenderer.Label("POUR ACHETER ", _width - _width/4 + 165, 470, SimpleText::CENTER);
        TextRenderer.Label("PRESS B", _width - _width/4 + 165, 490, SimpleText::CENTER);

        TextRenderer.Render();
    }

    
}

void App::key_callback(int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }
}

void App::mouse_button_callback(int /*button*/, int /*action*/, int /*mods*/) {
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/) {
}

void App::cursor_position_callback(double xpos, double ypos) {
    mouse_position = std::make_pair(xpos, ypos);
}



void App::size_callback(int width, int height) {
    _width  = width;
    _height = height;

    // make sure the viewport matches the new window dimensions
    glViewport(0, 0, _width, _height);

    const float aspectRatio { _width / (float) _height };

    // Change the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(aspectRatio > 1.0f) {
        glOrtho(-_viewSize / 2.0f * aspectRatio, _viewSize / 2.0f * aspectRatio, -_viewSize / 2.0f, _viewSize / 2.0f, -1.0f, 1.0f);
    } else {
        glOrtho(-_viewSize / 2.0f, _viewSize / 2.0f, -_viewSize / 2.0f / aspectRatio, _viewSize / 2.0f / aspectRatio, -1.0f, 1.0f);
    }
}

