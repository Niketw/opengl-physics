#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include <glad/glad.h>
#include <math.h>

#define N_VERTICES_TRI 9

typedef struct {
    GLfloat vertices[N_VERTICES_TRI];
} TRIANGLE;

#endif // !TEST_OBJECT_H