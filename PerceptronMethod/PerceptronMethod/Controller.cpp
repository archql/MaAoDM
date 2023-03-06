#include "Controller.h"

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <cstdlib>
#include <iostream>
#include <chrono>

#include "NamedColorTable.h"

Controller::Controller(int width, int height, int numOfClasses, double coeff) :
    mWidth(width),
    mHeight(height),
    mNumOfClasses(numOfClasses),
    mFunctions(numOfClasses),
    mPoints(),
    mActiveClass(0),
    mCoeff(coeff),
    mStudyMode(true)
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
    //std::srand(std::time(NULL)); //  Providing a seed value
    //
    //for (Point& p : mPoints) {
    //    p.mX = std::rand() % width;
    //    p.mY = std::rand() % height;
    //}
    mPoints.emplace_back(Point(0, 0, 0, 1));
    mPoints.emplace_back(Point(1, 1, 1, 1));
    mPoints.emplace_back(Point(2, -1, 1, 1));
}

Controller::~Controller()
{
    glDeleteLists(CUSTOM_LIST_ID, 1);
    glDeleteLists(CUSTOM_LIST_ID + 1, 1);
}

void Controller::update()
{
    //mAlgorithm->step();
    step();
}

void Controller::draw()
{
    // draw center line axises

    // draw polygons
    /*
    NamedColorTable::alphaColor buffer;

    for (size_t i = 0; i < mFunctions.size(); ++i) {
        const auto& f = mFunctions[i];
        // try to use 0.0
        double x1 = -mWidth, y1 = -mHeight;
        double y0 = -(f.z() - f.x() * mWidth) / f.y();
        double x0 = -(f.z() - f.y() * mWidth) / f.x();

        // try to use mWidth  mHeight (if wrong x0 y0)
        if (y0 < x1) {
            y0 = -(f.z() + f.x() * mWidth) / f.y();
            x1 = mWidth;
        }
        if (x0 < y1) {
            x0 = -(f.z() + f.y() * mHeight) / f.x();
            y1 = mHeight;
        }


        if (isinf(y0) || isnan(y0)) {
            y0 = mHeight;
            x1 = x0;
        }
        if (isinf(x0) || isnan(x0)) {
            x0 = mWidth;
            y1 = y0;
        }

        std::cout << "(0, " << y0 << ") (" << x0 << ", 0)\n";
        // get (width, 0) and (0, height) pos
        glColor3ubv(getColorFromClassNum(i));
        glBegin(GL_LINES);
        glVertex2d(x1, y0);
        glVertex2d(x0, y1);
        glEnd();
    }
    */
    // draw points
    for (const Point& p : mPoints) {
        glPushMatrix();
        glTranslatef(p.x(), p.y(), 0.0);
        glScalef(0.5, 0.5, 1.0);
        glColor3ubv(getColorFromClassNum(p.mClassNum));
        glCallList(CUSTOM_LIST_ID);
        glPopMatrix();
    }

    /*
    * Logics of 5th lab here
    */
    glBegin(GL_LINE_LOOP);
    // draw potentials (5th lab)
    for (int x = -mWidth; x <= mWidth; ++x) {
        // count f(x)
        const auto& f = mPotentialSum;
        const double y = -(f.x() * x + f.z()) / (f.w()*x + f.y());
        glVertex2d(x, y);
    }
    glEnd();
}

double potentialFunc(const Point& p, const Point& pi) {
    return p.x() * pi.x() + p.y() * pi.y() +
        p.z() * pi.z() + pi.x() * pi.y() * p.w();
}

void Controller::addPoint(int x, int y)
{
    Point p(mActiveClass, x, y, 1);
    if (!mStudyMode) {
        // find closest class
        //double vMax = p.dot(mFunctions[0]);
        //p.mClassNum = 0;
        //for (size_t i = 1; i < mFunctions.size(); ++i) {
        //    auto& f = mFunctions[i];
        //    const double v = p.dot(f);
        //    if (v > vMax) {
        //        vMax = v;
        //        p.mClassNum = i;
        //    }
        //}
        const double potential = potentialFunc(mPotentialSum, p);
        if (potential > 0) {
            p.mClassNum = 0;
        } else {
            p.mClassNum = 1;
        }

    }
    mPoints.emplace_back(p);
    //std::cout << "new point: x= " << x << " y= " << y << " (" << p.mClassNum << ")" << std::endl;
}

