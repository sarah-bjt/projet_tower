#include "map.hpp"

#include "GLHelpers.hpp"
#include "utils.hpp"

#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <img/img.hpp> 
#include <vector>
#include <stdexcept>


// Définir les dimensions de la fenêtre
const int window_width = 1280;
const int window_height = 720;


// Charger les textures
img::Image path { img::load(make_absolute_path("images/images_textures/path.png", true), 4, true) };
img::Image grass { img::load(make_absolute_path("images/images_textures/grass.png", true), 4, true) };
img::Image entry { img::load(make_absolute_path("images/images_textures/entry.png", true), 4, true) };
img::Image out { img::load(make_absolute_path("images/images_textures/out.png", true), 4, true) };

// Charger les maps
img::Image map1 { img::load(make_absolute_path("images/images_maps/map1.png", true), 3, true) };
img::Image map2 { img::load(make_absolute_path("images/images_maps/map2.png", true), 3, true) };
img::Image map3 { img::load(make_absolute_path("images/images_maps/map3.png", true), 3, true) };

float texture_width { 31.0f };
float texture_height { 31.0f };

// Faire apparaitre la map à gauche de l'écran
void Map::map_apparition(img::Image const& map) {
    if (map.channels_count() != 3) {
        throw std::runtime_error{"Image must have 3 channels"};
    }

    uint8_t const* data = map.data();
    size_t const size = map.width() * map.height();
    float size_case {(6.9f)*(texture_width / window_width)};

    glPushMatrix();
    glTranslatef(-10.8f*size_case,-6*size_case,0);

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            int index = (i * 12 + j) * 3;
            int pixel_r = data[index];
            int pixel_v = data[index + 1];
            int pixel_b = data[index + 2];

            GLuint texture_pixel {};

            if (pixel_r == 0 && pixel_v == 0 && pixel_b == 0) {
                texture_pixel = loadTexture(grass);
            } else if (pixel_r == 0 && pixel_v == 0 && pixel_b == 255){
                texture_pixel = loadTexture(out);
            }else if (pixel_r == 255 && pixel_v == 0 && pixel_b == 0){
                texture_pixel = loadTexture(entry);
            }else {
                texture_pixel = loadTexture(path);
            }

            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texture_pixel);
            glColor3ub(255, 255, 255);
            glBegin(GL_QUADS);

            glTexCoord2d(0.0, 0.0); 
            glVertex2f(j * size_case, i * size_case);

            glTexCoord2d(1.0, 0.0); 
            glVertex2f((j + 1) * size_case, i * size_case);

            glTexCoord2d(1.0, 1.0); 
            glVertex2f((j + 1) * size_case, (i + 1) * size_case);

            glTexCoord2d(0.0, 1.0); 
            glVertex2f(j * size_case, (i + 1) * size_case);

            glEnd();
            glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
        }
    }
    glPopMatrix();
}


