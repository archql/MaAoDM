#pragma once

class ViewportController {

public:
    constexpr static double maxZoom = 5.0;
    constexpr static double zoomStep = 0.1;

public:
    ViewportController(int fieldW, int fieldH);

public:
    void zoom(bool positive);
    void moveBy(double dx, double dy);

    void updateScreen(int screenW, int screenH);
    void updateField(int fieldW, int fieldH);

    void openGl();

    void toOpenglCords(int &x, int &y);

private:
    void apply();

private:
    int mFieldW;
    int mFieldH;

    int mScreenW;
    int mScreenH;

    double mZoom;

public:
    double mViewPosX1;
    double mViewPosY1;
    double mViewPosX2;
    double mViewPosY2;

    double mPointSize;
};
