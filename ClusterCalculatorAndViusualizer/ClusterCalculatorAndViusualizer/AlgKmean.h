#pragma once
#include "Algorithm.h"

class AlgKmean :
    public Algorithm
{
public:
    AlgKmean(std::vector<Point>& points, std::vector<Point>& cores) :
        Algorithm(points, cores)
    {

    }

    virtual void init() override;
    virtual void step() override;

    virtual bool finished() override;
private:
    // K average algorithm
    void algDoStage1();
    void algDoStage2();
};

