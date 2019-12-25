#ifndef _JULIASET_H_
#define _JULIASET_H_
#include "NumberGrid.h"

class JuliaSet: public NumberGrid{
private:
    double mMinX;
    double mMinY;
    double mMaxX;
    double mMaxY;
    double mDeltaX;
    double mDeltaY;
    double mA;
    double mB;
public:
    JuliaSet( );
    JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b );
    virtual ~JuliaSet( );
    double getMinX( ) const;
    double getMaxX( ) const;
    double getMinY( ) const;
    double getMaxY( ) const;
    double getA( ) const;
    double getB( ) const;
    virtual void setGridSize( const int& height, const int& width );
    void setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y );
    void setParameters( const double& a, const double& b );
    double getDeltaX( ) const;
    double getDeltaY( ) const;
    void setDeltas( const double& delta_x, const double& delta_y );
    double calculateDeltaX( ) const;
    double calculateDeltaY( ) const;
    double calculatePlaneYFromPixelRow( const int& row ) const;
    double calculatePlaneXFromPixelColumn( const int& column ) const;
    void calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const;
    virtual void calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const;
    int calculatePlaneEscapeCount( const double& x0, const double& y0 ) const;
    virtual int calculateNumber( const int& row, const int& column ) const;
};

#endif /* _IMAGE_MENU_H_ */