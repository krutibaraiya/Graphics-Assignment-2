#ifndef DINING_ROOM_CPP_OBJECTS_H
#define DINING_ROOM_CPP_OBJECTS_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "Parser.h"

/**
 * @brief Class defined to draw objects
 */
class Objects{
public:
    Model *cup, *monkey, *book, *vase, *plate, *donut, *book_red, *book_green, *book_purple, *book_yellow, *book_blue, *plant, *wine;
    Objects();
    void DrawObjects();
};
#endif
