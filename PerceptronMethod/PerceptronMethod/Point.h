#pragma once

#include <array>

class Point
{
public:
    Point();

    Point(int classNum, double x, double y, double z) 
    {
        mClassNum = classNum;
        mArr[0] = x;
        mArr[1] = y;
        mArr[2] = z;
        mArr[3] = 0.0;
    }
    Point(int classNum, double x, double y, double z, double w)
    {
        mClassNum = classNum;
        mArr[0] = x;
        mArr[1] = y;
        mArr[2] = z;
        mArr[3] = w;
    }
public:
    int mClassNum;

public:
    double x() const;

    double y() const;

    double z() const;

    double w() const;

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    void setW(double w);

    void reset();

    double dot(const Point& other) const;

public:
    double operator[](size_t index) const;
    double& operator[](size_t index);

public:
    double distance2To(const Point &p) const;
    double distanceTo(const Point& p) const;
public:
    Point& operator+=(const Point& p);
    Point& operator-=(const Point& p);
    Point& operator/=(int n);
    bool operator==(const Point& p) const;

    Point operator+(const Point& p) const;
    Point operator*(double value) const;

private:
    std::array<double, 4> mArr;
};
