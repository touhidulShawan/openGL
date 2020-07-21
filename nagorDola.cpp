// #include <windows.h> // uncomment this if you are in windows machine
#include <GL/glut.h>

void init();
void draw();
void reshape(int w, int h);
// void drawRectangle(int x1, int x2, int y1, int y2);

int main(int argc, char **argv)
{
    // glut initialization and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("NagorDola");

    // register callbacks
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    init();

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

    // draw base of nagordola
    glColor3f(0.196, 0.15, 0.15);
    glBegin(GL_POLYGON);
    // bottom left to right
    glVertex2i(-125, -600);
    glVertex2i(175, -600);
    // bottom right to top right
    glVertex2i(175, -600);
    glVertex2i(175, -450);
    // top right to top left
    glVertex2i(175, -450);
    glVertex2i(-125, -450);
    // top left to bottom left
    glVertex2i(-125, -450);
    glVertex2i(-125, -600);
    glEnd();

    // draw bar of nagordola
    glColor3f(0.188, 0.192, 0.44);
    glBegin(GL_POLYGON);
    // bottom left to bottom right
    glVertex2i(0, -450);
    glVertex2i(50, -450);
    // bottom right to top right
    glVertex2i(50, -450);
    glVertex2i(50, 100);
    // top right to top left
    glVertex2i(50, 100);
    glVertex2i(0, 100);
    // top left to bottom right
    glVertex2i(0, 100);
    glVertex2i(0, -450);
    glEnd();

    // body that hold every nagordola seat

    glColor3f(0.6, 0.04, .90);
    glBegin(GL_POLYGON);
    // bottom left to bottom right
    glVertex2i(-100, 100);
    glVertex2i(150, 100);
    // bottom right to top right
    glVertex2i(150, 100);
    glVertex2i(150, 350);
    // top right to top left
    glVertex2i(150, 350);
    glVertex2i(-100, 350);
    // top left to bottom right
    glVertex2i(-100, 350);
    glVertex2i(-100, 100);
    glEnd();

    // left seat handler of nagor dola
    glColor3f(.95, .44, 0.47);
    glBegin(GL_POLYGON);
    // bottom left to bottom right
    glVertex2i(-150, 150);
    glVertex2i(-100, 150);
    // bottom right to top right
    glVertex2i(-100, 150);
    glVertex2i(-100, 300);
    // top right to top left
    glVertex2i(-100, 300);
    glVertex2i(-150, 300);
    // top left to bottom left
    glVertex2i(-150, 300);
    glVertex2i(-150, 150);
    glEnd();

    // left seat of nagor dola

    glColor3f(0.37, .88, 0.03);
    glBegin(GL_POLYGON);
    // bottom left to  bottom right
    glVertex2i(-450, 100);
    glVertex2i(-150, 100);
    // bottom right to top right
    glVertex2i(-150, 100);
    glVertex2i(-150, 350);
    // top right to top left
    glVertex2i(-150, 350);
    glVertex2i(-450, 350);
    // top left to bottom left
    glVertex2i(-450, 350);
    glVertex2i(-450, 100);
    glEnd();

    // right seat handler of nagor dola

    glColor3f(.95, .44, 0.47);
    glBegin(GL_POLYGON);
    // bottom left to  bottom right
    glVertex2i(150, 150);
    glVertex2i(200, 150);
    // bottom right to top right
    glVertex2i(200, 150);
    glVertex2i(200, 300);
    // top right to top left
    glVertex2i(200, 300);
    glVertex2i(150, 300);
    // top left to bottom left
    glVertex2i(150, 300);
    glVertex2i(150, 150);
    glEnd();

    // right seat of nagor dola

    glColor3f(0.45, 0.32, 0.886);
    glBegin(GL_POLYGON);
    // bottom left to  bottom right
    glVertex2i(200, 100);
    glVertex2i(500, 100);
    // bottom right to top right
    glVertex2i(500, 100);
    glVertex2i(500, 350);
    // top right to top left
    glVertex2i(500, 350);
    glVertex2i(200, 350);
    // top left to bottom left
    glVertex2i(200, 350);
    glVertex2i(200, 100);
    glEnd();

    glutSwapBuffers();
};

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 600);
    glMatrixMode(GL_MODELVIEW);
}
