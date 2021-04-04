#include "Table.h"
/**
 * @brief Method implemented to draw table
 */
void Table::DrawTable() {
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
    /// Table top
    glPushMatrix();
    glColor3d(0,1,0);
    glScalef(2.0,thickness,1.5);
    glutSolidCube(len);
    glPopMatrix();

    /// Table Legs
    glColor3d(0,1,0);
    static GLUquadric *gluQuadric = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-len+thickness,0,3*len/4-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(len-thickness,0,3*len/4-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-len+thickness,0,-3*len/4+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(len-thickness,0,-3*len/4+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();
    glPopAttrib();
}
