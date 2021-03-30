#include <GL/glut.h>
#include <GL/glu.h>
#include "Color.h"

GLfloat length = 2, thickness = 0.05;
GLfloat Pos[] = {0,1,0,1};
GLfloat Col[] = {0,1,0,1};


void DrawTable() {
    
    // Table top
    glPushMatrix();
    glScalef(2.0,thickness,1.5);
    glutSolidCube(length);
    glPopMatrix();

    // Table Legs

    static GLUquadric *gluQuadric = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-length+thickness,0,3*length/4-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length-thickness,0,3*length/4-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-length+thickness,0,-3*length/4+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length-thickness,0,-3*length/4+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,3,50,50);
    glPopMatrix();

    // Right chair bottom
    glPushMatrix();
    glTranslatef(length+1.5,-length/2,0);
    glScalef(length/2,thickness,length/2);
    glutSolidCube(length);
    glPopMatrix();

    // Right chair legs
    glPushMatrix();
    glTranslatef(length+1.5-length/2+thickness,-length/2,-length/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length+1.5+length/2-thickness,-length/2,-length/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length+1.5+length/2-thickness,-length/2,+length/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,25,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(length+1.5-length/2+thickness,-length/2,length/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    // Right chair back support rods

    glPushMatrix();
    GLfloat d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(length+1.5+length/2-thickness,length/2-thickness,-length/2);
    for(int i = 0; i < 8; i++) {   
        gluCylinder(gluQuadric,thickness,thickness,length,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    // Right chair back support

    glPushMatrix();
    glTranslatef(length+1.5+length/2-thickness,length/2+thickness,0);
    glScalef(thickness,0.1,length/2+thickness);
    glutSolidCube(length);
    glPopMatrix();
    

    // Left chair bottom
    glPushMatrix();
    glTranslatef(-length-1.5,-length/2,0);
    glScalef(length/2,thickness,length/2);
    glutSolidCube(length);
    glPopMatrix();

    // Left chair legs
    glPushMatrix();
    glTranslatef(-length-1.5-length/2+thickness,-length/2,-length/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-length-1.5+length/2-thickness,-length/2,-length/2+thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-length-1.5+length/2-thickness,-length/2,+length/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,25,25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-length-1.5-length/2+thickness,-length/2,length/2-thickness);
    glRotatef(90,1,0,0);
    gluCylinder(gluQuadric, thickness,thickness,length,50,50);
    glPopMatrix();

    // Left chair back support rods

    glPushMatrix();
    d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(-length-1.5-length/2+thickness,length/2-thickness,-length/2);
    for(int i = 0; i < 8; i++) {   
        gluCylinder(gluQuadric,thickness,thickness,length,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    // Left chair back support

    glPushMatrix();
    glTranslatef(-length-1.5-length/2+thickness,length/2+thickness,0);
    glScalef(thickness,0.1,length/2+thickness);
    glutSolidCube(length);
    glPopMatrix();
   



    glutSwapBuffers(); 
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,1.0,1.0,64.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,4,12,0,0,0,0,1,0);
    glutDisplayFunc(DrawTable);

    
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(-400, -400);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Dining Room");
    
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0,GL_POSITION, Pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::GREEN.rgba);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    render();



    
    glutMainLoop();

    return 0;
}
