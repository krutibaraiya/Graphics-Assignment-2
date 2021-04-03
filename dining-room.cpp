#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include "Color.h"
#include "Camera.h"
#include "Parser.h"


using namespace std;

GLfloat len = 2, thickness = 0.05;
Camera camera({5, 5, 5}, {0, 0, 0});
GLboolean isDragging = false;
GLint dragX, dragY;

Model *cup, *book, *vase, *plate, *donut;
void DrawObjects() {



    glPushMatrix();
    glTranslatef(0,0.5,0);

    cup->draw();
    glPopMatrix();

    //plate = new Model("Objects/plate1.obj", "Objects/plate1.mtl");
    glPushMatrix();
    glTranslatef(2,0.5,0.5);
    plate->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0.5,0.5);
    plate->draw();
    glPopMatrix();

    //donut = new Model("Objects/donut1.obj", "Objects/donut1.mtl");
    glPushMatrix();
    glTranslatef(2,0.5,0.5);
    donut->draw();
    glPopMatrix();

    glPushMatrix();
    donut->draw();
    glPopMatrix();

    //book = new Model("Objects/book1.obj", "Objects/book1.mtl");
    glPushMatrix();
    book->draw();
    glPopMatrix();


}
void DrawTeapot() {


    GLfloat Teapot_col[] = {1,0,0,1};


    // teapot
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
    //glColor3f(1,0,0);
    glTranslatef(1,0.4,0);
    glScalef(0.5,0.5,0.5);
    glutSolidTeapot(1);
    glPopMatrix();
    glPopAttrib();

}

void DrawShelf() {

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    //glShadeModel(GL_SMOOTH);
    GLfloat mat_specular[] = {0.666, 0.666, 0.666, 1.0};
    GLfloat mat_diffuse[] = {0.666, 0.666, 0.666, 1.0};
    GLfloat mat_ambient[] = {0.666, 0.666, 0.666, 1.0};
    //GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    //glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    // shelf backside
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslatef(0,3,-10);
    glScalef(5,3,0.5);
    glutSolidCube(1);
    glPopMatrix();
    //glLightfv(GL_LIGHT0, GL_POSITION, Colors::WHITE.rgba);

    // left plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(-2.5,3,-9.5);
    glScalef(0.05,3,1);
    glutSolidCube(1);
    glPopMatrix();

    // right plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(2.5,3,-9.5);
    glScalef(0.05,3,1);
    glutSolidCube(1);
    glPopMatrix();

    // upper plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,4.5,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    // middle plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,3,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();

    // lower plank
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,1.5,-9.5);
    glScalef(5,0.05,1);
    glutSolidCube(1);
    glPopMatrix();
    glPopAttrib();

}
void DrawTable() {

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
    // Table top
    glPushMatrix();
    glColor3d(0,1,0);
    glScalef(2.0,thickness,1.5);
    glutSolidCube(len);
    glPopMatrix();

    // Table Legs
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

void DrawChair() {
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
    // Right chair bottom
    glPushMatrix();
    glTranslatef(len+1.5,-len/2,0);
    glScalef(len/2,thickness,len/2);
    glutSolidCube(len);
    glPopMatrix();

    // Right chair legs
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

    // Right chair back support rods

    glPushMatrix();
    GLfloat d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(len+1.5+len/2-thickness,len/2-thickness,-len/2);
    for(int i = 0; i < 8; i++) {
        gluCylinder(gluQuadric,thickness,thickness,len,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    // Right chair back support

    glPushMatrix();
    glTranslatef(len+1.5+len/2-thickness,len/2+thickness,0);
    glScalef(thickness,0.1,len/2+thickness);
    glutSolidCube(len);
    glPopMatrix();


    // Left chair bottom
    glPushMatrix();
    glTranslatef(-len-1.5,-len/2,0);
    glScalef(len/2,thickness,len/2);
    glutSolidCube(len);
    glPopMatrix();

    // Left chair legs
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

    // Left chair back support rods

    glPushMatrix();
    d = 0.27;
    glRotatef(90,1,0,0);
    glTranslatef(-len-1.5-len/2+thickness,len/2-thickness,-len/2);
    for(int i = 0; i < 8; i++) {
        gluCylinder(gluQuadric,thickness,thickness,len,50,50);
        glTranslatef(0,-d,0);
    }
    glPopMatrix();

    // Left chair back support

    glPushMatrix();
    glTranslatef(-len-1.5-len/2+thickness,len/2+thickness,0);
    glScalef(thickness,0.1,len/2+thickness);
    glutSolidCube(len);
    glPopMatrix();
    glPopAttrib();

}

void DrawFloor()
{
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
    // Floor
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslatef(0,-3,0);
    glScalef(10,thickness,10);
    glutSolidCube(len);
    glPopMatrix();
    glPopAttrib();

}
void DrawRoom() {




    // walls

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
    glTranslatef(0,7,-10);
    glScalef(10,10,thickness);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(-10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(len);
    glPopMatrix();

//    glPushMatrix();
//    glColor3d(1,0,0);
//    glTranslatef(0,7,10);
//    glScalef(10,10,thickness);
//    glutSolidCube(len);
//    glPopMatrix();
    glPopAttrib();

    glColor3d(0,0,0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(0,7,-10);
    glScalef(10,10,thickness);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(-10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(len);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glTranslatef(10,7,0);
    glScalef(thickness,10,10);
    glutSolidCube(len);
    glPopMatrix();

//    glPushMatrix();
//    glColor3d(1,0,0);
//    glTranslatef(0,7,10);
//    glScalef(10,10,thickness);
//    glutSolidCube(len);
//    glPopMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



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
        case 'q':
            glutLeaveMainLoop();
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

void  light()
{
//    GLfloat mat_specular[] = {0.1, 0.2, 0.1, 1.0};
//    GLfloat mat_emission[] = {0.1, 0.2, 0.1, 1.0};
//    GLfloat light_position[] = {1.0, 1.0, 10.0, 1.0};
//    GLfloat light_ambient[] = {0.8, 0.8, 0.8, 1.0};
//    GLfloat light_diffuse[] = {0.1, 0.1, 0.1, 1.0};
//    GLfloat light_specular[] = {0.001, 0.001, 0.001, 1.0};
//
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    glEnable(GL_COLOR_MATERIAL);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0}; /* bright white */
    GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_ambient[] = {0.8, 0.8, 0.8, 1.0}; /* soft white */

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);


    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);

}
void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,1.0,1.0,64.0);
    glMatrixMode(GL_MODELVIEW);
    light();
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
    glLoadIdentity();
    camera.lookAt();
    //gluLookAt(10,5,10,0,0,0,0,1,0);

    DrawFloor();
    DrawRoom();
    //DrawTeapot();
    DrawShelf();
    DrawChair();
    DrawTable();
    DrawObjects();
    DrawTeapot();
    glutSwapBuffers();
    
}



int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(-400, -400);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Dining Room");


    cup = new Model("Objects/colored-cup.obj", "Objects/colored-cup.mtl");
    plate = new Model("Objects/plate1.obj", "Objects/plate1.mtl");
    donut = new Model("Objects/donut1.obj", "Objects/donut1.mtl");
    book = new Model("Objects/book1.obj", "Objects/book1.mtl");

//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);

    light();
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);

    //light();
    glutMainLoop();

    return 0;
}
