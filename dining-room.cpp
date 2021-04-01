#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "Color.h"
#include "Camera.h"



GLfloat length = 2, thickness = 0.05;
GLfloat Pos[] = {0,1,0,1};
GLfloat Col[] = {0,1,0,1};
Camera camera ({10, 10, 10}, {0, 0, 0});
GLboolean isDragging = false;
GLint dragX, dragY;


void DrawRoom() {
    // Floor
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::WHITE.rgba);
    glTranslatef(0,-3,0);
    glScalef(10,thickness,10);
    glutSolidCube(length);
    glPopMatrix();

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::RED.rgba);
    // walls

    glPushMatrix();
    glTranslatef(0,7,-10);
    glScalef(10,10,thickness);
    glutSolidCube(length);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(length);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(length);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,7,10);
    glScalef(10,10,thickness);
    glutSolidCube(length);
    glPopMatrix();

    // teapot
    glPushMatrix();
    glTranslatef(0,0.4,0);
    glScalef(0.5,0.5,0.5);
    glutSolidTeapot(1);
    glPopMatrix();

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::BLUE.rgba);
    glPushMatrix();
    glTranslatef(5,3,5);
    glScalef(1/152.38, 1/152.38, 1/152.38);
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,'A');
    glPopMatrix();

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::GREEN.rgba);
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

    // shelf backside
    glPushMatrix();
    glTranslatef(0,3,-10);
    glScalef(5,3,0.5);
    glutSolidCube(1);
    glPopMatrix();

    // left plank
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors::WHITE.rgba);
    glPushMatrix();
    glTranslatef(-2.5,3,-9.5);
    glScalef(0.05,3,1);
    glutSolidCube(1);
    glPopMatrix();

    // right plank
    glPushMatrix();
    glTranslatef(2.5,3,-9.5);
    glScalef(0.05,3,1);
    glutSolidCube(1);
    glPopMatrix();

    // upper plank
    glPushMatrix();
    glTranslatef(0,4.5,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    // middle plank
    glPushMatrix();
    glTranslatef(0,3,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    // lower plank
    glPushMatrix();
    glTranslatef(0,1.5,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            camera.translate(Camera::Direction::FORWARD);
            break;
        case 's':
            camera.translate(Camera::Direction::BACKWARD);
            break;
        case 'a':
            camera.translate(Camera::Direction::LEFT);
            break;
        case 'd':
            camera.translate(Camera::Direction::RIGHT);
            break;
        case 'r':
            camera.reset();
            break;
        case '[': // ACW roll
            camera.rotate(-5);
            break;
        case ']': // CW roll
            camera.rotate(5);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}


void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            camera.translate(Camera::Direction::UP);
            break;
        case GLUT_KEY_DOWN:
            camera.translate(Camera::Direction::DOWN);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON: {
            if (state == GLUT_DOWN) {
                isDragging = true;
                dragX = x;
                dragY = y;
            } else {
                isDragging = false;
            }
            break;
        }
        case 3:
            camera.zoom(1);
            break;
        case 4:
            camera.zoom(-1);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void mouseMotion(int x, int y) {
    if (isDragging) {
        camera.rotate(x - dragX, y - dragY);
        dragX = x;
        dragY = y;
        glutPostRedisplay();
    }
}
void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,1.0,1.0,64.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.lookAt();
    //gluLookAt(10,5,10,0,0,0,0,1,0);

    DrawRoom();



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
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);





    glutMainLoop();

    return 0;
}
