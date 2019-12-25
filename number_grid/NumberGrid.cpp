#include "NumberGrid.h"

NumberGrid::NumberGrid( ){
    int i;
    setGridSize(300, 400);
    mMaxValue = 255;
    for(i = 0; i < getHeight()*getWidth(); i++){
        mArray.push_back(0);
    }
}
NumberGrid::NumberGrid( const int& height, const int& width ){
    int i;
    setGridSize(height, width);
    mMaxValue = 255;
    for(i = 0; i < getHeight()*getWidth(); i++){
        mArray.push_back(0);
    }
}
int NumberGrid::getHeight( ) const{
    return mHeight;
}
int NumberGrid::getWidth( ) const{
    return mWidth;
}
int NumberGrid::getMaxNumber( ) const{
    return mMaxValue;
}
void NumberGrid::setGridSize( const int& height, const int& width ){
    if(height >= 2 && width >= 2){
        mHeight = height;
        mWidth = width;
        mArray.resize(mHeight*mWidth);
    }
}
void NumberGrid::setMaxNumber( const int& number ){
    if(number >= 0){
        mMaxValue = number;
    }
}
const std::vector< int >& NumberGrid::getNumbers( ) const{
    return mArray;
}
int NumberGrid::index( const int& row, const int& column ) const{
    return row*getWidth()+column;
}
bool NumberGrid::indexValid( const int& row, const int& column ) const{
    if(row >= 0 && row < getHeight() && column >= 0 && column < getWidth()){
        return true;
    }
    return false;
}
bool NumberGrid::numberValid( const int& number ) const{
    if(number >= 0 && number <= getMaxNumber()){
        return true;
    }
    return false;
}
int NumberGrid::getNumber( const int& row, const int& column ) const{
    if(indexValid(row, column)){
        return mArray[index(row, column)];
    }
    return -1;
}
void NumberGrid::setNumber( const int& row, const int& column, const int& number ){
    if(indexValid(row, column) && numberValid(number)){
        mArray[index(row, column)] = number;
    }
}
void NumberGrid::setPPM( PPM& ppm ) const{
    int row, column;
    ppm.setHeight(getHeight());
    ppm.setWidth(getWidth());
    ppm.setMaxColorValue(63);
    for(row = 0; row < ppm.getHeight(); row++){
        for(column = 0; column < ppm.getWidth(); column++){
            if(getNumber(row, column) == 0){
                ppm.setPixel(row, column, 0, 0, 0);
            }
            else if(getNumber(row, column) == getMaxNumber()){
                ppm.setPixel(row, column, 63, 31, 31);
            }
            else if(getNumber(row, column) % 8 == 0){
                ppm.setPixel(row, column, 63, 63, 63);
            }
            else if(getNumber(row, column) % 8 == 1){
                ppm.setPixel(row, column, 63, 31, 31);
            }
            else if(getNumber(row, column) % 8 == 2){
                ppm.setPixel(row, column, 63, 63, 31);
            }
            else if(getNumber(row, column) % 8 == 3){
                ppm.setPixel(row, column, 31, 63, 31);
            }
            else if(getNumber(row, column) % 8 == 4){
                ppm.setPixel(row, column, 0, 0, 0);
            }
            else if(getNumber(row, column) % 8 == 5){
                ppm.setPixel(row, column, 31, 63, 63);
            }
            else if(getNumber(row, column) % 8 == 6){
                ppm.setPixel(row, column, 31, 31, 63);
            }
            else if(getNumber(row, column) % 8 == 7){
                ppm.setPixel(row, column, 63, 31, 63);
            }
        }
    }
}