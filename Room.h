#ifndef ROOM_H
#define ROOM_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
/**
 * @brief Class defined to draw the room
 */
class Room {
public:
    GLfloat len = 2, thickness = 0.05;
    /**
     * Method defined to draw the room
     */
    void DrawRoom();
};

#endif
