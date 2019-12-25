all: julia_set
julia_set: image_menu.o PPM.o ppm_menu.o NumberGrid.o JuliaSet.o
	g++ -std=c++11 -o julia_set image_menu.o PPM.o ppm_menu.o NumberGrid.o JuliaSet.o
image_menu.o: image_menu.cpp image_menu.h
	g++ -std=c++11 -c image_menu.cpp
PPM.o: PPM.cpp PPM.h
	g++ -std=c++11 -c PPM.cpp
NumberGrid.o: NumberGrid.cpp NumberGrid.h
	g++ -std=c++11 -c NumberGrid.cpp
JuliaSet.o: JuliaSet.cpp JuliaSet.h NumberGrid.h
	g++ -std=c++11 -c JuliaSet.cpp
ppm_menu.o: ppm_menu.cpp
	g++ -std=c++11 -c ppm_menu.cpp
clean:
	-rm -f *.o ppm_menu