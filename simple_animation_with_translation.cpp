#include "GL/glut.h"

void init();

void draw();

void reshape(int width, int height);

void timer(int value);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(300, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Translation");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 1);
}

float x_position = -10.0;
int state = 1;

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // translate the rectangle to different position
    glTranslated(x_position, x_position, 0.0); // will translate and animate diagonally
                                               //    glTranslated(x_position, 4.0, 0.0); // will translate and animate at specific (position 4)
                                               //    draw the rectangle
    glBegin(GL_POLYGON);
    glColor4f(0.26, .81, .86, .34); // dark green
    glVertex2f(0, 1.5);
    glVertex2f(-1.5, 0);
    glVertex2f(0, -1.5);
    glVertex2f(1.5, 0);
    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, value);

    switch (state)
    {
    case 1:
        if (x_position < 9)
            x_position += 0.15;
        else
            state = -1;
        break;
    case -1:
        if (x_position > -9)
            x_position -= 0.15;
        else
            state = 1;
        break;
    default:
        break;
    }
}