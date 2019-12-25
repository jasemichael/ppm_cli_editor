#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_
#include <iostream>
#include <string>
#include <fstream>
#include "PPM.h"
#include "NumberGrid.h"
#include "JuliaSet.h"
#include "MandelbrotSet.h"
#include "ComplexFractal.h"
#include "ColorTable.h"
#include <cmath>
#include <sstream>

std::string getString(std::istream& is, std::ostream& os, const std::string& prompt);
int getInteger(std::istream& is, std::ostream& os, const std::string& prompt);
double getDouble(std::istream& is, std::ostream& os, const std::string& prompt);
int assignment1(std::istream& is, std::ostream& os);

void writeUserImage(std::istream& is, std::ostream& os, const PPM& p);
int assignment2(std::istream& is, std::ostream& os);

void showMenu( std::ostream& os );
std::string getChoice(std::istream& is, std::ostream& os);
void commentLine(std::istream& is);
void setSize( std::istream& is, std::ostream& os, PPM& src );
void setMaxColorValue( std::istream& is, std::ostream& os, PPM& src );
void setChannel( std::istream& is, std::ostream& os, PPM& src );
void setPixel( std::istream& is, std::ostream& os, PPM& src );
void clearAll( PPM& src );
void drawDiamond( std::istream& is, std::ostream& os, PPM& src );
void drawCircle( std::istream& is, std::ostream& os, PPM& src );
void drawBox( std::istream& is, std::ostream& os, PPM& src );
void takeAction( std::istream& is, std::ostream& os, const std::string& choice, PPM& input_image1, PPM& input_image2, PPM& output_image, NumberGrid& grid, ColorTable& table );

void readUserImage( std::istream& is, std::ostream& os, PPM& ppm );
int imageMenu( std::istream& is, std::ostream& os );

void plusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 );
void minusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 );
void timesEquals( std::istream& is, std::ostream& os, PPM& src );
void divideEquals( std::istream& is, std::ostream& os, PPM& src );
void plus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst );
void minus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst );
void times( std::istream& is, std::ostream& os, const PPM& src, PPM& dst );
void divide( std::istream& is, std::ostream& os, const PPM& src, PPM& dst );

int runFile( std::istream& is, std::ostream& os, PPM& input_image1, PPM& input_image2, PPM& output_image, NumberGrid& grid, ColorTable& table);

void configureGrid( std::istream& is, std::ostream& os, NumberGrid& grid );
void setGrid( std::istream& is, std::ostream& os, NumberGrid& grid );
void applyGrid( std::istream& is, std::ostream& os, NumberGrid& grid, PPM& dst );

void setFractalPlaneSize( std::istream& is, std::ostream& os, NumberGrid& grid );
void calculateFractal( std::istream& is, std::ostream& os, NumberGrid& grid );
void setJuliaParameters( std::istream& is, std::ostream& os, NumberGrid& grid );

void setJuliaFractal( std::istream& is, std::ostream& os, NumberGrid*& grid );
void setMandelbrotFractal( std::istream& is, std::ostream& os, NumberGrid*& grid );

void applyGridColorTable( std::istream& is, std::ostream& os, NumberGrid& grid, ColorTable& table, PPM& dst );
void setColorTableSize( std::istream& is, std::ostream& os, ColorTable& table );
void setColor( std::istream& is, std::ostream& os, ColorTable& table );
void setRandomColor( std::istream& is, std::ostream& os, ColorTable& table );
void setColorGradient( std::istream& is, std::ostream& os, ColorTable& table );

void calculateFractalSingleThread( std::istream& is, std::ostream& os, NumberGrid& grid );

#endif /* _IMAGE_MENU_H_ */
