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
    Controller(int width, int height, int numOfPoints, int numOfClasses);
    ~Controller();
public:
    void update();
    void draw();

private:
    int mWidth;
    int mHeight;

    int mNumOfClasses;
    std::vector<Point> mPoints;
    std::vector<Point> mCores;

private:
    void setColorFromClassNum(int classNum);

};
