#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

#endif // !CALLBACKS_H