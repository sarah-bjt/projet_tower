// #pragma once

// // #define GLFW_INCLUDE_NONE
// // #define _USE_MATH_DEFINES
// // #include <iostream>
// // #include <img/img.hpp>
// // #include "App.hpp"

// // #include <glad/glad.h>
// // #include <GLFW/glfw3.h>
// // #include <img/img.hpp>

// // #include <sstream>

// // #include "simpletext.h"
// // #include "utils.hpp"
// // #include "GLHelpers.hpp"

// // #define STB_IMAGE_IMPLEMENTATION // Pour obtenir le tableau des valeurs des caneaux de couleur par pixels
// // #include "stb_image.h"


// // #define GLFW_INCLUDE_NONE
// // #define _USE_MATH_DEFINES
// // #include <iostream>
// // #include <glad/glad.h>
// // #include <GLFW/glfw3.h>
// // #include <stb_image.h>
// // #include "GLHelpers.hpp"
// // #include "utils.hpp"

// #define GLFW_INCLUDE_NONE
// #define _USE_MATH_DEFINES
// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// // #define STB_IMAGE_IMPLEMENTATION
// // #include "stb_image.h"
// #include "GLHelpers.hpp"
// #include "utils.hpp"


// const int window_width = 1280;
// const int window_height = 720;

// // import map
// // int x;
// // int y;
// // int n;
// img::Image map1 {img::load(make_absolute_path("images/images_maps/map1v3.png", true), 3, true)}; 
// //unsigned char* map1 {stbi_load(make_absolute_path("images/images_maps/map1v3.png", true), &x, &y, &n, 0)};

// // import texture 
// img::Image path {img::load(make_absolute_path("images/images_textures/path1.png", true), 3, true)}; 
// img::Image grass {img::load(make_absolute_path("images/images_textures/grass2.png", true), 3, true)}; 

// // taille case de texture
// int texture_width {31}; 
// int texture_height {31};

// //  taille map final
// int final_map_width {texture_width*12};
// int final_map_height {texture_height*12};

// std::vector<uint8_t> pixels_as_list(img::Image const& image);
// void map_apparition(img::Image const& map);


#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include "GLHelpers.hpp"
#include "utils.hpp"

// Définition des constantes


// Déclaration des images de la map et des textures
extern img::Image map1;
extern img::Image path;
extern img::Image grass;

// Définition des tailles de texture et de la map finale
extern float texture_width;
extern float texture_height;

// Fonction pour obtenir les pixels sous forme de liste
std::vector<uint8_t> pixels_as_list(img::Image const& image);

// Fonction pour faire apparaître la map
void map_apparition(img::Image const& map);
