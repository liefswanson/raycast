#include "Scene.hpp"

Scene::Scene(Screen& screen, Cam& camera, std::vector<Object*>& objects, std::vector<Light*>& lights){
	this->camera  = camera;

	this->screen  = screen;

	this->objects = objects;
	this->lights  = lights;
}

Scene::~Scene(){}

void
Scene::render() {
	// offsets the screen center to the topleft pixel for use of iterating through
	Vec topLeft = camera.lookAt
		+ 0.5 * screen.width  * screen.pxScale * camera.left
		+ 0.5 * screen.height * screen.pxScale * camera.up;
	
	for(uint32_t x = 0; x < screen.width; x++) {
		Vec deltaX = (x + 0.5) * screen.pxScale * camera.right;

		for(uint32_t y = 0; y < screen.height; y++) {
			Vec deltaY = (y + 0.5) * screen.pxScale * camera.down;

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
	
	const Object* closest = NULL;
	double dist = aliases::inf;

	for (auto obj : objects) {
		auto temp = obj->intersectWith(ray);
		if (temp <  dist &&
			temp != Ray::miss) {
			dist    = temp;
			closest = obj;
		}
	}

	if (dist != Ray::miss &&
		dist != aliases::inf) {
		return closest->colorAt(ray.direction*dist);
	} else {
		return Settings::background;
	}
}
