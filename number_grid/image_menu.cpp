//Jase Wilson
#include "image_menu.h"


//Assignment 1
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

//Assignment 2
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

//Assignment 3
void showMenu(std::ostream& os){
    os << "\nActions available:" << "\n\nread1) Read file into input image 1." << "\nread2) Read file into input image 2." << "\nwrite) Write output image to file." << "\ncopy) Copy input image 1 to output image."
    << "\nred-gray) Set output image from input image 1's grayscale from red." << "\ngreen-gray) Set output image from input image 1's grayscale from green."
    << "\nblue-gray) Set output image from input image 1's grayscale from blue." << "\nlinear-gray) Set output image from input image 1's grayscale from linear colorimetric."
    << "\nv-edge) Set output image from input image 1's vertical edge detection" << "\nh-edge) Set output image from input image 1's horizontal edge detection"
    <<"\n+) Set output image from sum of input image 1 and input image 2" << "\n+=) Set input image 1 by adding in input image 2"
    << "\n-) Set output image from difference of input image 1 and input image 2" << "\n-=) Set input image 1 by subtracting input image 2"
    << "\n*) Set output image from input image 1 multiplied by a number" << "\n*=) Set input image 1 by multiplying by a number"
    << "\n/) Set output image from input image 1 divided by a number" << "\n/=) Set input image 1 by dividing by a number" << "\n# Comment to end of line"
    << "\nsize) Set the size of input image 1" << "\nmax) Set the max color value of input image 1" << "\nchannel) Set a channel value in input image 1"
    << "\npixel) Set a pixel's 3 values in input image 1" << "\nclear) Set all pixels to 0,0,0 in input image 1" << "\ndiamond) Draw a diamond shape in input image 1"
    << "\ncircle) Draw a circle shape in input image 1" << "\nbox) Draw a box shape in input image 1" << "grid) Configure the grid." << "grid-set) Set a single value in the grid."
    << "grid-apply) Use the grid values to set colors in the output image." << "\nquiet) Toggle output quieting" << "\nrun) Run commands from another file" << "\nquit) Quit" << "\n\n";
}

std::string getChoice(std::istream& is, std::ostream& os){
    std::string res = getString(is, os, "Choice? ");
    return res;
}

void commentLine(std::istream& is) {
    std::string comment;
    std::getline(is, comment);
}

void setSize( std::istream& is, std::ostream& os, PPM& src ){
    int height = getInteger(is, os, "Height? ");
    int width = getInteger(is, os, "Width? ");
    src.setHeight(height);
    src.setWidth(width);
}

void setMaxColorValue( std::istream& is, std::ostream& os, PPM& src ){
    int mcv = getInteger(is, os, "Max color value? ");
    src.setMaxColorValue(mcv);
}

void setChannel(std::istream& is, std::ostream& os, PPM& src){
    int row = getInteger(is, os, "Row? ");
    int column = getInteger(is, os, "Column? ");
    int channel = getInteger(is, os, "Channel? ");
    int value = getInteger(is, os, "Value? ");
    src.setChannel(row, column, channel, value);
}

void setPixel( std::istream& is, std::ostream& os, PPM& src ){
    int row = getInteger(is, os, "Row? ");
    int column = getInteger(is, os, "Column? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");
    src.setPixel(row, column, red, green, blue);
}

void clearAll( PPM& src ){
    int row, column;
    for(row = 0; row < src.getHeight(); row++){
        for(column = 0; column < src.getWidth(); column++){
            src.setPixel(row, column, 0, 0, 0);
        }
    }
}

