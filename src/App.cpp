#include "App.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include<iostream>
#include <sstream>
#include "simpletext.h"




App::App(const std::string& player_name) : _previousTime(0.0), _viewSize(2.0),_player_name(player_name) {
    
    img::Image tower_rock {img::load(make_absolute_path("images/images_objects/rock_tower.png", true), 4, true)};
    img::Image tower_wood {img::load(make_absolute_path("images/images_objects/wood_tower.png", true), 4, true)};
    img::Image egg {img::load(make_absolute_path("images/images_objects/egg.png", true), 4, true)};
    
    _tex_tower_rock = loadTexture(tower_rock);
    _tex_tower_wood = loadTexture(tower_wood);
    _tex_egg = loadTexture(egg);
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

void App::update() {
    render();
}



// std::string player_name {"Sophie"}; // nom provisoir

void App::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

// Phrases de bienvenue

    TextRenderer.Label("Tempete de Poulets Geants !", _width - _width/4, 60, SimpleText::CENTER);
    const std::string player_name_text { "Bienvenue " + _player_name };
    TextRenderer.Label(player_name_text.c_str(),  _width - _width/4, 85, SimpleText::CENTER);
    TextRenderer.Label("Vous avez masse d oeufs !", _width - _width/4, 120, SimpleText::CENTER);

// Info joueur

    // score
    const std::string player_score_text { "votre score : " + std::to_string(0) };
    TextRenderer.Label(player_score_text.c_str(), _width - _width/4, 140, SimpleText::CENTER);

    // argent (oeuf)
    const std::string player_money_text { "votre nombre d oeufs : " + std::to_string(200) };
    TextRenderer.Label(player_money_text.c_str(), _width - _width/4, 160, SimpleText::CENTER);

// visuel Boutique

    // Rock Tower
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
    TextRenderer.Label("Elle coute 150 oeufs", _width - _width/4 - 105, 410, SimpleText::CENTER);
    TextRenderer.Label("Puissance de tire : 80", _width - _width/4 - 105, 430, SimpleText::CENTER);
    TextRenderer.Label("POUR ACHETER ", _width - _width/4 - 105, 470, SimpleText::CENTER);
    TextRenderer.Label("PRESS R", _width - _width/4 - 105, 490, SimpleText::CENTER);

    // Wood Tower
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
    TextRenderer.Label("Elle coute 60 oeufs", _width - _width/4 + 165, 410, SimpleText::CENTER);
    TextRenderer.Label("Puissance de tire : 20", _width - _width/4 + 165, 430, SimpleText::CENTER);
    TextRenderer.Label("POUR ACHETER ", _width - _width/4 + 165, 470, SimpleText::CENTER);
    TextRenderer.Label("PRESS W", _width - _width/4 + 165, 490, SimpleText::CENTER);


    TextRenderer.Render();


// Dessin oeuf
    // glPushMatrix();
    // glTranslatef(0.70f,0.60f,0);
    // glScalef(0.1f, 0.1f, 0.1f);
    // draw_quad_with_texture(_tex_egg);
    // glPopMatrix();



}

int App::key_callback(int key, int scancode, int action, int mods) {
    if (key == 90 && scancode == 44 && action == GLFW_PRESS)
    {
        return 1; // Pour la touche W
    }
    else if (key == 82 && scancode == 19 && action == GLFW_PRESS)
    {
        return 2; // Pour la touche R
    }
    else
    {
        return 0;
    }
}

void App::mouse_button_callback(int /*button*/, int /*action*/, int /*mods*/) {
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/) {
}

std::pair<double, double> App::cursor_position_callback(double xpos, double ypos) {
    return std::make_pair(xpos, ypos);
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

