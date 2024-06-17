#pragma once

#include "GLHelpers.hpp"
#include "utils.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>



struct Map{
    // Définir les dimensions de la fenêtre
    const int window_width = 1280;
    const int window_height = 720;

    // Définition des tailles de texture
    float texture_width { 31.0f };
    float texture_height { 31.0f };

    // Fonction pour faire apparaître la map
    void map_apparition(img::Image const& map);
};

// Déclaration des images de la map et des textures
extern img::Image map1;
extern img::Image map2;
extern img::Image map3;

extern img::Image path;
extern img::Image grass;

