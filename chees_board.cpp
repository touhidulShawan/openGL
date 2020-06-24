/*
 * ID: 171-15-9354
 * NAME: MD TOUHIDUL ISLAM SHAWAN
 */

//#include <windows.h> // UNCOMMENT THIS IN CASE OF ANY ERROR ON WINDOWS
#include "GL/glut.h"

void init();

void drawChessBoard();

int x, y;
bool flag = false;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(drawChessBoard);
    init();

    glutMainLoop();
}

// INIT
void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// DRAW THE CHESS BOARD FUNCTION
void drawChessBoard() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);


    for (x = 0; x <= 500; x += 50) {
        for (y = 0; y <= 500; y += 50) {
            if (flag) {
                glColor3ub(0, 0, 0);
                flag = !flag;
            } else {
                glColor3ub(1, 1, 1);
                flag = !flag;
            }

            glBegin(GL_QUADS); // GL_QUADS IS ANY SHAPE WITH 4 VERTICES
            glVertex2i(x, y);
            glVertex2i(x, y + 50);
            glVertex2i(x + 50, y + 50);
            glVertex2i(x + 50, y);
            glEnd();
            glutSwapBuffers();
        }
    }
}