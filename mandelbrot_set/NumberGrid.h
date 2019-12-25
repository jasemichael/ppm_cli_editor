#ifndef _NumberGrid_H_
#define _NumberGrid_H_
#include <vector>
#include "PPM.h"
class NumberGrid {

private:
    int mHeight;
    int mWidth;
    int mMaxValue;
    std::vector<int> mArray;

public:
    NumberGrid( );
    NumberGrid( const int& height, const int& width );
    int getHeight( ) const;
    int getWidth( ) const;
    int getMaxNumber( ) const;
    virtual void setGridSize( const int& height, const int& width );
    void setMaxNumber( const int& number );
    const std::vector< int >& getNumbers( ) const;
    int index( const int& row, const int& column ) const;
    bool indexValid( const int& row, const int& column ) const;
    bool numberValid( const int& number ) const;
    int getNumber( const int& row, const int& column ) const;
    void setNumber( const int& row, const int& column, const int& number );
    void setPPM( PPM& ppm ) const;
    virtual ~NumberGrid( );
    virtual int calculateNumber( const int& row, const int& column ) const = 0;
    virtual void calculateAllNumbers( );
};
#endif /* _NumberGrid_H_ */