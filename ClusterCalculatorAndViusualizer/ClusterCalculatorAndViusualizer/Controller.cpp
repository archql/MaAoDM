#include "Controller.h"

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <cstdlib>
#include <iostream>

#include "NamedColorTable.h"
#include "AlgKmean.h"
#include "AlgMaxiMin.h"

Controller::Controller(int width, int height, int numOfPoints, int numOfClasses) :
    mPoints(numOfPoints),
    mCores(numOfClasses),
    mWidth(width),
    mHeight(height),
    mNumOfClasses(numOfClasses)
{
    // create gllist for view
    glNewList(CUSTOM_LIST_ID, GL_COMPILE); // TODO 1000 is test
    glBegin(GL_QUADS);
    glVertex2i(1, 1);
    glVertex2i(1, -1);
    glVertex2i(-1, -1);
    glVertex2i(-1, 1);
    glEnd();
    glEndList();
    // init
    // step 0. Getting input data vectors.
    std::srand(std::time(NULL)); //  Providing a seed value

    for (Point& p : mPoints) {
        p.mX = std::rand() % width;
        p.mY = std::rand() % height;
    }

    // setup algorithm
    //mCores.clear(); // it is for AlgMaxiMin
    mAlgorithm = new AlgKmean(mPoints, mCores);//new AlgKmean(mPoints, mCores);
    mAlgorithm->init();
}

Controller::~Controller()
{
    glDeleteLists(CUSTOM_LIST_ID, 1);

    delete mAlgorithm;
}

void Controller::update()
{
    mAlgorithm->step();
}

void Controller::draw()
{
    for (const Point& p : mPoints) {
        glPushMatrix();
        glTranslatef(p.mX, p.mY, 0.0);
        glScalef(2.0, 2.0, 1.0);
        setColorFromClassNum(p.mClassNum);
        glCallList(CUSTOM_LIST_ID);
        glPopMatrix();
    }
    for (const Point& p : mCores) {
        glPushMatrix();
        glTranslatef(p.mX, p.mY, 0.0);

        glScalef(6.0, 6.0, 1.0);
        glColor3f(0.0, 0.0, 0.0);
        glCallList(CUSTOM_LIST_ID);

        glScalef(0.7, 0.7, 1.0);
        setColorFromClassNum(p.mClassNum);
        glCallList(CUSTOM_LIST_ID);
        glPopMatrix();
    }
}

void Controller::setColorFromClassNum(int classNum) {
    switch (classNum) {
    case 0: glColor3ubv(NamedColorTable::purple); break;
    case 1: glColor3ubv(NamedColorTable::crimson); break;
    case 2: glColor3ubv(NamedColorTable::hotpink); break;
    case 3: glColor3ubv(NamedColorTable::tomato); break;
    case 4: glColor3ubv(NamedColorTable::gold); break;
    case 5: glColor3ubv(NamedColorTable::blueviolet); break;
    case 6: glColor3ubv(NamedColorTable::green); break;
    case 7: glColor3ubv(NamedColorTable::teal); break;
    case 8: glColor3ubv(NamedColorTable::royalblue); break;
    case 9: glColor3ubv(NamedColorTable::darkkhaki); break;
    case 10: glColor3ubv(NamedColorTable::salmon); break;
    case 11: glColor3ubv(NamedColorTable::pink); break;
    case 12: glColor3ubv(NamedColorTable::orangered); break;
    case 13: glColor3ubv(NamedColorTable::yellow); break;
    case 14: glColor3ubv(NamedColorTable::indigo); break;
    case 15: glColor3ubv(NamedColorTable::greenyellow); break;
    case 16: glColor3ubv(NamedColorTable::mediumspringgreen); break;
    case 17: glColor3ubv(NamedColorTable::lightcyan); break;
    case 18: glColor3ubv(NamedColorTable::deepskyblue); break;
    case 19: glColor3ubv(NamedColorTable::brown); break;
    default: glColor3ubv(NamedColorTable::gray); break;
    }
}
