#include <GL/glut.h>

void init();

void draw();

void reshape(int width, int height);

void timer(int value);

float x_position = -10.0;
int state = 1; // decide the direction to animate

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Learning OpenGL");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(x_position, 1.0);
    glVertex2f(x_position, -1.0);
    glVertex2f(x_position + 2, -1.0);
    glVertex2f(x_position + 2, 1.0);
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
        if (x_position < 8)
            x_position += 0.45;
        else
            state = -1;
        break;
    case -1:
        if (x_position > -10)
            x_position -= 0.45;
        else
            state = 1;
        break;
    default:
        break;
    }
}