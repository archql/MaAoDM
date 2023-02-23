#pragma once
#include "Controller.h"

#include <map>
#include <functional>
#include <memory>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

class View
{
public:
    static constexpr int delay = 0;//500;
private:
    View();
    ~View();
    View(const View& o) = delete;
    View& operator=(const View& o) = delete;
public:
    static View& getView() {
        static View v;
        return v;
    }
    static void timerFunc(int param) {
        View::getView().onTimer();

        glutTimerFunc(delay, View::timerFunc, param);
    }
protected:
    Controller mController;
    ViewportController mViewportController;

    bool mRunning;
public:
    void display();
    void reshape(int w, int h);
    void mouse(int button, int state, int x, int y);
    void keyboard(unsigned char key, int x, int y);
    void onTimer();
};

