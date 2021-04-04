#include "Toys.h"

/**
 * @brief Method implemented to draw the toys
 */
void Toys::DrawBall() {

    glPushMatrix();
    glTranslatef(1.5,2,-9);
    glutWireSphere(0.5,50,50);
    glPopMatrix();
}
