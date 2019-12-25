#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_
#include <iostream>
#include <vector>

class Color {
private:
    int mRed;
    int mGreen;
    int mBlue;
public:
    Color( );
    Color( const int& red, const int& green, const int& blue );
    int getRed( ) const;
    int getGreen( ) const;
    int getBlue( ) const;
    int getChannel( const int& channel ) const;
    void setRed( const int& value );
    void setGreen( const int& value );
    void setBlue( const int& value );
    void setChannel( const int& channel, const int& value );
    void invert( const int& max_color_value );
    bool operator==( const Color& rhs ) const;
};

class ColorTable{
private:
    std::vector<Color> mColors;
public:
    ColorTable( const size_t& num_color );
    size_t getNumberOfColors( ) const;
    void setNumberOfColors( const size_t& num_color );
    const Color& operator[]( const int& i ) const;
    Color& operator[]( const int& i );
    void setRandomColor( const int& max_color_value, const size_t& position );
    void insertGradient( const Color& color1, const Color& color2, const size_t& position1, const size_t& position2 );
    int getMaxChannelValue( ) const;
};
std::ostream& operator<<( std::ostream& os, const Color& color );
#endif /*_COLORTABLE_H_ */