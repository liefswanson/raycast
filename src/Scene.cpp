#include "Scene.hpp"

Scene::Scene(uint32_t height, uint32_t width, std::vector<Object*> objects){
	this->camera  = Cam   (Settings::camPos, Settings::camLookAt);

	this->screen  = Screen(height, width, Settings::pxScale);

	this->objects = objects;
	this->light   = Settings::light;
}

Scene::~Scene(){}

void
Scene::render() {
	// offsets the screen center to the topleft pixel for use of iterating through
	Vec topLeft = camera.lookAt
		- 0.5 * screen.width  * screen.pxScale * camera.right
		- 0.5 * screen.height * screen.pxScale * camera.up;
	
	for(uint32_t x = 0; x < screen.width; x++) {
		Vec deltaX = (x + 0.5) * screen.pxScale * camera.right;

		for(uint32_t y = 0; y < screen.height; y++) {
			Vec deltaY = (y + 0.5) * screen.pxScale * camera.up;

			Vec pxPosition = topLeft + deltaX + deltaY;
			// std::cout << pxPosition << std::endl;
			
			auto ray = Ray(camera.position, pxPosition);
			// FIXME colors MUST be normalized before being put in a pixel
			screen.at(x, y) = Pixel(raycast(ray));
		}
	}
}


Color
Scene::raycast(const Ray& ray) const {
	using namespace aliases;
	
	const Object* closest = NULL;
	double dist = inf;

	for (auto obj : objects) {
		auto temp = obj->intersectWith(ray);
		if (temp <  dist &&
			temp != miss) {
			dist    = temp;
			closest = obj;
		}
	}

	if (dist != miss &&
		dist != inf) {
		return closest->color;
	} else {
		return Settings::background;
	}
}
