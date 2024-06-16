#include "map.hpp"

#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GLHelpers.hpp"
#include "utils.hpp"
#include <img/img.hpp> 
#include <vector>
#include <stdexcept>


// Définir les dimensions de la fenêtre
const int window_width = 1280;
const int window_height = 720;



// Charger les textures
img::Image path { img::load(make_absolute_path("images/images_textures/path1.png", true), 4, true) };
img::Image grass { img::load(make_absolute_path("images/images_textures/grass2.png", true), 4, true) };

// Charger les maps
img::Image map1 { img::load(make_absolute_path("images/images_maps/map1v3.png", true), 3, true) };
img::Image map2 { img::load(make_absolute_path("images/images_maps/map2.png", true), 3, true) };
img::Image map3 { img::load(make_absolute_path("images/images_maps/map3.png", true), 3, true) };

float texture_width { 31.0f };
float texture_height { 31.0f };

// Définition de la fonction map_apparition
void Map::map_apparition(img::Image const& map) {
    if (map.channels_count() != 3) {
        throw std::runtime_error{"Image must have 3 channels"};
    }

    uint8_t const* data = map.data();
    size_t const size = map.width() * map.height();
    // float aspect_ratio = static_cast<float>(window_width) / window_height;
    float size_case {8*(texture_width / window_width)};

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            int index = (i * 12 + j) * 3;
            int pixel_r = data[index];
            int pixel_v = data[index + 1];
            int pixel_b = data[index + 2];

            GLuint texture_pixel {};

            if (pixel_r == 0 && pixel_v == 0 && pixel_b == 0) {
                texture_pixel = loadTexture(grass);
            } else {
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
}




// // Déclaration de la fonction pixels_as_list
// std::vector<uint8_t> pixels_as_list(img::Image const& image);

// // Définition de la fonction pixels_as_list
// std::vector<uint8_t> pixels_as_list(img::Image const& image) {
//     if (image.channels_count() != 3) {
//         throw std::runtime_error{"Image must have 3 channels"};
//     }

//     uint8_t const* data = image.data();
//     size_t const size = image.width() * image.height();

//     std::vector<uint8_t> pixel_values;
//     pixel_values.reserve(size * 3); // Réserve suffisamment d'espace pour R, G, B de chaque pixel

//     for (size_t i = 0; i < size; ++i) {
//         pixel_values.push_back(data[i * 3]);     // Valeur R du pixel i
//         pixel_values.push_back(data[i * 3 + 1]); // Valeur G du pixel i
//         pixel_values.push_back(data[i * 3 + 2]); // Valeur B du pixel i
//     }

//     return pixel_values;
// }


// // Définition de la fonction map_apparition
// void map_apparition(img::Image const& map) {
//     std::vector<uint8_t> map_data { pixels_as_list(map) };

//     float aspect_ratio = static_cast<float>(window_width) / window_height;



//     for (int i = 0; i < 12; ++i) {
//         for (int j = 0; j < 12; ++j) {
//             int index = (i * 12 + j) * 3;
//             int pixel_r = map_data[index];
//             int pixel_v = map_data[index + 1];
//             int pixel_b = map_data[index + 2];

//             GLuint texture_pixel {};

//             if (pixel_r == 0 && pixel_v == 0 && pixel_b == 0) {
//                 texture_pixel = loadTexture(grass);
//             } else {
//                 texture_pixel = loadTexture(path);
// //             }

//             glEnable(GL_TEXTURE_2D);
//             glBindTexture(GL_TEXTURE_2D, texture_pixel);
//             glColor3ub(255, 255, 255);
//             glBegin(GL_QUADS);


//                 glTexCoord2d(0.0, 0.0); 
//                 glVertex2f(j * texture_width / window_width, i * texture_height / window_height );

//                 glTexCoord2d(1.0, 0.0); 
//                 glVertex2f((j + 1) * texture_width / window_width, i * texture_height / window_height );

//                 glTexCoord2d(1.0, 1.0); 
//                 glVertex2f((j + 1) * texture_width / window_width, (i + 1) * texture_height / window_height );

//                 glTexCoord2d(0.0, 1.0); 
//                 glVertex2f(j * texture_width / window_width, (i + 1) * texture_height / window_height );

//                 // glTexCoord2d(0, 0); 
//                 // glVertex2f(j*(120.0f/window_height), i*(120/window_height));
//                 // // glVertex2f(j*texture_width, i*texture_height);

//                 // glTexCoord2d(1, 0); 
//                 // glVertex2f( (j*(120.0f/window_height)) + (120.0f/window_height), i*(120.0f/window_width));
//                 // // glVertex2f( (j*texture_width) + texture_width, i*texture_height);

//                 // glTexCoord2d(1, 1); 
//                 // glVertex2f(  (j*(120.0f/window_height)) + (120.0f/window_height),  i*(120.0f/window_width) + (120.0f/window_width));
//                 // // glVertex2f( (j*texture_width) + texture_width, (i*texture_height) + texture_height);

//                 // glTexCoord2d(0, 1);
//                 // glVertex2f(  (j*(120.0f/window_height)),  i*(120.0f/window_width) + (120.0f/window_width)); 
//                 // // glVertex2f(j*texture_width, (i*texture_height) + texture_height);
//             glEnd();
//             glBindTexture(GL_TEXTURE_2D, 0);
//             glDisable(GL_TEXTURE_2D);

            
//         }
//     }
// }

