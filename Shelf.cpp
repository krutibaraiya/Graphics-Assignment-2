#include "Shelf.h"
/**
 * Method implemented to draw the shelf
 */
void Shelf::DrawShelf() {

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glShadeModel(GL_SMOOTH);
    GLfloat mat_specular[] = {0.521, 0.376, 0.247, 1.0};
    GLfloat mat_diffuse[] = {0.521, 0.376, 0.247, 1.0};
    GLfloat mat_ambient[] = {0.521, 0.376, 0.247, 1.0};
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
    /// shelf backside
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslatef(0,3,-9.8);
    glScalef(5,3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    /// left plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(-2.5,3,-9);
    glScalef(0.05,3,1.5);
    glutSolidCube(1);
    glPopMatrix();

    /// right plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(2.5,3,-9);
    glScalef(0.05,3,1.5);
    glutSolidCube(1);
    glPopMatrix();

    /// upper plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,4.5,-9);
    glScalef(5,0.05,1.5);
    glutSolidCube(1);
    glPopMatrix();

    /// middle plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,3,-9);
    glScalef(5,0.05,1.5);
    glutSolidCube(1);
    glPopMatrix();

    /// lower plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,1.5,-9);
    glScalef(5,0.05,1.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopAttrib();
}