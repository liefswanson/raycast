#include "Main.hpp"


static void argStatus(std::string arg, bool flag) {
	std::cout << Term::Cyan << arg << ": ";
	if (flag) {
		std::cout << Term::IGreen << "enabled";
	} else {
		std::cout << Term::IRed << "disabled";
	}
	std::cout << Term::Reset << std::endl;
}

static void notImplemented(std::string arg) {
	std::cout << Term::Cyan << arg << ": ";
	std::cout << Term::IPurple << "not implemented";
	std::cout << Term::Reset << std::endl;
}

int
main(int argc, char *argv[]) {
	ArgParse parser(argc, argv);

	bool userScene;
	bool defaultScene;

	bool depthSet;
	uint depth;

	bool shadows;

	bool reflections;

	bool refractions;

	bool chessBoard;

	bool stochasticDiffuse;

	bool superSample;
	

	// ------------------------------------------------------------------------------------------
	// [-u | -d] < recursion_depth > FIXME
	// ------------------------------------------------------------------------------------------

	userScene = parser.isSet("-u");
	defaultScene = parser.isSet("-d");
	if (userScene && defaultScene) {
		std::cout << Term::IRed << "the [-u | -d] flags cannot both be set at once"
				  << Term::Reset << std::endl;
		return 1;
	}

	if (userScene) {
		std::cout <<  Term::Cyan << "Will construct the" << Term::Yellow << " user Scene " << std::endl;
	} else if (defaultScene) {
		std::cout << Term::Cyan << "Will construct the" << Term::Yellow << " default Scene " << std::endl;
	} else {
		std::cout << Term::IRed << "neither the of the [-d | -u] flags were set"
				  << Term::Reset << std::endl;
		return 1;
	}
	
	depthSet = userScene || defaultScene;
	if (depthSet) {
		auto temp = parser.getValue("-d");
		if (temp == "") {
			temp = parser.getValue("-u");
		}			
		if (temp == "") {
			std::cout << Term::IRed << "No depth was specified after the first flag [-u | -d]"
					  << Term::Reset << std::endl;
			return 1;
		} else {
			std::istringstream(temp) >> depth;
			if (depth == 0) {
				std::cout << Term::IRed << "The value specified for the depth  was not an integer or was 0"
					  << Term::Reset << std::endl;
				std::cout << Term::Cyan << "Will use the default depth "
				  << Term::Yellow << Settings::defaultDepth << Term::Reset << std::endl;
			} else {
				std::cout << Term::Cyan << "Will use the specified depth "
						  << Term::Yellow << depth << Term::Reset << std::endl;
		    }
		}
	}

	// ------------------------------------------------------------------------------------------
	// +s FIXME does not work with more than one light
	// ------------------------------------------------------------------------------------------

	shadows = parser.isSet("+s");
	argStatus("shadows", shadows);
	
	// ------------------------------------------------------------------------------------------
	// +l DONE may also have a problem with more than one light
	// ------------------------------------------------------------------------------------------

	reflections = parser.isSet("+l");
	argStatus("reflection", reflections);

	// ------------------------------------------------------------------------------------------
	// +r TODO
	// ------------------------------------------------------------------------------------------
	
	refractions = parser.isSet("+r");
	notImplemented("refraction");

	// ------------------------------------------------------------------------------------------
	// +c DONE
	// ------------------------------------------------------------------------------------------
	
	chessBoard  = parser.isSet("+c");
	argStatus("Chess board", chessBoard);

	// ------------------------------------------------------------------------------------------
	// +f TODO
	// ------------------------------------------------------------------------------------------

	stochasticDiffuse = parser.isSet("+f");
	notImplemented("stochastic diffusion");

	// ------------------------------------------------------------------------------------------
	// +p DONE
	// ------------------------------------------------------------------------------------------

	superSample = parser.isSet("+p");
	argStatus("Super sampling", superSample);

	// ------------------------------------------------------------------------------------------
	// -p DONE
	// ------------------------------------------------------------------------------------------
	
	std::string path;
	bool customPath;

	customPath  = parser.isSet("-p");
	if (customPath) {
		path = parser.getValue("-p");
		if (path == "") {
			std::cout << Term::IRed << "No -p flag was used, but no path was specified after it"
					  << Term::Reset << std::endl;
			return 1;
		} else {
			std::cout << Term::Cyan << "Will use the specified path "
					  << Term::Yellow << "\"" << path << "\" " << Term::Reset << std::endl;
		}
	} else {
		path = Settings::defaultPath;
		std::cout << Term::Cyan << "Will use the default path "
				  << Term::Yellow << "\"" << Settings::defaultPath << "\" " << Term::Reset << std::endl;
	}

	std::cout << Term::Cyan << "Rendering... " << Term::Reset;

	// build the scene before passing it to the scene object for rendering
	
	auto objects = std::vector<Object*>();
	CheckerBoard ground(World::x, World::z, -2, Palette::muddyRed, Palette::mattWhite, 1);
	if (chessBoard) objects.push_back(dynamic_cast<Object*>(&ground));

	Sphere defred  (Settings::camLookAt
					- 1.5 * World::x
					- 0.5 * World::y,
					1, Palette::crimson);
	Sphere defblue (Settings::camLookAt
					+ 0.5 * World::x
					- 0.95 * World::z
					- 0.6 * World::y,
					0.9, Palette::paleBlue);
	Sphere defgreen(Settings::camLookAt
					- 0.8 * World::x
					- 0.5 * World::z
					+ 1.2 * World::y,
					0.65, Palette::limeGreen);
	if (defaultScene) {
		objects.push_back(dynamic_cast<Object*>(&defred));	
		objects.push_back(dynamic_cast<Object*>(&defgreen));
		objects.push_back(dynamic_cast<Object*>(&defblue));
	}

	auto lights = std::vector<Light*>();
	Light light(Settings::camPos + Vec(-12, 20, -1), Palette::mattWhite, 1);
	Light light2(Settings::camPos + Vec(12, -1, 1), Palette::mattWhite, 0.25);
	lights.push_back(&light);
	// lights.push_back(&light2);

	Screen screen(512, 512, Settings::pxScale);
	Cam camera(Settings::camPos, Settings::camLookAt);

	Scene scene(screen, camera, objects, lights,
				depth,
				shadows, reflections, refractions,
				stochasticDiffuse, superSample);

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
