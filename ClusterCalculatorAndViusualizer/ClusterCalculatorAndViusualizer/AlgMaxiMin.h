#pragma once
#include "Algorithm.h"

class AlgMaxiMin :
    public Algorithm
{
public:
    /*
    * assumed, that param cores is empty
    */
    AlgMaxiMin(std::vector<Point>& points, std::vector<Point>& cores) :
        Algorithm(points, cores)
    {
        mThresholdDst = 0.0;
    }

    virtual void init() override;
    virtual void step() override;

    virtual bool finished() override;

private:
    double mThresholdDst;
    // fully as AlgKmean step1
    void doAlgStep3(); // Выполняется распределение оставшихся объектов по классам по критерию минимального расстояниja
    void doAlgStep4();
    void doAlgStep5();
};

