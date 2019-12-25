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
    int i, j, k;
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

//Assignment 4
void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    int row, column, value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            value = getChannel(row, column, src_channel);
            dst.setPixel(row, column, value, value, value);
        }
    }
}
void PPM::grayFromRed( PPM& dst ) const{
    grayFromChannel(dst, 0);
}
void PPM::grayFromGreen( PPM& dst ) const{
    grayFromChannel(dst, 1);
}
void PPM::grayFromBlue( PPM& dst ) const{
    grayFromChannel(dst, 2);
}
double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const{
    int red = getChannel(row, column, 0);
    int green = getChannel(row, column, 1);
    int blue = getChannel(row, column, 2);
    double brightness = (0.2126*red) + (0.7152*green) + (0.0722*blue);
    return brightness;
}
void PPM::grayFromLinearColorimetric( PPM& dst ) const{
    int row, column, value;
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    for(row = 0; row < dst.getHeight(); row++){
        for(column = 0; column < dst.getWidth(); column++){
            value = linearColorimetricPixelValue(row, column);
            dst.setPixel(row, column, value, value, value);
        }
    }
}

//"P6 getWidth getHeight() rhs.getMaxColorValue()\n"
std::istream& operator>>( std::istream& is, PPM& rhs ){
    std::string p;
    unsigned char value, b;
    int width, height, mcv, row, column, chan;
    is >> p;
    is >> width;
    is >> height;
    is >> mcv;
    rhs.setWidth(width);
    rhs.setHeight(height);
    rhs.setMaxColorValue(mcv);
    is.read((char*)&b, 1);
    for(row = 0; row < rhs.getHeight(); row++){
        for(column = 0; column < rhs.getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                is.read((char *)&value, 1);
                rhs.setChannel(row, column, chan, value);
            }
        }
    }
    return is;
}

bool PPM::operator==( const PPM& rhs ) const{
    int tPixels = getHeight() * getWidth() ;
    int rhsPixels =  rhs.getHeight() * rhs.getWidth();
    if(tPixels == rhsPixels) {
        return true;
    }
    else{
        return false;
    }
}

bool PPM::operator!=( const PPM& rhs ) const {
    int tPixels = getHeight() * getWidth();
    int rhsPixels = rhs.getHeight() * rhs.getWidth();
    if (tPixels != rhsPixels){
        return true;
    }
    else{
        return false;
    }
}

bool PPM::operator<( const PPM& rhs ) const{
    int tPixels = getHeight() * getWidth();
    int rhsPixels = rhs.getHeight() * rhs.getWidth();
    if(tPixels < rhsPixels){
        return true;
    }
    else{
        return false;
    }
}

bool PPM::operator<=( const PPM& rhs ) const{
    int tPixels = getHeight() * getWidth();
    int rhsPixels = rhs.getHeight() * rhs.getWidth();
    if(tPixels <= rhsPixels){
        return true;
    }
    else{
        return false;
    }
}

bool PPM::operator>( const PPM& rhs ) const{
    int tPixels = getHeight() * getWidth();
    int rhsPixels = rhs.getHeight() * rhs.getWidth();
    if(tPixels > rhsPixels){
        return true;
    }
    else{
        return false;
    }
}

bool PPM::operator>=( const PPM& rhs ) const{
    int tPixels = getHeight() * getWidth();
    int rhsPixels = rhs.getHeight() * rhs.getWidth();
    if(tPixels >= rhsPixels){
        return true;
    }
    else{
        return false;
    }
}

PPM& PPM::operator+=( const PPM& rhs ){
    int row, column, chan, value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) + rhs.getChannel(row, column, chan);
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                setChannel(row, column, chan, value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator-=( const PPM& rhs ){
    int row, column, chan, value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) - rhs.getChannel(row, column, chan);
                if(value < 0){
                    value = 0;
                }
                setChannel(row, column, chan, value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator*=( const double& rhs ){
    int row, column, chan;
    double value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) * rhs;
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                else if(value < 0){
                    value = 0;
                }
                setChannel(row, column, chan, value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator/=( const double& rhs ){
    int row, column, chan;
    double value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) / rhs;
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                else if(value < 0){
                    value = 0;
                }
                setChannel(row, column, chan, value);
            }
        }
    }
    return *this;
}
PPM PPM::operator+( const PPM& rhs ) const{
    PPM p(getHeight(), getWidth());
    p.setMaxColorValue(getMaxColorValue());
    int row, column, chan, value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) + rhs.getChannel(row, column, chan);
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                p.setChannel(row, column, chan, value);
            }
        }
    }
    return p;
}
PPM PPM::operator-( const PPM& rhs ) const{
    PPM p(getHeight(), getWidth());
    p.setMaxColorValue(getMaxColorValue());
    int row, column, chan, value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) - rhs.getChannel(row, column, chan);
                if(value < 0){
                    value = 0;
                }
                p.setChannel(row, column, chan, value);
            }
        }
    }
    return p;
}
PPM PPM::operator*( const double& rhs ) const{
    PPM p(getHeight(), getWidth());
    p.setMaxColorValue(getMaxColorValue());
    int row, column, chan;
    double value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) * rhs;
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                else if(value < 0){
                    value = 0;
                }
                p.setChannel(row, column, chan, value);
            }
        }
    }
    return p;
}
PPM PPM::operator/( const double& rhs ) const{
    PPM p(getHeight(), getWidth());
    p.setMaxColorValue(getMaxColorValue());
    int row, column, chan;
    double value;
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            for(chan = 0; chan < 3; chan++){
                value = getChannel(row, column, chan) / rhs;
                if(value > getMaxColorValue()){
                    value = getMaxColorValue();
                }
                else if(value < 0){
                    value = 0;
                }
                p.setChannel(row, column, chan, value);
            }
        }
    }
    return p;
}

int PPM::edgePixelValue( const int& row1, const int& column1, const int& row2, const int& column2 ) const{
    double rc1, rc2, dif;
    rc1 = linearColorimetricPixelValue(row1, column1);
    rc2 = linearColorimetricPixelValue(row2, column2);
    dif = std::abs(rc1 - rc2);
    if(dif >= (getMaxColorValue()/10)){
        return getMaxColorValue();
    }
    return 0;
}

void PPM::findVerticalEdges( PPM& dst ) const{
    int row, column, cm1, value;
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    for(column = 0; column < getWidth(); column++){
        for(row = 0; row < getHeight(); row++){
            if(column == 0){
                cm1 = 0;
            }
            else{
                cm1 = column - 1;
            }
            value = edgePixelValue(row, column, row, cm1);
            dst.setPixel(row, column, value, value, value);
        }
    }
}

void PPM::findHorizontalEdges( PPM& dst ) const{
    int row, column, rm1, value;
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    for(row = 0; row < getHeight(); row++){
        for(column = 0; column < getWidth(); column++){
            if(row == 0){
                rm1 = 0;
            }
            else{
                rm1 = row - 1;
            }
            value = edgePixelValue(row, column, rm1, column);
            dst.setPixel(row, column, value, value, value);
        }
    }
}