/*
 * ID: 171-15-9354
 * NAME: MD. TOUHIDUL ISLAM SHAWAN
 * PROBLEM NAME: ANIMATE OBJECT LEFT TO RIGHT
 */

// #include <windows.h> // uncomment if you are in windows machine
#include <GL/glut.h>

void init();
void reshape(int w, int h);
void draw();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translation - Animate Rectangle Left to Right");

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(draw);
    init();
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

float x_position = -10;
int state = 1;

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor4f(0.26, .81, .86, .34); // dark green
    glVertex2f(x_position, 1);
    glVertex2f(x_position, -1);
    glVertex2f(x_position + 2, -1);
    glVertex2f(x_position + 2, 1);
    glEnd();

    switch (state)
    {
    case 1:
        if (x_position < 8)
        {
            x_position += 0.15;
            ;
        }
        else
        {
            state = -1;
        }
        break;
    case -1:
        if (x_position > -10)
        {
            x_position -= 0.15;
        }
        else
        {
            state = 1;
        }
        break;
    default:
        break;
    }

    glutPostRedisplay();

    glutSwapBuffers();
}