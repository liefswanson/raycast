#include "Main.hpp"

std::string path = "out/output.bmp";

int
main(int argc, char *argv[]) {
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
	std::cout << Term::Cyan << "Rendering... " << Term::Reset;

	// build the scene before passing it to the scene object for rendering
	
	auto objects = std::vector<Object*>();
	// Plane ground (World::y, -2, Palette::maroon);
	CheckerBoard ground(-World::x, World::z, 2, Palette::mattWhite, Palette::mattBlack, 1);
	objects.push_back(dynamic_cast<Object*>(&ground));

	Sphere sphere (Settings::camLookAt, 1, Palette::limeGreen);
	objects.push_back(dynamic_cast<Object*>(&sphere));

	auto lights = std::vector<Light*>();
	Light light(Vec(7, 10, -10), Palette::lightWhite, 1);
	lights.push_back(&light);
	
	Screen screen(640, 480, Settings::pxScale);
	Cam camera(Settings::camPos, Settings::camLookAt);

	Scene scene(screen, camera, objects, lights);

	scene.render();
	scene.screen.normalize();
	std::cout << Term::IBlue << "Done!" << Term::Reset << std::endl;

	// TODO: this should be changed to handle incorrect paths
	// if the incorrect path does not work y/n to use the default one otherwise the rendering time is lost
	// alternatively check the path before doing the render
	try {
		writeBMP24bit(path, scene.screen, Settings::dpi);
		
	} catch (std::exception e) {
		std::cout << Term::Red <<  "There was a problem using the path " << Term::Yellow << "\""<< path << "\"" << Term::Red << " to save the file; are you sure the directory exists?" << Term::Reset << std::endl;
	}

    return 0;
}
