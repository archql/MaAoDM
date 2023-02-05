#pragma once
#include <vector>
#include "Point.h"

struct Algorithm {

public:
    Algorithm(std::vector<Point> &points, std::vector<Point>& cores);

public:
    virtual void init() = 0;
    virtual void step() = 0;

    virtual bool finished();

protected:
    std::vector<Point> &mPoints;
    std::vector<Point> &mCores;
    bool mFinished;
    int mNumIte;
};