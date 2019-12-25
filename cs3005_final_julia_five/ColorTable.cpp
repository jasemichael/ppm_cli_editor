#include "ColorTable.h"
#include <iostream>

//Color class implementations
Color::Color() {
    mRed = 0;
    mGreen = 0;
    mBlue = 0;
}

Color::Color(const int &red, const int &green, const int &blue) {
    mRed = red;
    mGreen = green;
    mBlue = blue;
}

int Color::getRed( ) const{
    return mRed;
}

int Color::getGreen( ) const{
    return mGreen;
}

int Color::getBlue( ) const{
    return mBlue;
}

int Color::getChannel( const int& channel ) const{
    if(channel == 0){return mRed;}
    else if (channel == 1){return mGreen;}
    else if (channel == 2){return mBlue;}
    else{return -1;}
}

void Color::setRed( const int& value ){
    if(value >= 0){
        mRed = value;
    }
}

void Color::setGreen( const int& value ){
    if(value >= 0){
        mGreen = value;
    }
}

void Color::setBlue( const int& value ){
    if(value >= 0){
        mBlue = value;
    }
}

void Color::setChannel( const int& channel, const int& value ){
    if(channel <= 2 && channel >= 0){
        if(value < 0){
            return;
        }
        if(channel == 0){
            mRed = value;
        }
        else if(channel == 1){
            mGreen = value;
        }
        else if(channel == 2){
            mBlue = value;
        }
    }
}

void Color::invert( const int& max_color_value ){
    if(max_color_value < getRed() || max_color_value < getGreen() || max_color_value < getBlue()){
        return;
    }
    setRed(max_color_value - getRed());
    setGreen(max_color_value - getGreen());
    setBlue(max_color_value - getBlue());
}

bool Color::operator==( const Color& rhs ) const{
    if(getRed() == rhs.getRed() && getGreen() == rhs.getGreen() && getBlue() == rhs.getBlue()){
        return true;
    }
    return false;
}



std::ostream& operator<<( std::ostream& os, const Color& color ){
    os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
    return os;
}


//ColorTable Class Implementations
ColorTable::ColorTable( const size_t& num_color ){
    mColors.resize(num_color);
}

size_t ColorTable::getNumberOfColors( ) const{
    return mColors.size();
}

void ColorTable::setNumberOfColors( const size_t& num_color ){
    mColors.resize(num_color);
}

const Color& ColorTable::operator[]( const int& i ) const{
    if(i >= 0 && i < int(getNumberOfColors())){
        return mColors[i];
    }
    static Color ec( -1, -1, -1 );
    return ec;
}

Color& ColorTable::operator[]( const int& i ){
    if(i >= 0 && i < int(getNumberOfColors())){
        return mColors[i];
    }
    static Color ec( -1, -1, -1 );
    static Color c( -1, -1, -1 );
    c = ec;
    return c;
}

void ColorTable::setRandomColor( const int& max_color_value, const size_t& position ){
    if(int(position) >= 0 && position < getNumberOfColors()){
        if(max_color_value >= 0){
            int i;
            for(i=0; i < 3; i++) {
                mColors[position].setChannel(i, rand() % (max_color_value + 1));
            }
        }
    }
}

void ColorTable::insertGradient( const Color& color1, const Color& color2, const size_t& position1, const size_t& position2 ){
    if(position1 < position2){
        if(position2 < getNumberOfColors()){
            int i;
            double red_step, green_step, blue_step, r_i, g_i, b_i;
            red_step = double(color2.getRed() - color1.getRed()) / double(position2 - position1);
            green_step = double(color2.getGreen() - color1.getGreen()) / double(position2 - position1);
            blue_step = double(color2.getBlue() - color1.getBlue()) / double(position2 - position1);
            for(i = 0;i < int(position2-position1)+1; i++){
                r_i = color1.getRed() + (i * red_step);
                g_i = color1.getGreen() + (i * green_step);
                b_i = color1.getBlue() + (i * blue_step);
                mColors[position1 + i].setRed(r_i);
                mColors[position1 + i].setGreen(g_i);
                mColors[position1 + i].setBlue(b_i);
            }
        }
    }
}

int ColorTable::getMaxChannelValue( ) const{
    int i, j, max_color;
    max_color = 0;
    for(i=0; i < int(getNumberOfColors()); i++){
        for(j=0;j < 3; j++){
            int color = mColors[i].getChannel(j);
            if(color > max_color){
                max_color = color;
            }
        }
    }
    return max_color;
}