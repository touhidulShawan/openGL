// import all library that we need
// #include <windows.h> //uncomment this if you are on windows
#include <GL/glut.h>
#include <cmath>

// declaration of all function that used
void setup(int argc, char **argv);
void init();
void reshape(GLsizei width, GLsizei height);
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy);
void draw();

int main(int argc, char **argv)
{
    setup(argc, argv);
}

// setup glut stuff
void setup(int argc, char **argv)
{
    // initial setup
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("LabFinal_Frog_Cartoon");

    //register callbacks;
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();
}

void init()
{
    // just change the default bg color of window
    glClearColor(1, 1, 1, 1);
}

void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
    // To prevent divide by 0
    if (height == 0)
        height = 1;
    // calculate aspect ratio of the new window
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height)
    {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

//draw circle
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 100; i++)
    {
        float angle = 2 * M_PI * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

/*
color pallete
--------------
orange: 1, 0.4,0
red: 0.996,0,0
light-orange: 0.988,0.17,0.16
white: 1,1,1
black: 0,0,0
*/

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw body

    glColor3f(0, 0, 0);
    circle(0.5, 0.4, 0, 0);
    glColor3f(0.996, 0, 0);
    circle(0.48, 0.38, 0, 0);

    // draw head

    glColor3f(0, 0, 0);
    circle(0.55, 0.25, 0, 0.3);
    glColor3f(1, 0.4, 0);
    circle(0.53, 0.23, 0, 0.3);

    //draw eye
    // left eye
    glColor3f(0, 0, 0);
    circle(0.2, 0.2, -0.15, 0.5);
    glColor3f(1, 1, 1);
    circle(0.18, 0.18, -0.15, 0.5);

    // right eye
    glColor3f(0, 0, 0);
    circle(0.2, 0.2, 0.18, 0.5);
    glColor3f(1, 1, 1);
    circle(0.18, 0.18, 0.18, 0.5);

    // helpler
    glColor3f(1, 1, 1);
    circle(0.035, 0.09, 0.01, 0.51);

    // left eyball
    glColor3f(0, 0, 0);
    circle(0.1, 0.1, -0.13, 0.5);
    glColor3f(1, 1, 1);
    circle(0.04, 0.04, -0.14, 0.54);

    // right eyball
    glColor3f(0, 0, 0);
    circle(0.1, 0.1, 0.13, 0.5);
    glColor3f(1, 1, 1);
    circle(0.04, 0.04, 0.14, 0.54);

    // mouth
    glColor3f(0, 0, 0);
    circle(0.44, 0.1, 0, 0.2);
    glColor3f(1, 1, 1);
    circle(0.42, 0.08, 0, 0.2);

    // hands

    // left hand

    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.46, 0.17);
    glVertex2f(-0.58, -0.05);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.988, 0.17, 0.16);
    glVertex2f(-0.46, 0.17);
    glVertex2f(-0.58, -0.05);
    glEnd();

    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.58, -0.05);
    glVertex2f(-0.4, -0.3);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.988, 0.17, 0.16);
    glVertex2f(-0.58, -0.05);
    glVertex2f(-0.4, -0.3);
    glEnd();

    glColor3f(0, 0, 0);
    circle(0.1, 0.11, -0.5, -0.25);
    glColor3f(1, 1, 1);
    circle(0.08, 0.09, -0.5, -0.25);

    // right hand
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.46, 0.17);
    glVertex2f(0.63, 0.015);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.988, 0.17, 0.16);
    glVertex2f(0.46, 0.17);
    glVertex2f(0.63, 0.015);
    glEnd();

    glLineWidth(15);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.63, 0.015);
    glVertex2f(0.6, -0.04);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.988, 0.17, 0.16);
    glVertex2f(0.63, 0.015);
    glVertex2f(0.6, -0.04);
    glEnd();

    glColor3f(0, 0, 0);
    circle(0.1, 0.11, 0.6, -0.15);
    glColor3f(1, 1, 1);
    circle(0.08, 0.09, 0.6, -0.15);

    // legs

    //left leg
    glColor3f(0, 0, 0);
    circle(0.25, 0.1, -0.4, -0.35);
    glColor3f(1, 0.4, 0);
    circle(0.23, 0.08, -0.4, -0.35);

    //right leg
    glColor3f(0, 0, 0);
    circle(0.25, 0.1, 0.4, -0.35);
    glColor3f(1, 0.4, 0);
    circle(0.23, 0.08, 0.4, -0.35);

    // hair

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.5, .88);
    glVertex2f(0.01, 0.62);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.4, .88);
    glVertex2f(0.01, 0.62);
    glEnd();

    glutSwapBuffers();
}
