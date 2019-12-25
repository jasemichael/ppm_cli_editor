all: ppm
ppm: image_menu.o PPM.o ppm_menu.o
	g++ -std=c++11 -o ppm image_menu.o PPM.o ppm_menu.o
image_menu.o: image_menu.cpp image_menu.h
	g++ -std=c++11 -c image_menu.cpp
PPM.o: PPM.cpp PPM.h
	g++ -std=c++11 -c PPM.cpp
ppm_menu.o: ppm_menu.cpp
	g++ -std=c++11 -c ppm_menu.cpp
clean: -rm -f image_menu.o PPM.o ppm_menu.o ppm
