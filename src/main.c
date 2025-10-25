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

#include "objects/triangle.h"

const char *vertex_shader_src =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n\0";

const char *fragment_shader_src =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
    "}\n\0";

int main(int argc, char *argv[])
{
    // Initialize GLFW
    if (!glfwInit()) {
        perror("Error initializing GLFW\n");
        exit(EXIT_FAILURE);
    }

    // Window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create window and OpenGL context
    GLFWwindow *window = glfwCreateWindow(800, 600, "Black hole Simulation", NULL, NULL);
    if (!window) {
        perror("Error creating window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Error loading GLAD");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    // Triangle rendering
    TRIANGLE triangle = {
        .vertices = {
            -0.5f, -0.5f * (float)sqrt(3) / 3, 0.0f,
            0.5f, -0.5f * (float)sqrt(3) / 3, 0.0f,
            0.0f, 0.5f * (float)sqrt(3) * 2 / 3, 0.0f
        }
    };


    // Compile shaders
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_src, NULL);
    glCompileShader(fragment_shader);


    // Create shader program and link shaders
    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);

    glLinkProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);


    // VAO's and VBO's (VAO b4 VBO order matters)
    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle.vertices), triangle.vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        // Checks if ESC key is pressed and closes window
        check_exit_pressed(window);

        // Render commands
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shader_program);

    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}