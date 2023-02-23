#include "View.h"

#include <algorithm>
#include <iostream>

View::View() :
    mViewportController(20, 20), // 20
    mController(20, 20, 5, 10), // 100000, 20
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
        //mController.update();
        mViewportController.toOpenglCords(x, y);
        mController.addPoint(x, y); 
    }
    glutPostRedisplay();
}

void View::keyboard(unsigned char key, int x, int y)
{
    if (key == (unsigned char)(' ')) { // space hit
        mController.update();
        glutPostRedisplay();
    } else if (key == (unsigned char)(32)) { // space hit
        mRunning = !mRunning;
    } else if (key == (unsigned char)(8)) { // backspace hit
        mController.clear();
        glutPostRedisplay();
    } else if (key >= (unsigned char)('1') && key <= (unsigned char)('9')) {
        mController.setActiveClass(key - (unsigned char)('1'));
    } else if (key == (unsigned char)('S') || key == (unsigned char)('s')) {
        mController.toggleStudyMode();
    } else if (key == (unsigned char)(13)) {
        mController.fill();
        glutPostRedisplay();
    }
}

void View::onTimer()
{
    if (mRunning) {
        mController.update();
        glutPostRedisplay();
    }
}
