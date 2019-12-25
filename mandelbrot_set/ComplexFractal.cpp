#include "ComplexFractal.h"

ComplexFractal::ComplexFractal()
        : NumberGrid(200, 300), mMinX(-1.5), mMinY(-1), mMaxX(1.5), mMaxY(1), mDeltaX(0.01), mDeltaY(0.01){
    NumberGrid::setGridSize(200, 300);
}

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y)
        : NumberGrid(height, width), mMinX(min_x), mMinY(min_y), mMaxX(max_x), mMaxY(max_y){
    NumberGrid::setGridSize(height, width);
}

ComplexFractal::~ComplexFractal( ){}

double ComplexFractal::getMinX() const {
    return mMinX;
}

double ComplexFractal::getMaxX() const {
    return mMaxX;
}

double ComplexFractal::getMinY() const {
    return mMinY;
}

double ComplexFractal::getMaxY() const {
    return mMaxY;
}
void ComplexFractal::setGridSize(const int &height, const int &width) {
    if(height >= 2 && width >= 2){
        NumberGrid::setGridSize(height, width);
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}

void ComplexFractal::setPlaneSize(const double &min_x, const double &max_x, const double &min_y, const double &max_y) {
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

double ComplexFractal::getDeltaX() const {
    return mDeltaX;
}

double ComplexFractal::getDeltaY() const {
    return mDeltaY;
}

void ComplexFractal::setDeltas(const double &delta_x, const double &delta_y) {
    if(delta_x > 0 && delta_y > 0){
        mDeltaX = delta_x;
        mDeltaY = delta_y;
    }
}

double ComplexFractal::calculateDeltaY() const {
    double delta_y = ( getMaxY() - getMinY() ) / ( getHeight() - 1 );
    return delta_y;
}

double ComplexFractal::calculateDeltaX() const {
    double delta_x = ( getMaxX() - getMinX() ) / ( getWidth() - 1 );
    return delta_x;
}

double ComplexFractal::calculatePlaneYFromPixelRow(const int &row) const {
    if(row >= getHeight() || row < 0){
        return 0;
    }
    double y = getMaxY() - row * getDeltaY();
    return y;
}

double ComplexFractal::calculatePlaneXFromPixelColumn(const int &column) const {
    if(column >= getWidth() || column < 0){
        return 0;
    }
    double x = getMinX() + column * getDeltaX();
    return x;
}

void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates(const int &row, const int &column, double &x, double &y) const {
    if((row >= getHeight() || row < 0) || (column >= getWidth() || column < 0)){
        x = 0;
        y = 0;
    }
    else{
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
}
