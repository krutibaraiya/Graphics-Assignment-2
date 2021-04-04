#include "Teapot.h"
/**
 * @brief Method defined to draw the utah's teapot
 */
void Teapot::DrawTeapot() {

    GLfloat Teapot_col[] = {1,0,0,1};

    /// teapot
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Teapot_col);
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_diffuse[] = {1.0, 0.5, 0.0, 1.0};
    GLfloat mat_ambient[] = {1.0, 0.5, 0.0, 1.0};
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
    glPushMatrix();
    glTranslatef(0.5,0.4,0.5);
    glScalef(0.5,0.5,0.5);
    glRotatef(-90,0,1,0);
    glutSolidTeapot(1);
    glPopMatrix();
    glPopAttrib();
}
