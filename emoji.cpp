
#include <GL/glut.h>
#include <cmath>

// declaration of functions
void init();
void draw();
void reshape(int width, int height);
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy);

int main(int argc, char **argv)
{
    // initialization of glut and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(300, 50);
    glutInitWindowSize(540, 540);
    glutCreateWindow("Draw an Emoji");

    // register all callbacks
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    init();

    // glut event loop
    glutMainLoop();
}
void init()
{
    glClearColor(1, 1, 1, 1); // make background white
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // draw orange shadow
    glColor3f(0.96, 0.8, 0.15);
    circle(280, 280, 20, 20);
    // draw face circle
    glColor3f(.97, .86, 0.15);
    circle(270, 270, 0, 0);

    // draw left eyebrew
    glColor3f(0.24, 0.23, 0.33);
    circle(55, 45, -80, 100);
    glColor3f(.97, .86, 0.15);
    circle(60, 45, -80, 90);

    // draw left eye
    glColor3f(0.24, 0.23, 0.33);
    circle(60, 60, -80, 55);
    // inside circle of eye white part
    glColor3f(1, 1, 1);
    circle(50, 50, -80, 55);

    // draw eyeball
    glColor3f(0.24, 0.23, 0.33);
    circle(25, 25, -75, 50);
    glColor3f(1, 1, 1);
    circle(5, 5, -70, 50);

    // draw right eyebrew
    glColor3f(0.24, 0.23, 0.33);
    circle(55, 45, 100, 100);
    glColor3f(.97, .86, 0.15);
    circle(60, 45, 100, 90);

    // draw right eye
    glColor3f(0.24, 0.23, 0.33);
    circle(60, 60, 100, 55);
    // inside circle of eye white part
    glColor3f(1, 1, 1);
    circle(50, 50, 100, 55);

    // draw eyeball
    glColor3f(0.24, 0.23, 0.33);
    circle(25, 25, 105, 50);
    glColor3f(1, 1, 1);
    circle(5, 5, 110, 48);

    // draw mouth
    glColor3f(0.24, 0.23, 0.33);
    circle(130, 100, 0, -110);
    glColor3f(.97, .86, 0.15);
    circle(160, 65, 0, -75);

    //draw tounge
    glColor3f(1, 0, 0);
    circle(75, 20, 0, -190);

    glutSwapBuffers();
};

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-480, 480, -480, 480);
    glMatrixMode(GL_MODELVIEW);
}

// circle function

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 200; i++)
    {
        float angle = 2 * M_PI * i / 200;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x + cx), (y + cy));
    }

    glEnd();
};