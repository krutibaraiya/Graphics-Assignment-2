#ifndef FAN_H
#define FAN_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

/**
 * @brief Class defined to draw the fan
 */
class Fan {

public:
    GLfloat rotationAngle = 0.5f;
    /**
     * Method to draw fan
     */
    void DrawFan();
    /**
     * Method to rotate fan
     */
    void RotateFan();
};

#endif
