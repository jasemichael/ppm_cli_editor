#include "PPM.h"

PPM::PPM(){
	mHeight = 0;
	mWidth = 0;
	mMaxColorValue = 0;
	mArray.resize(mHeight * mWidth * 3);
}

PPM::PPM(const int& height, const int& width){
	mHeight = height;
	mWidth = width;
	mMaxColorValue = 0;
	mArray.resize(mHeight * mWidth * 3);
}

int PPM::getHeight() const{
	return mHeight;
}

int PPM::getWidth() const{
	return mWidth;
}

int PPM::getMaxColorValue() const{
	return mMaxColorValue;
}

int PPM::getChannel(const int& row, const int& column, const int& channel) const{
    int value = -1;
    if(0 <= row && row < mHeight && 0 <= column && column < mWidth && 0 <= channel && channel < 3){
        value = mArray[(row * mWidth * 3 + (column * 3)) + channel] ;
    }
        return value;
}

bool PPM::indexValid(const int& row, const int& column, const int& channel) const{
    int maxChannel = 3;
    if(0 <= row && row < mHeight && 0 <= column && column < mWidth && 0 <= channel && channel < maxChannel){
        return true;
    }
    return false;
}
int PPM::index(const int& row, const int& column, const int& channel) const{
    int index = (row * mWidth * 3 + column * 3) + channel;
    return index;
}

bool PPM::valueValid(const int& value) const{
    if(value >= 0 && value <= mMaxColorValue){
        return true;
    }
    return false;
}

void PPM::setHeight(const int& height){
    if(height >= 0){
        mHeight = height;
        mArray.resize(mHeight*mWidth * 3);
    }
}

void PPM::setWidth(const int& width){
    if(width >= 0){
        mWidth = width;
        mArray.resize(mHeight * mWidth * 3);
    }
}

void PPM::setMaxColorValue(const int& max_color_value){
    if(max_color_value >= 0 && max_color_value <= 255){
        mMaxColorValue = max_color_value;
    }
}

void PPM::setChannel(const int& row, const int& column, const int& channel, const int& value) {
    int maxChannel = 2;
    if(row >= 0 && row <= mHeight && column >= 0 && column <= mWidth && channel >= 0 && channel <= maxChannel && value >= 0 && value <= mMaxColorValue){
        int index = (row * mWidth * 3 + column * 3) + channel;
        mArray[index] = value;
    }
}

void PPM::setPixel(const int& row, const int& column, const int& red, const int& green, const int& blue){
setChannel(row, column, 0, red);
setChannel(row, column, 1, green);
setChannel(row, column, 2, blue);
}

std::ostream& operator << (std::ostream& os, const PPM& rhs) {
    os << "P6" << " " << rhs.getWidth() << " " << rhs.getHeight() << " " << rhs.getMaxColorValue() <<  "\n";
    int i = 0;
    int j = 0;
    int k = 0;
    unsigned char x;
    for(i=0; i < rhs.getHeight(); i++){
        for(j=0; j < rhs.getWidth(); j++){
            for(k=0; k < 3; k++){
                x = rhs.getChannel(i, j, k);
                os.write((char*) &x, sizeof(x));
            }
        }
    }
    return os;
}