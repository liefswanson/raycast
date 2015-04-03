#include "Main.hpp"


std::string path = "out/output.bmp";


int main(int argc, char *argv[]) {
	Screen screen(640, 480, 72);
	ArgParse parser(argc, argv);
	Cam cam(Vec(0, 2, -2));
	
	if (parser.isSet("-p")) {
		path = parser.getValue("-p");
		if (path == "") {
			std::cout << Term::Red << "No path was specified by the -p flag."  << Term:: Reset << std::endl;
			return 1;
		}
	} else {
		std::cout << Term::Cyan << "Using default the path " << Term::Yellow << "\"" << path << "\" " << Term::Reset << std::endl;
	}
	
    std::cout << Term::Cyan << "Rendering..." << Term::Reset << std::endl;


	Vec x(1, 0, 0);
	Vec y(0, 1, 0);
	Vec z(0, 0, 1);

	Vec lookAt(0, 0, 0);
	Vec diff = cam.position - lookAt;

	cam.direction = normalize(-diff);
	cam.up = Cam::worldUp;
	
	for(uint32_t x = 0; x < screen.width; x++) {
		for(uint32_t y = 0; y < screen.height; y++) {
			
		}
	}

	// TODO: this should be changed to handle incorrect paths
	// if the incorrect path does not work y/n to use the default one otherwise the rendering time is lost
	// alternatively check the path before doing the render
	try {
		writeBMP(path,
				 screen.width, screen.height, screen.dpi,
				 screen.bgr24(), 24);
	} catch (std::exception e) {
		std::cout << Term::Red <<  "There was a problem using the path " << Term::Yellow << "\""<< path << "\"" << Term::Red << " to save the file; are you sure the directory exists?" << Term::Reset << std::endl;
	}
	
    return 0;
}

