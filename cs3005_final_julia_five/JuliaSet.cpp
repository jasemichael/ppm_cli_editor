#include "JuliaSet.h"
#include <iostream>

JuliaSet::JuliaSet()
    : ComplexFractal(), mA(-0.650492), mB(-0.478235){}

JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b )
: ComplexFractal(height, width, min_x, max_x, min_y, max_y), mA(a), mB(b){}

JuliaSet::~JuliaSet( ){}

double JuliaSet::getA() const {
    return mA;
}

double JuliaSet::getB() const {
    return mB;
}



void JuliaSet::setParameters(const double &a, const double &b) {
    if(a >= -2 && a <= 2 && b >= -2 && b <= 2){
        mA = a;
        mB = b;
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


JuliaSetFive::JuliaSetFive()
        : JuliaSet(){}

JuliaSetFive::~JuliaSetFive(){}

void JuliaSetFive::calculateNextPoint(const double x0, const double y0, double &x1, double &y1) const {
    double r = std::sqrt( x0*x0 + y0*y0 );
    double theta = std::atan2( y0, x0 );
    x1 = std::pow(r, 5) * std::cos( 5 * theta ) + getA();
    y1 = std::pow(r,5) * std::sin( 5 * theta ) + getB();
}