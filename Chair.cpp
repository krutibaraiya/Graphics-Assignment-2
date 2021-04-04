#include "Chair.h"

/**
 * @brief Method to draw the chairs
 */
void Chair::DrawChair() {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glShadeModel(GL_SMOOTH);
    GLfloat mat_specular[] = {0.588, 0.423, 0.231, 1.0};
    GLfloat mat_diffuse[] = {0.588, 0.423, 0.231, 1.0};
    GLfloat mat_ambient[] = {0.588, 0.423, 0.231, 1.0};
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
    glColor3d(0,1,0);
    static GLUquadric *gluQuadric = gluNewQuadric();
    /// Right chair bottom
    glPushMatrix();
    glTranslatef(len+1.5,-len/2,0);
    glScalef(len/2,thickness,len/2);
    glutSolidCube(len);
    glPopMatrix();

    /// Right chair legs
    glPushMatrix();
    glTranslatef(len+1.5-len/2+thickness,-len/2,-len/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(len+1.5+len/2-thickness,-len/2,-len/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(len+1.5+len/2-thickness,-len/2,+len/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,25,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(len+1.5-len/2+thickness,-len/2,len/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    /// Right chair back support rods

    glPushMatrix();
    GLfloat d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(len+1.5+len/2-thickness,len/2-thickness,-len/2);
    for(int i = 0; i < 8; i++) {
        gluCylinder(gluQuadric,thickness,thickness,len,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    /// Right chair back support

    glPushMatrix();
    glTranslatef(len+1.5+len/2-thickness,len/2+thickness,0);
    glScalef(thickness,0.1,len/2+thickness);
    glutSolidCube(len);
    glPopMatrix();


    /// Left chair bottom
    glPushMatrix();
    glTranslatef(-len-1.5,-len/2,0);
    glScalef(len/2,thickness,len/2);
    glutSolidCube(len);
    glPopMatrix();

    /// Left chair legs
    glPushMatrix();
    glTranslatef(-len-1.5-len/2+thickness,-len/2,-len/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-len-1.5+len/2-thickness,-len/2,-len/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-len-1.5+len/2-thickness,-len/2,+len/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,25,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-len-1.5-len/2+thickness,-len/2,len/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,len,50,50);
    glPopMatrix();

    /// Left chair back support rods

    glPushMatrix();
    d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(-len-1.5-len/2+thickness,len/2-thickness,-len/2);
    for(int i = 0; i < 8; i++) {
        gluCylinder(gluQuadric,thickness,thickness,len,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    /// Left chair back support

    glPushMatrix();
    glTranslatef(-len-1.5-len/2+thickness,len/2+thickness,0);
    glScalef(thickness,0.1,len/2+thickness);
    glutSolidCube(len);
    glPopMatrix();
    glPopAttrib();
}
