#include "View.h"

#include <algorithm>
#include <iostream>

View::View() :
    mViewportController(1200, 800),
    mController(1200, 800, 20000, 20), // 100000, 20
    mRunning(false)
{
}

View::~View()
{
}

void View::display()
{
    std::cout << "display\n";
    // viewport setup
    mViewportController.openGl();

    // reset background
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.5, 0.5, 0.0);

    // draw
    int x, y;
    // your draw func here
    mController.draw();

    // end draw
    glutSwapBuffers();
}

void View::reshape(int w, int h)
{
    mViewportController.updateScreen(w, h);
}

void View::mouse(int button, int state, int x, int y)
{
    //std::cout << "pos" << x << y;
    if ((button == GLUT_LEFT_BUTTON) && (state & GLUT_UP)) {
        mController.update();
    }
    glutPostRedisplay();
}

void View::keyboard(unsigned char key, int x, int y)
{
    if (key == (unsigned char)(' ')) { // space hit
        mRunning = !mRunning;
    }
}

void View::onTimer()
{
    if (mRunning) {
        mController.update();
        glutPostRedisplay();
    }
}