void Controller::setActiveClass(int classNo)
{
    if (classNo < mNumOfClasses) {
        mActiveClass = classNo;
    }
}

void Controller::clear()
{
    mStudyMode = true;
    mPoints.clear();
    for (auto& f : mFunctions) {
        f.reset();
    }
}

void Controller::toggleStudyMode()
{
    mStudyMode = !mStudyMode;
    std::cout << "study enabled? " << mStudyMode << std::endl;
}

void Controller::fill()
{
    mStudyMode = false;
    for (int x = -mWidth; x < mWidth; x++) {
        for (int y = -mHeight; y < mHeight; y++) {
            addPoint(x, y);
        }
    }
}

void Controller::step()
{
    //bool finished = true;
    //for (const auto& p : mPoints) {
    //    // get current funtion and its value
    //    const size_t curClass = p.mClassNum;
    //    auto& fCur = mFunctions[curClass];
    //    const double vCur = p.dot(fCur);
    //    // for other functions
    //    bool unbalanced = false;
    //    for (size_t i = 0; i < mFunctions.size(); ++i) {
    //        if (i == curClass) { // ignore current function
    //            continue;
    //        }
    //        auto& f = mFunctions[i];
    //        const double vOther = p.dot(f);
    //        if (vOther > vCur || abs(vOther - vCur) < 0.001) {
    //            // rebalance needed
    //            f -= (p * mCoeff);
    //            unbalanced = true;
    //        }
    //    }
    //    if (unbalanced) {
    //        // set finished to false (failed to balance)
    //        finished = false;
    //        fCur += (p * mCoeff);
    //    }
    //}
    //std::cout << "functions:" << std::endl;
    //for (size_t i = 0; i < mFunctions.size(); ++i) {
    //    const auto& f = mFunctions[i];
    //    std::printf(" f%-3d = %+.2f %+.2f*x1 %+.2f*x2\n", i, f.z(), f.x(), f.y());
    //}
    //std::cout << "finished? " << finished << std::endl;
    //
    /*
    * Logics of 5th lab here
    */
    bool finished = true;
    for (const auto& p : mPoints) {
        const double potential = potentialFunc(mPotentialSum, p);
        double k;
        if (potential <= 0 && p.mClassNum == 0) {
            k = 1.0;
        } else if (potential >= 0 && p.mClassNum == 1) {
            k = -1.0;
        } else {
            k = 0.0;
        }
        mPotentialSum += Point(0, 4 * p.x(), 4 * p.y(), 1, 16 * p.x() * p.y()) * k;
    }
    const auto& f = mPotentialSum;
    std::printf(" f = %+.2f %+.2f*x1 %+.2f*x2 %+.2f*x1*x2\n", f.z(), f.x(), f.y(), f.w());
    std::cout << "finished? " << finished << std::endl;
}

const unsigned char* Controller::getColorFromClassNum(int classNum) {
    switch (classNum) {
    case 0: return (NamedColorTable::purple); break;
    case 1: return (NamedColorTable::crimson); break;
    case 2: return (NamedColorTable::royalblue); break;
    case 3: return (NamedColorTable::tomato); break;
    case 4: return (NamedColorTable::gold); break;
    case 5: return (NamedColorTable::blueviolet); break;
    case 6: return (NamedColorTable::green); break;
    case 7: return (NamedColorTable::teal); break;
    case 8: return (NamedColorTable::hotpink); break;
    case 9: return (NamedColorTable::darkkhaki); break;
    case 10:return (NamedColorTable::salmon); break;
    case 11:return (NamedColorTable::pink); break;
    case 12:return (NamedColorTable::orangered); break;
    case 13:return (NamedColorTable::yellow); break;
    case 14:return (NamedColorTable::indigo); break;
    case 15:return (NamedColorTable::greenyellow); break;
    case 16:return (NamedColorTable::mediumspringgreen); break;
    case 17:return (NamedColorTable::lightcyan); break;
    case 18:return (NamedColorTable::deepskyblue); break;
    case 19:return (NamedColorTable::brown); break;
    default:return (NamedColorTable::gray); break;
    }
}
