#include "Point.h"
#include <cmath>

Point::Point()
{
    mX = 0;
    mY = 0;
    mClassNum = -1;
    mIsCored = false;
}

double Point::distance2To(const Point& p) const
{
    const double a = mX - p.mX;
    const double b = mY - p.mY;
    return a * a + b * b;
}
double Point::distanceTo(const Point& p) const
{
    return sqrt(distance2To(p));
}

Point& Point::operator+=(const Point& p)
{
    mX += p.mX;
    mY += p.mY;
    return *this;
}

Point& Point::operator/=(int n)
{
    mX /= n;
    mY /= n;
    return *this;
}

bool Point::operator==(const Point& p)
{
    return (mX == p.mX) && (mY == p.mY);
}
