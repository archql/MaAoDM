#pragma once
#include "ViewportController.h"

#include <memory>
#include <vector>
#include "Point.h"

class Controller
{
    //friend class View;
public:
    static constexpr int CUSTOM_LIST_ID = 1000;
public:
    Controller(int width, int height, int numOfClasses, double coeff = 1.0);
    ~Controller();
public:
    void update();
    void draw();
    void addPoint(int x, int y);
    void setActiveClass(int classNo);
    void clear();
    void toggleStudyMode();
    void fill();

private:
    int mWidth;
    int mHeight;

    int mNumOfClasses;
    int mActiveClass;
    double mCoeff;
    std::vector<Point> mPoints;
    std::vector <Point> mFunctions;

    bool mStudyMode;

private:
    void step();

private:
    const unsigned char* getColorFromClassNum(int classNum);

};
