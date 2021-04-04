#ifndef FLOOR_H
#define FLOOR_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

/**
 * @brief Class defined to draw the floor and ceiling
 */
class Floor {

public:

    GLfloat len = 2, thickness = 0.05;
    /**
     * Method to draw the floor and ceiling
     */
    void DrawFloor();

};
#endif
