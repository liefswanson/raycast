#include "Main.hpp"
#include <unistd.h>

std::string path = "out/output.bmp";

int main(int argc, char *argv[]) {
	ArgParse parser(argc, argv);

	if (parser.isSet("-p")) {
		path = parser.getValue("-p");
		if (path == "") {
			std::cout << Term::Red << "No path was specified by the -p flag."  << Term:: Reset << std::endl;
			return 1;
		}
	} else {
		std::cout << Term::Cyan << "Will use the default path " << Term::Yellow << "\"" << path << "\" " << Term::Reset << std::endl;
	}

    std::cout << Term::Cyan << "Rendering... " << Term::Reset;// << std::endl;
    // std::cout << Term::Cyan << "[--------------------] (  0%)" << Term::Reset << std::endl;

	Scene scene(640, 480);
	scene.render();
	
	std::cout << Term::IBlue << "Done!" << Term::Reset << std::endl;

	// TODO: this should be changed to handle incorrect paths
	// if the incorrect path does not work y/n to use the default one otherwise the rendering time is lost
	// alternatively check the path before doing the render
	try {
		writeBMP(path,
				 scene.screen.width, scene.screen.height, Settings::dpi,
				 scene.screen.bgr24(), 24);
	} catch (std::exception e) {
		std::cout << Term::Red <<  "There was a problem using the path " << Term::Yellow << "\""<< path << "\"" << Term::Red << " to save the file; are you sure the directory exists?" << Term::Reset << std::endl;
	}

    return 0;
}

