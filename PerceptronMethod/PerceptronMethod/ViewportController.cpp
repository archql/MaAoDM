#include "ViewportController.h"

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>

ViewportController::ViewportController(int fieldW, int fieldH)
{
    mScreenW = 0; // prevent div by 0  ?
    mScreenH = 0; // prevent div by 0  ?

    mFieldW = fieldW * 2;
    mFieldH = fieldH * 2;

    mViewPosX1 = -mFieldW / 2;
    mViewPosX2 = mFieldW / 2;
    mViewPosY1 = -mFieldH / 2;
    mViewPosY2 = mFieldH / 2;

    mZoom = 1.0;

    apply();
}

void ViewportController::zoom(bool positive)
{
    double oldZoom = mZoom;
    if (positive) 
    {
        mZoom += zoomStep;
        if (mZoom > maxZoom) {
            mZoom = maxZoom;
        }
    } 
    else 
    {
        mZoom -= zoomStep;
        if (mZoom < 1.0) {
            mZoom = 1.0;
        }
    }
    double zoomDiff = mZoom / oldZoom;
    // recount
    mViewPosX1 *= zoomDiff;
    mViewPosX2 *= zoomDiff;
    mViewPosY1 *= zoomDiff;
    mViewPosY2 *= zoomDiff;
    // update
    moveBy(0.0, 0.0); // same as toBorders
}

void ViewportController::moveBy(double dx, double dy)
{
    dx /= mZoom;
    dy /= mZoom;

    if (dx + mViewPosX1 < 0.0) {
        dx = mViewPosX1 - 0.0;
    }
    if (dx + mViewPosX2 > mFieldW) {
        dx = mFieldW - mViewPosX2;
    }
    if (dy + mViewPosY1 < 0.0) {
        dy = mViewPosY1 - 0.0;
    }
    if (dy + mViewPosY2 > mFieldH) {
        dy = mFieldH - mViewPosY2;
    }

    mViewPosX1 += dx;
    mViewPosX2 += dx;
    mViewPosY1 += dy;
    mViewPosY2 += dy;
}

void ViewportController::updateScreen(int screenW, int screenH)
{
    mScreenW = screenW;
    mScreenH = screenH;

    apply();
}

void ViewportController::updateField(int fieldW, int fieldH)
{
    mFieldW = fieldW * 2;
    mFieldH = fieldH * 2;
}

void ViewportController::openGl()
{
    glViewport(0, 0, mScreenW, mScreenH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(mViewPosX1, mViewPosX2, mViewPosY2, mViewPosY1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glPointSize(mPointSize + 1);
}

void ViewportController::toOpenglCords(int& x, int& y)
{
    x /= mPointSize;
    y /= mPointSize;
    x += mViewPosX1;
    y += mViewPosY1;
}

void ViewportController::apply()
{
    // Temp
    mViewPosX1 = -mFieldW / 2;
    mViewPosX2 = mFieldW/2;
    mViewPosY1 = -mFieldH/2;
    mViewPosY2 = mFieldH/2;

    // get point size and screen info
    double pSZ1 = (double)mScreenW / mFieldW;
    double pSZ2 = (double)mScreenH / mFieldH;
    if (pSZ1 < pSZ2)
    { // width is prioritized
        mPointSize = pSZ1;
        mViewPosY2 = (double)mScreenH / mPointSize / 2.;
        mViewPosY1 = -(double)mScreenH / mPointSize / 2.;
    }
    else
    { // height is prioritized
        mPointSize = pSZ2;
        mViewPosX2 = (double)mScreenW / mPointSize / 2.;
        mViewPosX1 = -(double)mScreenW / mPointSize / 2.;
    }
    glLineWidth(mPointSize * 0.3);
}
