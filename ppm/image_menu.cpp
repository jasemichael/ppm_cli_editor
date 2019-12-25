//Jase Wilson
#include "image_menu.h"

std::string getString(std::istream& is, std::ostream& os, const std::string& prompt){
	std::string res;
	os << prompt;
	is >> res;	
	return res;
}

int getInteger(std::istream& is, std::ostream& os, const std::string& prompt){
	int num;
	os << prompt;
	is >> num;
	return num;
}

double getDouble(std::istream& is, std::ostream& os, const std::string& prompt){
	double num;
	os << prompt;
	is >> num;
	return num;
}

int assignment1(std::istream& is, std::ostream& os){
	std::string color;
	int repeat;
	double num;
	color = getString(is, os, "What's your favorite color? ");
	repeat = getInteger(is, os, "What's your favorite integer? ");
	num = getDouble(is, os, "What's your favorite number? ");
	int i;
	for(i=0; i<repeat; i++){
	os << i+1 << " " << color << " " << num << "\n";
	}
	return repeat;
}

void writeUserImage(std::istream& is, std::ostream& os, const PPM& p){
    std::string x = getString(is, os, "Output filename? ");
    std::ofstream fout(x);
    fout << p;
    fout.close();
}

int assignment2(std::istream& is, std::ostream& os){
    int height = getInteger(is, os, "Image height? ");
    int width = getInteger(is, os, "Image width? ");
    int max_color = ( height + width ) / 3;
    PPM p(height, width);
    p.setMaxColorValue(max_color);
    int row = 0;
    int column = 0;
    int red;
    int blue;
    int green;
    for(row = 0;row < p.getHeight(); row++){
        for(column = 0; column < p.getWidth(); column++){
            red = p.getMaxColorValue();
            blue = p.getMaxColorValue();
            green = (row + column) % (p.getMaxColorValue() + 1);
            if(row < p.getHeight()/2){
                red = 0;
            }
            if(column < p.getWidth()/2){
                blue = 0;
            }
            p.setPixel(row, column, red, green, blue);
        }
    }
    writeUserImage(is, os, p);
    return 0;
}
