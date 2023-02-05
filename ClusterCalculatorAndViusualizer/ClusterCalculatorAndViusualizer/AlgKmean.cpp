#include "AlgKmean.h"

#include <cstdlib>
#include <iostream>

void AlgKmean::init()
{
    // init
    // step 1; Randomly assign numOfClasses points to be new cores
    int numClassesRemained = mCores.size();
    while (numClassesRemained != 0) {
        const size_t pos = std::rand() % mPoints.size(); // assumed that numOfPoints < ~32K
        if (!mPoints[pos].mIsCored) { // if it is not already a core
            numClassesRemained--;
            // and remember its id
            mPoints[pos].mIsCored = true;
            mPoints[pos].mClassNum = numClassesRemained;
            mCores[numClassesRemained] = mPoints[pos];
        }
    }

    mFinished = false;
    mNumIte = 0;
}

void AlgKmean::step()
{
    if (!mFinished) {
        std::cout << "Stage " << mNumIte << "\n";

        algDoStage1();
        algDoStage2();

        mNumIte++;

        std::cout << "Need continue? " << !mFinished << "\n";
    }
}

bool AlgKmean::finished()
{
    return mFinished;
}

void AlgKmean::algDoStage1()
{
    for (Point& p : mPoints) {
        double dstA = p.distance2To(mCores[0]);
        int minClassNum = 0;
        for (int i = 1; i < mCores.size(); i++) {
            const double dstB = p.distance2To(mCores[i]);
            if (dstB < dstA) {
                dstA = dstB;
                minClassNum = i;
            }
        }
        p.mClassNum = minClassNum;
    }
}

void AlgKmean::algDoStage2()
{
    mFinished = false;

    std::vector<Point> newCores(mCores.size());
    std::vector<size_t> count(mCores.size(), 0);
    for (Point& p : mPoints) {
        newCores[p.mClassNum] += p;
        count[p.mClassNum] ++;
    }
    for (int i = 0; i < mCores.size(); i++) {
        if (count[i] == 0) {
            continue;
        }
        newCores[i] /= count[i];
        // check end condition
        mFinished |= !(newCores[i] == mCores[i]);
        // set new core
        newCores[i].mClassNum = i;
        mCores[i] = newCores[i];
    }
    mFinished = !mFinished;
}