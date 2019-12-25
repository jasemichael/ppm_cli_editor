#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet( )
: ComplexFractal(){}

MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
: ComplexFractal(height, width, min_x, max_x, min_y, max_y){}

MandelbrotSet::~MandelbrotSet( ){}

void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{
    x1 = x0*x0 - y0*y0 + a;
    y1 = 2*x0*y0 + b;
}

int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const{
    int i;
    double x, y, x1, y1;
    x = a;
    y = b;
    for(i=0; i < getMaxNumber(); i++){
        if(((x*x)+(y*y)) <= 4){
            calculateNextPoint(x, y, a, b, x1, y1);
            x = x1;
            y = y1;
        }
        else{
            return i;
        }
    }
    return getMaxNumber();
}

int MandelbrotSet::calculateNumber( const int& row, const int& column ) const{
    if(row >= getHeight() || row < 0 || column >= getWidth() || column < 0){
        return -1;
    }
    double x = calculatePlaneXFromPixelColumn(column);
    double y = calculatePlaneYFromPixelRow(row);
    return calculatePlaneEscapeCount(x, y);
}