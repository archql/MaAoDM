#include "Algorithm.h"

Algorithm::Algorithm(std::vector<Point>& points, std::vector<Point>& cores) :
    mPoints(points),
    mCores(cores)
{
    mFinished = false;
    mNumIte = 0;
}

bool Algorithm::finished()
{
    return mFinished;
}
