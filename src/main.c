// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Math headers
#include <math.h>
#include <cglm/cglm.h>
#include <limits.h>

// Utility headers
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

// OpenGL graphics related headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Physics headers
#include "constants.h"

// GLFW specific headers
#include "callbacks.h"
#include "input/keyboard_input.h"
#include "input/mouse_input.h"

int main(int argc, char *argv[])
{
    // Initialize GLFW
    if (!glfwInit())
    {
        perror("Error initializing GLFW\n");
        exit(EXIT_FAILURE);
    }

    // Create window and OpenGL context
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Physics Simulation", NULL, NULL);
    if (!window)
    {

        perror("Error creating window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        perror("Error loading GLAD");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        // Checks if ESC key is pressed and closes window
        check_exit_pressed(window);

        // Render commands
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}