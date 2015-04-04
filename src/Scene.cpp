#include "Scene.hpp"

Scene::Scene(uint32_t height, uint32_t width){
	camera = Cam   (Settings::camPos, Settings::screenCenter);

	this->screen = Screen(height, width, Settings::pxScale,
						  Settings::screenCenter);

	objects = Settings::objects;
	light   = Settings::light;
}

Scene::~Scene(){}

void
Scene::render() {
	for(uint32_t x = 0; x < screen.width; x++) {
		for(uint32_t y = 0; y < screen.height; y++) {
			
		}
	}
}
