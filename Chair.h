#ifndef CHAIR_H
#define CHAIR_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
/**
 * @brief Class to draw chair
 * @param len length of the chair
 * @param thickness thickness of the chair
 */
class Chair{
public:
    GLfloat len = 2, thickness = 0.05;
    void DrawChair();
};
#endif
