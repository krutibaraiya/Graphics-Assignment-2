#include "Room.h"
/**
 * @brief Method implemented to draw the room
 */
void Room::DrawRoom() {

    /// walls
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glShadeModel(GL_SMOOTH);
    GLfloat mat_specular[] = {1.0, 0.901, 0.792, 1.0};
    GLfloat mat_diffuse[] = {1.0, 0.901, 0.792, 1.0};
    GLfloat mat_ambient[] = {1.0, 0.901, 0.792, 1.0};
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(0,2,-10);
    glScalef(10,5,thickness);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(-10,2,0);
    glScalef(thickness,5,10);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(10,2,0);
    glScalef(thickness,5,10);
    glutSolidCube(len);
    glPopMatrix();

    glColor3d(0,0,0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(0,2,-10);
    glScalef(10,5,thickness);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(-10,2,0);
    glScalef(thickness,5,10);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(10,2,0);
    glScalef(thickness,5,10);
    glutSolidCube(len);
    glPopMatrix();


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPopAttrib();
}