#include "App.hpp"
#include "game.hpp"
#include <queue>

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


namespace {
    App& window_as_app(GLFWwindow* window)
    {
        return *static_cast<App*>(glfwGetWindowUserPointer(window));
    }
}

// Limite la frame rate
constexpr double TARGET_TIME_FOR_FRAME { 1.0 / 60.0 };

int main() {
    // Demander au joueur de saisir son nom
    std::string player_name;
    std::cout << "Entrez votre nom: ";
    std::getline(std::cin, player_name);

    // Définit un rappel d'erreur pour afficher les erreurs GLFW
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "Error " << error << ": " << description << std::endl;
    });

    // Initialise glfw
    if (!glfwInit()) {
        return -1;
    }

    // Crée une window
    GLFWwindow* window { glfwCreateWindow(1280, 720, "Window", nullptr, nullptr) };
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Intialise glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Va créer une valeur game;
    Game new_game;
    new_game.create_game(player_name);
    //Puis va utiliser une méthode pour le lancer

    //Annonce le début du jeu au joueur
    std::cout <<  " Le jeu va commencer ! " << std::endl;

    //Ajoute le nom du joueur dans l'interface
    App app(player_name);

    glfwSetWindowUserPointer(window, &app);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        window_as_app(window).key_callback(key, scancode, action, mods);
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
        window_as_app(window).mouse_button_callback(button, action, mods);
    });
    glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
        window_as_app(window).scroll_callback(xoffset, yoffset);
    });
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
        window_as_app(window).cursor_position_callback(xpos, ypos);
    });
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        window_as_app(window).size_callback(width, height);
    });
    
    // Force l'appel du size_callback du jeu pour définir le bon viewport et la matrice de projection
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        app.size_callback(width, height);
    }

    app.setup();

    int key {0}; //Recupère la touche utilisé
    int player_action {0}; //Associe une touche à une action
    double xpos {0}; //Prend en variable la position de la souris
    double ypos {0};

    // Boucle jusqu'à ce que le joueur ferme la fenêtre
    while (!glfwWindowShouldClose(window)) {

        // Prend le temps (en secondes) au début de la boucle
		double startTime { glfwGetTime() };
        
        glfwPollEvents(); // Ensure events are processed to update key state

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) //Vérifie si la touche B est pressée
        {
            player_action = 1; // Définie player_action = 1 pour l'achat de tour de bois
        }
        else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) // Vérifie si la touche P est pressée
        {
            player_action = 2; // Définie player_action = 2 pour l'achat de tour de pierre
        }
        else
        {
            player_action = 0; // Si aucune touche est pressé, player_action = 0;
        }

        app.update(new_game.player);
        new_game.start(); // La partie commence

        glfwSwapBuffers(window);

        glfwPollEvents();

		double elapsedTime { glfwGetTime() - startTime };
		if(elapsedTime < TARGET_TIME_FOR_FRAME)
		{
			glfwWaitEventsTimeout(TARGET_TIME_FOR_FRAME-elapsedTime);
		}

        new_game.update(player_action, app.getMousePosition()); //Rajoute la tour acheté par le joueur
    }


    glfwTerminate();
    return 0;
}