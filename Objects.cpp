#include "Objects.h"
/**
 * Constructor to load the object models from blender
 */
Objects::Objects() {
    cup = new Model("Objects/colored-cup2.obj", "Objects/colored-cup2.mtl");
    plate = new Model("Objects/plate1.obj", "Objects/plate1.mtl");
    donut = new Model("Objects/donut1.obj", "Objects/donut1.mtl");
    book = new Model("Objects/book1.obj", "Objects/book1.mtl");
    book_red = new Model("Objects/book-red.obj", "Objects/book-red.mtl");
    book_green = new Model("Objects/book-green.obj", "Objects/book-green.mtl");
    book_purple = new Model("Objects/book-purple.obj", "Objects/book-purple.mtl");
    book_yellow = new Model("Objects/book-yellow.obj", "Objects/book-yellow.mtl");
    book_blue = new Model("Objects/book-blue.obj", "Objects/book-blue.mtl");
    vase = new Model("Objects/vase.obj","Objects/vase.mtl");
    plant = new Model("Objects/plant.obj","Objects/plant.mtl");
    wine = new Model("Objects/Wineglass.1obj.obj","Objects/Wineglass.1obj.mtl");
    monkey = new Model("Objects/monkey.obj", "Objects/monkey.mtl");

}

/**
 * Method implemented to draw the objects
 */
void Objects::DrawObjects() {

    glPushMatrix();
    glTranslatef(1.7,-0.55,0.7);
    glScalef(0.25,0.25,0.25);
    wine->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3,-0.55,-0.7);
    glScalef(0.25,0.25,0.25);
    wine->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,2,-9);
    glScalef(0.5,0.5,0.5);
    monkey->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8,-2.75,-8);
    glScalef(1,1,1);
    plant->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8,-2.75,-8);
    glScalef(1,1,1);
    plant->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5,1.1,0);
    glScalef(0.25,0.25,0.25);
    vase->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,0.1,0.7);
    cup->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0.1,-0.7);
    cup->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0.05,0);
    plate->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,0.05,0);
    plate->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0.05,0.35);
    glScalef(25,25,25);
    donut->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,0.05,0.35);
    glScalef(25,25,25);
    donut->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.30,3.5,-9);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.10,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_red->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.90,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_green->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.70,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_purple->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.50,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_yellow->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.30,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_blue->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.10,3.5,-9);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_red->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_green->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_purple->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_yellow->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.30,3.5,-9);
    glScalef(2,2,2);
    glRotatef(90,0,1,0);
    glRotatef(10,1,0,0);
    book_blue->draw();
    glPopMatrix();
}
