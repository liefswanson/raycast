#include "Scene.hpp"

Scene::Scene(uint32_t height, uint32_t width, std::vector<Object*> objects){
	this->camera  = Cam   (Settings::camPos, Settings::screenCenter);

	this->screen  = Screen(height,   width,
						   Settings::pxScale,
						   Settings::screenCenter);

	this->objects = objects;
	this->light   = Settings::light;
}

Scene::~Scene(){}

void
Scene::render() {
	auto heightDisplace = screen.height/2;
	auto widthDisplace  = screen.width/2;

	for(uint32_t x = 0; x < screen.width; x++) {
		for(uint32_t y = 0; y < screen.height; y++) {
			
			Vec pxPosition = screen.center
				+ (x - widthDisplace  - 0.5) * Settings::pxScale * camera.right
				+ (y - heightDisplace - 0.5) * Settings::pxScale * camera.up;

			auto ray = Ray(camera.position, pxPosition);
			screen.at(x, y) = Pixel(raycast(ray));
		}
	}
}


Color
Scene::raycast(const Ray& ray) const {

	const Object* closest = NULL;
	double dist = aliases::inf;

	for (auto obj : objects) {
		auto temp = obj->intersectWith(ray);
		if(temp > -aliases::inf) {
			std::cout << temp << std::endl;
		}
		dist    = temp;
		closest = obj;
	}

	if (closest != NULL && dist > 0) {
		return closest->color;
	} else {
		return Settings::background;
	}
}
