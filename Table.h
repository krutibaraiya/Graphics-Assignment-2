#ifndef TABLE_H
#define TABLE_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
/**
 * @brief Class defined to draw the table
 */
class Table{
public:
    GLfloat len = 2, thickness = 0.05;
    /**
     * @brief Method defined to draw the table
     */
    void DrawTable();
};
#endif
