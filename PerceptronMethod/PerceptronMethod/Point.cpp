#include "Point.h"
#include <cmath>

Point::Point()
{
    mArr[0] = 0.0;
    mArr[1] = 0.0;
    mArr[2] = 0.0;
    mClassNum = -1;
}

double Point::dot(const Point& other) const
{
    double res = 0.0;
    for (size_t i = 0; i < 3; i++) {
        res += mArr[i] * other[i];
    }
    return res;
}

double Point::x() const
{
    return mArr[0];
}


double Point::y() const
{
    return mArr[1];
}

double Point::z() const
{
    return mArr[2];
}

double Point::w() const
{
    return mArr[3];
}


void Point::setX(double x)
{
    mArr[0] = x;
}


void Point::setY(double y)
{
    mArr[1] = y;
}


void Point::setZ(double z)
{
    mArr[2] = z;
}

void Point::setW(double w)
{
    mArr[3] = w;
}


void Point::reset()
{
    for (size_t i = 0; i < 4; i++) {
        mArr[i] = 0.0;
    }
}


double Point::operator[](size_t index) const
{
    return mArr[index];
}
double& Point::operator[](size_t index)
{
    return mArr[index];
}

// warn!
double Point::distance2To(const Point& p) const
{
    double dst = 0.0;
    for (size_t i = 0; i < 3; i++) {
        const double a = (mArr[i] - p[i]);
        dst += a*a;
    }
    return dst;
}
// warn!
double Point::distanceTo(const Point& p) const
{
    return sqrt(distance2To(p));
}


Point& Point::operator+=(const Point& p)
{
    for (size_t i = 0; i < 4; i++) {
        mArr[i] += p[i];
    }

    return *this;
}

Point& Point::operator-=(const Point& p)
{
    for (size_t i = 0; i < 4; i++) {
        mArr[i] -= p[i];
    }

    return *this;
}


Point& Point::operator/=(int n)
{
    for (size_t i = 0; i < 4; i++) {
        mArr[i] /= n;
    }
    return *this;
}

// warn!
bool Point::operator==(const Point& p) const
{
    bool result = true;
    for (size_t i = 0; i < 3; i++) {
        result &= mArr[i] == p[i];
    }
    return result;
}


Point Point::operator+(const Point& p) const
{
    Point newP;
    for (size_t i = 0; i < 4; i++) {
        newP[i] = mArr[i] + p[i];
    }
    return newP;
}


Point Point::operator*(double value) const
{
    Point newP;
    for (size_t i = 0; i < 4; i++) {
        newP[i] = mArr[i] * value;
    }
    return newP;
}
