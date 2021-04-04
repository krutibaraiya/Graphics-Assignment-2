#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include "Camera.h"
#include "Floor.h"
#include "Room.h"
#include "Shelf.h"
#include "Chair.h"
#include "Table.h"
#include "Fan.h"
#include "Teapot.h"
#include "Objects.h"
#include "Toys.h"
using namespace std;

Floor f;
Room room;
Shelf shelf;
Chair chair;
Table table;
Fan fan;
Teapot teapot;
Objects objects;
Toys toy;

Camera camera({5, 5, 5}, {0, 0, 0});
GLboolean isDragging = false;
GLint dragX, dragY;
GLfloat rotationAngle = 0.0f;

/**
 * @brief Method to define the keyboard keys for camera movement
 * @param key keyboard key for a particular movement
 */
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
        case 'q':
            glutLeaveMainLoop();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
/**
 * @brief Method to define the arrow key motion for camera movement
 * @param key keyboard arrow key for vertical motion
 */
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
/**
 * @brief Method to define the movement of camera by mouse button
 * @param button mouse button for movement of camera
 * @param state to show the status of scene whether it is dragged or not
 */
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
/**
 * @brief Method to define the movement of camera by mouse if it is dragged
 */
void mouseMotion(int x, int y) {
    if (isDragging) {
        camera.rotate(x - dragX, y - dragY);
        dragX = x;
        dragY = y;
        glutPostRedisplay();
    }

}
/**
 * Method to define the lighting for the scene
 */
void  light()
{

    GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0}; /* bright white */
    GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_ambient[] = {0.8, 0.8, 0.8, 1.0}; /* soft white */

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);


    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);

}
void animate() {
    fan.RotateFan();
    glutPostRedisplay();
}

/**
 * Method to render the scene
 */
void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0*camera.getZoom(),1.0,1.0,64.0);
    glMatrixMode(GL_MODELVIEW);
    light();
    glLoadIdentity();
    camera.lookAt();


    f.DrawFloor();
    room.DrawRoom();
    shelf.DrawShelf();
    chair.DrawChair();
    table.DrawTable();
    objects.DrawObjects();
    toy.DrawBall();
    teapot.DrawTeapot();
    fan.DrawFan();

    glutSwapBuffers();
    
}


/**
 * Method to initialise the glut window
 */
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(-400, -400);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Dining Room");

    light();
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
