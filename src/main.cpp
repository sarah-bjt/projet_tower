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

// Optional: limit the frame rate
constexpr double TARGET_TIME_FOR_FRAME { 1.0 / 60.0 };

int main() {
    // Demander au joueur de saisir son nom
    std::string player_name;
    std::cout << "Entrez votre nom: ";
    std::getline(std::cin, player_name);

    // Set an error callback to display glfw errors
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "Error " << error << ": " << description << std::endl;
    });

    // Initialize glfw
    if (!glfwInit()) {
        return -1;
    }

// Not working on apple with those hint for unknown reason
// #ifdef __APPLE__
//     // We need to explicitly ask for a 3.3 context on Mac
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// #endif

    // Create window
    GLFWwindow* window { glfwCreateWindow(1280, 720, "Window", nullptr, nullptr) };
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Intialize glad (loads the OpenGL functions)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Va créer une valeur game;
    Game new_game;
    new_game.create_game(player_name);
    //Puis va utiliser une méthode pour le lancer

    std::cout <<  " Le jeu va commencer ! " << std::endl;

    // App app {};
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
    
    // Force calling the size_callback of the game to set the right viewport and projection matrix
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        app.size_callback(width, height);
    }

    app.setup();

    int key {0};
    int action {0};
    int scancode {0};
    int mods {0};
    int player_action {0};
    double xpos {0};
    double ypos {0};

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {

        // Get time (in second) at loop beginning
		double startTime { glfwGetTime() };
        

        glfwPollEvents(); // Ensure events are processed to update key state

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        {
            key = GLFW_KEY_B;
            player_action = 1;
    
        }
        else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        {
            key = GLFW_KEY_P;
            player_action = 2;
        }
        else
        {
            player_action = 0;
        }

        app.update();
        new_game.start();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();

        // Optional: limit the frame rate
		double elapsedTime { glfwGetTime() - startTime };
        // wait the remaining time to match the target wanted frame rate
		if(elapsedTime < TARGET_TIME_FOR_FRAME)
		{
			glfwWaitEventsTimeout(TARGET_TIME_FOR_FRAME-elapsedTime);
		}

        new_game.update(player_action, app.getMousePosition());
    }


    glfwTerminate();
    return 0;
}