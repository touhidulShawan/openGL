/*
 * ID: 171-15-9354
 * NAME: MD. TOUHIDUL ISLAM SHAWAN
 * DATE: 11 JUNE 2020
 */

//import necessary library
//#include <windows.h> // UNCOMMENT IF YOUR ARE WINDOWS USER AND IN CASE IF THERE ARE SOME ERRORS IN COMPILING
#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>

void draw();

void init();


int main(int argc, char **argv) {
    glutInit(&argc, argv); // glut initialization
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // initialize display mode
    glutInitWindowPosition(100, 50); // set initial window position of terminal window
    glutInitWindowSize(1120, 645); //set initial window size
    glutCreateWindow("Draw House"); // create window
    glutDisplayFunc(draw); // register callback function draw with the window
    init();
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(217, 217, 217, 1); // current bg color light gray
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}

//draw function
void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    //draw wall first
    glColor3f(0.79, 0.85, 0.59);
    glBegin(GL_POLYGON);

    glVertex2f(100, 450); // left top
    glVertex2f(100, 50); // left bottom

    glVertex2f(100, 50); // left bottom
    glVertex2f(900, 50); // right bottom

    glVertex2f(900, 50); // right bottom
    glVertex2f(900, 450); // right top

    glVertex2f(900, 450); // right top
    glVertex2f(100, 450); // left top
    glEnd();

    // draw roof

    glColor3f(0.31, 0.33, 0.47);
    glBegin(GL_POLYGON);

    glVertex2f(100, 560); // left top
    glVertex2f(80, 450); // left bottom

    glVertex2f(80, 450); // left bottom
    glVertex2f(920, 450); // right bottom

    glVertex2f(920, 450); // right bottom
    glVertex2f(900, 560); // right top

    glVertex2f(900, 560); // right top
    glVertex2f(100, 560); // left top
    glEnd();

    //    draw bottom of house
    glColor3f(0.25, 0.12, 0.05);
    glBegin(GL_POLYGON);

    glVertex2f(100, 50); // left top
    glVertex2f(50, 0); // left bottom

    glVertex2f(50, 0); // left bottom
    glVertex2f(950, 0); // right bottom

    glVertex2f(950, 0); // right bottom
    glVertex2f(900, 50); // right top

    glVertex2f(900, 50); // right top
    glVertex2f(100, 50); // left top
    glEnd();

    //draw door
    glColor3f(0.29, 0.57, 0.75);
    glBegin(GL_POLYGON);

    glVertex2f(400, 410); // left top
    glVertex2f(400, 50); // left bottom

    glVertex2f(400, 50); // left bottom
    glVertex2f(600, 50); // right bottom

    glVertex2f(600, 50); // right bottom
    glVertex2f(600, 410); // right top

    glVertex2f(600, 410); // right top
    glVertex2f(400, 410); // left top
    glEnd();

    //    inside door
    glColor3f(0.43, 0.83, 0.91);
    glBegin(GL_POLYGON);

    glVertex2f(498, 410); // left top
    glVertex2f(498, 50); // left bottom

    glVertex2f(498, 50); // left bottom
    glVertex2f(502, 50); // right bottom

    glVertex2f(502, 50); // right bottom
    glVertex2f(502, 410); // right top

    glVertex2f(502, 410); // right top
    glVertex2f(498, 410); // left top
    glEnd();

    //    top left side design of door

    glColor3f(0.35, .47, .46);
    glBegin(GL_POLYGON);

    glVertex2f(400, 410); // left top
    glVertex2f(400, 300); // left bottom

    glVertex2f(400, 300); // left bottom
    glVertex2f(498, 300); // right bottom

    glVertex2f(498, 300); // right bottom
    glVertex2f(498, 410); // right top

    glVertex2f(498, 410); // right top
    glVertex2f(400, 410); // left top
    glEnd();

    //    top right side design of door
    glColor3f(0.35, .47, .46);
    glBegin(GL_POLYGON);

    glVertex2f(502, 410); // left top
    glVertex2f(502, 300); // left bottom

    glVertex2f(502, 300); // left bottom
    glVertex2f(600, 300); // right bottom

    glVertex2f(600, 300); // right bottom
    glVertex2f(600, 410); // right top

    glVertex2f(600, 410); // right top
    glVertex2f(502, 410); // left top
    glEnd();

    //    draw left window

    glColor3f(0.35, .47, .46);
    glBegin(GL_POLYGON);

    glVertex2f(150, 390); // left top
    glVertex2f(150, 150); // left bottom

    glVertex2f(150, 150); // left bottom
    glVertex2f(350, 150); // right bottom

    glVertex2f(350, 150); // right bottom
    glVertex2f(350, 390); // right top

    glVertex2f(350, 390); // right top
    glVertex2f(150, 390); // left top
    glEnd();

    //    four rectangle inside left window

    //first one
    glColor3f(0.898, 0.949, .788);
    glBegin(GL_POLYGON);

    glVertex2f(155, 385); // left top
    glVertex2f(155, 265); // left bottom

    glVertex2f(155, 265); // left bottom
    glVertex2f(250, 265); // right bottom

    glVertex2f(250, 265); // right bottom
    glVertex2f(250, 385); // right top

    glVertex2f(250, 385); // right top
    glVertex2f(155, 385); // left top
    glEnd();

    //second one
    glColor3f(.97, .71, .69);
    glBegin(GL_POLYGON);

    glVertex2f(255, 385); // left top
    glVertex2f(255, 265); // left bottom

    glVertex2f(255, 265); // left bottom
    glVertex2f(345, 265); // right bottom

    glVertex2f(345, 265); // right bottom
    glVertex2f(345, 385); // right top

    glVertex2f(345, 385); // right top
    glVertex2f(255, 385); // left top
    glEnd();

    //    third one
    glColor3f(.97, .71, .69);
    glBegin(GL_POLYGON);

    glVertex2f(155, 260); // left top
    glVertex2f(155, 155); // left bottom

    glVertex2f(155, 155); // left bottom
    glVertex2f(250, 155); // right bottom

    glVertex2f(250, 155); // right bottom
    glVertex2f(250, 260); // right top

    glVertex2f(250, 260); // right top
    glVertex2f(155, 260); // left top
    glEnd();

    //fourth one
    glColor3f(0.898, 0.949, .788);
    glBegin(GL_POLYGON);

    glVertex2f(255, 260); // left top
    glVertex2f(255, 155); // left bottom

    glVertex2f(255, 155); // left bottom
    glVertex2f(345, 155); // right bottom

    glVertex2f(345, 155); // right bottom
    glVertex2f(345, 260); // right top

    glVertex2f(345, 260); // right top
    glVertex2f(255, 260); // left top
    glEnd();

    //    right window

    glColor3f(0.35, .47, .46);
    glBegin(GL_POLYGON);

    glVertex2f(650, 390); // left top
    glVertex2f(650, 150); // left bottom

    glVertex2f(650, 150); // left bottom
    glVertex2f(850, 150); // right bottom

    glVertex2f(850, 150); // right bottom
    glVertex2f(850, 390); // right top

    glVertex2f(850, 390); // right top
    glVertex2f(650, 390); // left top
    glEnd();

    //    four rectangle inside right window

    //    first one
    glColor3f(0.898, 0.949, .788);
    glBegin(GL_POLYGON);

    glVertex2f(655, 385); // left top
    glVertex2f(655, 265); // left bottom

    glVertex2f(655, 265); // left bottom
    glVertex2f(750, 265); // right bottom

    glVertex2f(750, 265); // right bottom
    glVertex2f(750, 385); // right top

    glVertex2f(750, 385); // right top
    glVertex2f(655, 385); // left top
    glEnd();

    //    second one
    glColor3f(.97, .71, .69);
    glBegin(GL_POLYGON);

    glVertex2f(655, 260); // left top
    glVertex2f(655, 155); // left bottom

    glVertex2f(655, 155); // left bottom
    glVertex2f(750, 155); // right bottom

    glVertex2f(750, 260); // right bottom
    glVertex2f(750, 260); // right top

    glVertex2f(750, 260); // right top
    glVertex2f(655, 260); // left top
    glEnd();

    //third one
    glColor3f(.97, .71, .69);
    glBegin(GL_POLYGON);

    glVertex2f(755, 385); // left top
    glVertex2f(755, 265); // left bottom

    glVertex2f(755, 265); // left bottom
    glVertex2f(845, 265); // right bottom

    glVertex2f(845, 265); // right bottom
    glVertex2f(845, 385); // right top

    glVertex2f(845, 385); // right top
    glVertex2f(755, 385); // left top
    glEnd();

    //fourth one
    glColor3f(0.898, 0.949, .788);
    glBegin(GL_POLYGON);

    glVertex2f(755, 260); // left top
    glVertex2f(755, 155); // left bottom

    glVertex2f(755, 155); // left bottom
    glVertex2f(845, 155); // right bottom

    glVertex2f(845, 155); // right bottom
    glVertex2f(845, 260); // right top

    glVertex2f(845, 260); // right top
    glVertex2f(755, 260); // left top
    glEnd();

    glutSwapBuffers();

}

