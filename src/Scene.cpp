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
	// offsets the screen center to the topleft pixel for use of iterating through
	Vec topLeft = screen.center
		- 0.5 * screen.width  * Settings::pxScale * camera.right
		- 0.5 * screen.height * Settings::pxScale * camera.up;
	
	for(uint32_t x = 0; x < screen.width; x++) {
		Vec deltaX = (x + 0.5) * Settings::pxScale * camera.right;

		for(uint32_t y = 0; y < screen.height; y++) {
			Vec deltaY = (y + 0.5) * Settings::pxScale * camera.up;

			Vec pxPosition = topLeft + deltaX + deltaY;

			auto ray = Ray(camera.position, pxPosition);
			// FIXME colors MUST be normalized before being put in a pixel
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
		dist    = temp;
		closest = obj;
	}

	if (closest != NULL && dist > 0) {
		return closest->color;
	} else {
		return Settings::background;
	}
}
