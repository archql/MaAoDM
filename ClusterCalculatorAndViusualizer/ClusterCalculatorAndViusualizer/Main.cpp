// Climate2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glut.h>

#include <iostream>

#include "Controller.h"
#include "View.h"

void initGL(void);
int initGLUT(int argc, char** argv);
int main(int argc, char** argv)
{
    initGLUT(argc, argv);
    initGL();

    glutMainLoop();
    return 0;
}

int initGLUT(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    int handle = glutCreateWindow("Cluster Calculator and Visualizator");

    glutDisplayFunc([]() {
        View::getView().display();
        });
    glutReshapeFunc([](int x, int y) {
        View::getView().reshape(x, y);
        });
    glutMouseFunc([](int button, int state, int x, int y) {
        View::getView().mouse(button, state, x, y);
        });
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        View::getView().keyboard(key, x, y);
        });
    glutTimerFunc(View::delay, View::timerFunc, 0);
    //glutMouseFunc(mouse);
    //glutMotionFunc(mouseMotion);

    return handle;
}
void initGL(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);

    glClearStencil(0);                          // clear stencil buffer
    glClearDepth(1.0f);                         // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);

    // set up light colors (ambient, diffuse, specular)
    GLfloat lightKa[] = { .3f, .3f, .3f, 1.0f };  // ambient light
    GLfloat lightKd[] = { .7f, .7f, .7f, 1.0f };  // diffuse light
    //GLfloat lightKs[] = { 1, 1, 1, 1 };           // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = { 0, 0, 1, 0 }; // directional light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0);                        // MUST enable each light source after configuration
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