void drawDiamond( std::istream& is, std::ostream& os, PPM& src ){
    int cRow, cColumn, size, red, green, blue, row, column;
    cRow = getInteger(is, os, "Center Row? ");
    cColumn = getInteger(is, os, "Center Column? ");
    size = getInteger(is, os, "Size? ");
    red = getInteger(is, os, "Red? ");
    green = getInteger(is, os, "Green? ");
    blue = getInteger(is, os, "Blue? ");
    for(row = 0; row < src.getHeight(); row++){
        for(column = 0; column < src.getWidth(); column++){
            int xDif = std::abs(cRow - row);
            int yDif = std::abs(cColumn - column);
            int total = xDif + yDif;
            if(total <= size){
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}

void drawCircle( std::istream& is, std::ostream& os, PPM& src ){
    int cRow, cColumn, radius, red, green, blue, row, column;
    cRow = getInteger(is, os, "Center Row? ");
    cColumn = getInteger(is, os, "Center Column? ");
    radius = getInteger(is, os, "Radius? ");
    red = getInteger(is, os, "Red? ");
    green = getInteger(is, os, "Green? ");
    blue = getInteger(is, os, "Blue? ");
    for(row = 0; row < src.getHeight(); row++){
        for(column = 0; column < src.getWidth(); column++){
            int rowDif = (cRow - row);
            rowDif*=rowDif;
            int columnDif = (cColumn - column);
            columnDif*=columnDif;
            double total = std::sqrt(rowDif+columnDif);
            if(total <= radius){
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}


void drawBox( std::istream& is, std::ostream& os, PPM& src ){
    int tRow, lColumn, rColumn, bRow, red, green, blue, row, column;
    tRow = getInteger(is, os, "Top Row? ");
    lColumn = getInteger(is, os, "Left Column? ");
    bRow = getInteger(is, os, "Bottom Row? ");
    rColumn = getInteger(is, os, "Right Column? ");
    red = getInteger(is, os, "Red? ");
    green = getInteger(is, os, "Green? ");
    blue = getInteger(is, os, "Blue? ");
    for(row = 0; row < src.getHeight(); row++){
        for(column = 0; column < src.getWidth(); column++){
            if(row <= bRow && row >= tRow && column <= rColumn && column >= lColumn){
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}

void takeAction(std::istream& is, std::ostream& os, const std::string& choice, PPM& input_image1, PPM& input_image2, PPM& output_image, NumberGrid& grid){
    (void)input_image2;
    if(choice == "copy"){
        output_image = input_image1;
    }
    else if(sizeof(choice) > 0 && choice[0] ==  '#'){
        commentLine(is);
    }
    else if(choice == "write"){
        writeUserImage(is, os, output_image);
    }
    else if(choice == "size"){
        setSize(is, os, input_image1);
    }
    else if(choice == "max"){
        setMaxColorValue(is, os, input_image1);
    }
    else if(choice == "channel"){
        setChannel(is, os, input_image1);
    }
    else if(choice == "pixel"){
        setPixel(is, os, input_image1);
    }
    else if(choice == "clear"){
        clearAll(input_image1);
    }
    else if(choice == "diamond"){
        drawDiamond(is, os, input_image1);
    }
    else if(choice == "circle"){
        drawCircle(is, os, input_image1);
    }
    else if(choice == "box"){
        drawBox(is, os, input_image1);
    }
    else if(choice == "quit"){
        return;
    }
    else if(choice == "read1"){
        readUserImage(is, os, input_image1);
    }
    else if(choice == "red-gray"){
        input_image1.grayFromRed(output_image);
    }
    else if(choice == "green-gray"){
        input_image1.grayFromGreen(output_image);
    }
    else if(choice == "blue-gray"){
        input_image1.grayFromBlue(output_image);
    }
    else if(choice == "linear-gray"){
        input_image1.grayFromLinearColorimetric(output_image);
    }
    else if(choice == "read2"){
        readUserImage(is, os, input_image2);
    }
    else if(choice == "+"){
        plus(is, os, input_image1, input_image2, output_image);
    }
    else if(choice == "+="){
        plusEquals(is, os, input_image1, input_image2);
    }
    else if(choice == "-"){
        minus(is, os, input_image1, input_image2, output_image);
    }
    else if(choice == "-="){
        minusEquals(is, os, input_image1, input_image2);
    }
    else if(choice == "*"){
        times(is, os, input_image1, output_image);
    }
    else if(choice == "*="){
        timesEquals(is, os, input_image1);
    }
    else if(choice == "/"){
        divide(is, os, input_image1, output_image);
    }
    else if(choice == "/="){
        divideEquals(is, os, input_image1);
    }
    else if(choice == "v-edge"){
        input_image1.findVerticalEdges(output_image);
    }
    else if(choice == "h-edge"){
        input_image1.findHorizontalEdges(output_image);
    }
    else if(choice == "run"){
        runFile(is, os, input_image1, input_image2, output_image, grid);
    }
    else if(choice == "quiet"){
    }
    else if(choice == "grid"){
        configureGrid(is, os, grid);
    }
    else if(choice == "grid-set"){
        setGrid(is, os, grid);
    }
    else if(choice == "grid-apply"){
        applyGrid(is, os, grid, output_image);
    }
    else{
        os << "Unkown action '" << choice << "'." << std::endl;
    }
}

int imageMenu( std::istream& is, std::ostream& os ){
    PPM input_image1, input_image2, output_image;
    NumberGrid grid;
    std::string choice;
    bool quiet = false;
    std::stringstream ss;
    while(choice != "quit"){
        if(choice == "quiet"){
            quiet = !quiet;
        }
        if(quiet){
            choice = getChoice(is, ss);
            takeAction(is, ss, choice, input_image1, input_image2, output_image, grid);
        }
        else {
            showMenu(os);
            choice = getChoice(is, os);
            takeAction(is, os, choice, input_image1, input_image2, output_image, grid);
        }
    }
    return 0;
}

void readUserImage( std::istream& is, std::ostream& os, PPM& ppm ){
    std::string filename = getString(is, os, "Input filename? ");
    std::ifstream fin(filename);
    fin >> ppm;
    fin.close();
}

void plusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 ){
    (void)is, (void)os;
    src1 += src2;
}
void minusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 ){
    (void)is, (void)os;
    src1 -= src2;
}
void timesEquals( std::istream& is, std::ostream& os, PPM& src ){
    double factor = getDouble(is, os, "Factor? ");
    src *= factor;
}
void divideEquals( std::istream& is, std::ostream& os, PPM& src ){
    double factor = getDouble(is, os, "Factor? ");
    src /= factor;
}
void plus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst ){
    (void)is, (void)os;
    dst = src1 + src2;
}
void minus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst ){
    (void)is, (void)os;
    dst = src1 - src2;
}
void times( std::istream& is, std::ostream& os, const PPM& src, PPM& dst ){
    double factor = getDouble(is, os, "Factor? ");
    dst = src * factor;
}
void divide( std::istream& is, std::ostream& os, const PPM& src, PPM& dst ){
    double factor = getDouble(is, os, "Factor? ");
    dst = src / factor;
}

int runFile( std::istream& is, std::ostream& os, PPM& input_image1, PPM& input_image2, PPM& output_image, NumberGrid& grid ){
    std::string filename, choice;
    filename = getString(is, os, "File? ");
    std::ifstream fin(filename);
    if(!fin){
        return 1;
    }
    std::stringstream ss;
    while(choice != "quit" && fin.good()){
        choice = getChoice(fin, ss);
        takeAction(fin, ss, choice, input_image1, input_image2, output_image, grid);
    }
    return 0;
}

void configureGrid( std::istream& is, std::ostream& os, NumberGrid& grid ){
    int height, width, gmv;
    height = getInteger(is, os, "Grid Height? ");
    width = getInteger(is, os, "Grid Width? ");
    gmv = getInteger(is, os, "Grid Max Value? ");
    grid.setGridSize(height, width);
    grid.setMaxNumber(gmv);
}
void setGrid( std::istream& is, std::ostream& os, NumberGrid& grid ){
    int gRow, gColumn, gValue;
    gRow = getInteger(is, os, "Grid Row? ");
    gColumn = getInteger(is, os, "Grid Column? ");
    gValue = getInteger(is, os, "Grid Value? ");
    grid.setNumber(gRow, gColumn, gValue);
}
void applyGrid( std::istream& is, std::ostream& os, NumberGrid& grid, PPM& dst ){
    (void) is;
    (void) os;
    grid.setPPM(dst);
}