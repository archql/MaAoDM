#pragma once
class Point
{
public:
    Point();
public:
    int mX;
    int mY;
    int mClassNum;

    bool mIsCored; // used for first core distribution
public:
    double distance2To(const Point &p) const;
    double distanceTo(const Point& p) const;
public:
    Point& operator+=(const Point& p);
    Point& operator/=(int n);
    bool operator==(const Point& p);
};

