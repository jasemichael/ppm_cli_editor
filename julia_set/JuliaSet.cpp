#include "JuliaSet.h"
#include <iostream>

JuliaSet::JuliaSet()
    : NumberGrid(200, 300), mMinX(-1.5), mMinY(-1), mMaxX(1.5), mMaxY(1), mDeltaX(0.01), mDeltaY(0.01), mA(-0.650492), mB(-0.478235){
    NumberGrid::setGridSize(200, 300);
}

JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b )
: NumberGrid(height, width), mMinX(min_x), mMinY(min_y), mMaxX(max_x), mMaxY(max_y), mA(a), mB(b){
    NumberGrid::setGridSize(height, width);
}

JuliaSet::~JuliaSet( ){}

double JuliaSet::getMinX() const {
    return mMinX;
}

double JuliaSet::getMaxX() const {
    return mMaxX;
}

double JuliaSet::getMinY() const {
    return mMinY;
}

double JuliaSet::getMaxY() const {
    return mMaxY;
}

double JuliaSet::getA() const {
    return mA;
}

double JuliaSet::getB() const {
    return mB;
}

void JuliaSet::setGridSize(const int &height, const int &width) {
    if(height >= 2 && width >= 2){
        NumberGrid::setGridSize(height, width);
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}

void JuliaSet::setPlaneSize(const double &min_x, const double &max_x, const double &min_y, const double &max_y) {
    if(min_x >= -2 && min_x <= 2 && max_x >= -2 && max_x <= 2 && min_y >= -2 && min_y <= 2 && max_y >= -2 && max_y <= 2 && max_x != min_x && max_y != min_y){
        if(min_x != max_x){
            if(min_x > max_x){
                mMaxX = min_x;
                mMinX = max_x;
            }
            else{
                mMaxX = max_x;
                mMinX = min_x;
            }
        }
        if(min_y != max_y){
            if(min_y > max_y){
                mMaxY = min_y;
                mMinY = max_y;
            }
            else{
                mMaxY = max_y;
                mMinY = min_y;
            }
        }
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}

void JuliaSet::setParameters(const double &a, const double &b) {
    if(a >= -2 && a <= 2 && b >= -2 && b <= 2){
        mA = a;
        mB = b;
    }
}

double JuliaSet::getDeltaX() const {
    return mDeltaX;
}

double JuliaSet::getDeltaY() const {
    return mDeltaY;
}

void JuliaSet::setDeltas(const double &delta_x, const double &delta_y) {
    if(delta_x > 0 && delta_y > 0){
        mDeltaX = delta_x;
        mDeltaY = delta_y;
    }
}

double JuliaSet::calculateDeltaY() const {
    double delta_y = ( getMaxY() - getMinY() ) / ( getHeight() - 1 );
    return delta_y;
}

double JuliaSet::calculateDeltaX() const {
    double delta_x = ( getMaxX() - getMinX() ) / ( getWidth() - 1 );
    return delta_x;
}

double JuliaSet::calculatePlaneYFromPixelRow(const int &row) const {
    if(row >= getHeight() || row < 0){
        return 0;
    }
    double y = getMaxY() - row * getDeltaY();
    return y;
}

double JuliaSet::calculatePlaneXFromPixelColumn(const int &column) const {
    if(column >= getWidth() || column < 0){
        return 0;
    }
    double x = getMinX() + column * getDeltaX();
    return x;
}

void JuliaSet::calculatePlaneCoordinatesFromPixelCoordinates(const int &row, const int &column, double &x, double &y) const {
    if((row >= getHeight() || row < 0) || (column >= getWidth() || column < 0)){
        x = 0;
        y = 0;
    }
    else{
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
}

void JuliaSet::calculateNextPoint(const double x0, const double y0, double &x1, double &y1) const {
    x1 = x0*x0 - y0*y0 + mA;
    y1 = 2*x0*y0 + mB;
}

int JuliaSet::calculatePlaneEscapeCount(const double &x0, const double &y0) const {
    int i;
    double x, y, x1, y1;
    x = x0;
    y = y0;
    for(i=0; i < getMaxNumber(); i++){
        if(((x*x)+(y*y)) <= 4){
            calculateNextPoint(x, y, x1, y1);
            x = x1;
            y = y1;
        }
        else{
            return i;
        }
    }
    return getMaxNumber();
}

int JuliaSet::calculateNumber(const int &row, const int &column) const {
    if(row >= getHeight() || row < 0 || column >= getWidth() || column < 0){
        return -1;
    }
    double x = calculatePlaneXFromPixelColumn(column);
    double y = calculatePlaneYFromPixelRow(row);
    return calculatePlaneEscapeCount(x, y);
}