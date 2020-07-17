/*
---------------------------Description-------------------------------- 
-> This is show how to implement special keypress event with glut. 
-> First I have implemented a basic triangle and give it default white bg;
-> Special key on keyboard like f1,f2,f3...f10, left ,right,down, up etc;
-> Here when we will just implement f1, f2,f3 key. This 3 key will change the bg color of triangle
-> f1 will change bg to red
-> f2 will change bg to green
-> f3 will change bg to blue
*/
#include <GL/glut.h>

// decleration of functions
void init();
void draw();
void reshape(int width, int height);
void handleNormalKeypress(unsigned char key, int x, int y);
void handleSpecialKeypress(int key, int x, int y);

// global variables
float red = 1.0f, green = 1.0f, blue = 1.0f;

int main(int argc, char **argv)
{
    // glut init and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Change Color using keypress");

    // registration of all callbacks
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    init();
    // idle funciton
    glutIdleFunc(draw);
    // handler functions
    glutKeyboardFunc(handleNormalKeypress);
    glutSpecialFunc(handleSpecialKeypress);

    glutMainLoop();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
    glVertex2f(-150, -100);
    glVertex2f(150, -100);
    glVertex2f(0, 150);
    glEnd();

    glutSwapBuffers();
};
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
};

// press esc to close the window

void handleNormalKeypress(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        exit(0);
    }
}

void handleSpecialKeypress(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F1:
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;
    case GLUT_KEY_F2:
        red = 0.0;
        green = 1.0;
        blue = 0.0;
        break;

    case GLUT_KEY_F3:
        red = 0.0;
        green = 0.0;
        blue = 1.0;
        break;

    default:
        red = 1.0;
        green = 1.0;
        blue = 1.0;
        break;
    }
};