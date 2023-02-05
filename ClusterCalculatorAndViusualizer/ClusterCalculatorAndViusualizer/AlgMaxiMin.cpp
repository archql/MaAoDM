#include "AlgMaxiMin.h"
#include <iostream>

void AlgMaxiMin::init()
{
    mCores.clear();
    // select N0
    //const size_t pos = 0; LETS TAKE JUST 0's point - its random!
    mPoints[0].mClassNum = 0; // assign first class to a random point (N0)
    mCores.push_back(mPoints[0]);

    const auto& n0 = mCores[0];
    double distA = n0.distance2To(mPoints[1]);
    size_t posN1 = 1;
    // select N1 as point with max dst from N0
    for (size_t i = 2; i < mPoints.size(); ++i) {
        const double distB = n0.distance2To(mPoints[i]);
        if (distB > distA) {
            distA = distB;
            posN1 = i;
        }
    }
    mPoints[posN1].mClassNum = 1;
    mCores.push_back(mPoints[posN1]);
}

void AlgMaxiMin::step()
{
    if (!mFinished) {
        std::cout << "Stage " << mNumIte << "\n";

        doAlgStep5(); // count new threshold distance (= dst(N1, N2) / 2)
        doAlgStep3();
        doAlgStep4();

        mNumIte++;

        std::cout << "New classes num " << mCores.size() << "\n";
        std::cout << "Need continue? " << !mFinished << "\n";
    }
}

bool AlgMaxiMin::finished()
{
    return mFinished;
}

void AlgMaxiMin::doAlgStep3()
{
    // fully as AlgKmean step1
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

void AlgMaxiMin::doAlgStep4()
{
    mFinished = true;

    std::vector<double> maxDsts(mCores.size());
    std::vector<size_t> maxDstsIds(mCores.size());
    // find max dsts in each class
    for (size_t i = 0; i < mPoints.size(); ++i) {
        const auto& p = mPoints[i];
        const int classNum = p.mClassNum;
        const double dst = p.distance2To(mCores[classNum]);
        if (maxDsts[classNum] < dst) {
            maxDsts[classNum] = dst;
            maxDstsIds[classNum] = i;
        }
    }
    // Var 1: add multicores. see if some of maximums exeed mThresholdDst
    //for (size_t i = 0; i < maxDsts.size(); ++i) {
    //    if (sqrt(maxDsts[i]) > mThresholdDst) {
    //        // new core is created
    //        mFinished = false;
    //
    //        auto& newCore = mPoints[maxDstsIds[i]];
    //        newCore.mClassNum = mCores.size();
    //        mCores.push_back(newCore);
    //    }
    //}
    // Var 2: only one
    size_t fartherestCoreId = 0;
    double fartherestDst = maxDsts[0];
    for (size_t i = 1; i < mCores.size(); ++i) {
        if (fartherestDst < maxDsts[i]) {
            fartherestDst = maxDsts[i];
            fartherestCoreId = i;
        }
    }
    if (sqrt(maxDsts[fartherestCoreId]) > mThresholdDst) {
        // new core is created
        mFinished = false;

        auto& newCore = mPoints[maxDstsIds[fartherestCoreId]];
        newCore.mClassNum = mCores.size();
        mCores.push_back(newCore);
    }
}

void AlgMaxiMin::doAlgStep5()
{
    // recalculate mThresholdDst (as avg of dsts between all cores)
    mThresholdDst = 0.0;
    size_t limitI = mCores.size() - 1;
    size_t limitJ = mCores.size();
    for (size_t i = 0; i < limitI; ++i) {
        for (size_t j = i + 1; j < limitJ; ++j) {
            mThresholdDst += mCores[i].distanceTo(mCores[j]);
        }
    }
    mThresholdDst /= (double)(limitI * limitJ);
}
