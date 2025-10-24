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

// Custom headers
#include "constants.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char *argv[])
{
  // Initialize GLFW
  if (!glfwInit())
  {
    perror("Error initializing GLFW\n");
    exit(EXIT_FAILURE);
  }

  // Create window and OpenGL context
  GLFWwindow *window = glfwCreateWindow(800, 600, "My GLFW Window", NULL, NULL);
  if (!window)
  {

    perror("Error creating window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    perror("Error loading GLAD");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Mainloop
  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    // Render commands
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Check, call events and swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}