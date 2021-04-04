#include "Floor.h"

/**
 * Method implemented to draw the floor and ceiling
 */
void Floor::DrawFloor() {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glShadeModel(GL_SMOOTH);
    GLfloat mat_specular[] = {0.976, 0.952, 0.952, 1.0};
    GLfloat mat_diffuse[] = {0.976, 0.952, 0.952, 1.0};
    GLfloat mat_ambient[] = {0.976, 0.952, 0.952, 1.0};
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    /// Floor
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,-3,0);
    glScalef(10,thickness,10);
    glutSolidCube(len);
    glPopMatrix();

    /// Ceiling
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,7,0);
    glScalef(10,thickness,10);
    glutSolidCube(len);
    glPopMatrix();
    glPopAttrib();
}
