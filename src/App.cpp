#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include<iostream>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"


App::App() : _previousTime(0.0), _viewSize(2.0) {
    
    img::Image tower_rock {img::load(make_absolute_path("images/images_objects/rock_tower.png", true), 4, true)};
    img::Image tower_wood {img::load(make_absolute_path("images/images_objects/wood_tower.png", true), 4, true)};
    
    _tex_tower_rock = loadTexture(tower_rock);
    _tex_tower_wood = loadTexture(tower_wood);
}


void App::setup() {
    // couleur de fond
    glClearColor(192/255.0f, 226/255.0f, 157/255.0f,1);

    // Setup the text renderer with blending enabled and white text color
    TextRenderer.ResetFont();
    TextRenderer.SetColor(SimpleText::TEXT_COLOR, SimpleText::Color::BLACK);
    TextRenderer.SetColorf(SimpleText::BACKGROUND_COLOR, 0.f, 0.f, 0.f, 0.f);
    TextRenderer.EnableBlending(true);
}

void App::update() {
    render();
}

void App::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.6f,0.2f,0);
    glColor3f(235/255.0f, 185/255.0f, 119/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.75f);
        glVertex2f(0.25f, -0.75f);
        glVertex2f(0.25f, 0.25f);
        glVertex2f(-0.25f, 0.25f);
    glEnd();
    glScalef(0.4f, 0.4f, 0.4f);
    draw_quad_with_texture(_tex_tower_rock);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.35f,0.2f,0);
    glColor3f(235/255.0f, 185/255.0f, 119/255.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.75f);
        glVertex2f(0.25f, -0.75f);
        glVertex2f(0.25f, 0.25f);
        glVertex2f(-0.25f, 0.25f);
    glEnd();
    glScalef(0.4f, 0.4f, 0.4f);
    draw_quad_with_texture(_tex_tower_wood);
    glPopMatrix();

    TextRenderer.Label("Bienvenue dans notre jeu :", _width - _width/4, 60, SimpleText::CENTER);
    TextRenderer.Label("Tempete de Poulets Geants !!", _width - _width/4, 85, SimpleText::CENTER);
    TextRenderer.Label("Vous avez masse de thune", _width - _width/4, 2*60, SimpleText::CENTER);

    TextRenderer.Render();
}

void App::key_callback(int key, int scancode, int action, int mods) {
    // std::cout << "je suis dans key callback" << std::endl;
        // Vérifier si la touche W est pressée
    if (key == 90 && scancode == 44 && action == GLFW_PRESS) {
        std::cout << "La touche W a été pressée." << std::endl;
    }
}

void App::mouse_button_callback(int /*button*/, int /*action*/, int /*mods*/) {
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/) {
}

void App::cursor_position_callback(double /*xpos*/, double /*ypos*/) {
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

