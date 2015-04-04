#include "Scene.hpp"

Scene::Scene(uint32_t height, uint32_t width){
	this->camera  = Cam   (Settings::camPos, Settings::screenCenter);

	this->screen  = Screen(height,   width,
						   Settings::pxScale,
						   Settings::screenCenter);

	this->objects = Settings::objects;
	this->light   = Settings::light;
}

Scene::~Scene(){}

void
Scene::render() {
	std::cout << camera.right.x << ' ' << camera.right.y << ' ' << camera.right.z << ' ' << std::endl;
	std::cout << camera.direction.x << ' ' << camera.direction.y << ' ' << camera.direction.z << ' ' << std::endl;
	auto heightDisplace = screen.height/2;
	auto widthDisplace  = screen.width/2;

	for(uint32_t x = 0; x < screen.width; x++) {
		for(uint32_t y = 0; y < screen.height; y++) {

			auto pxPosition = screen.center
				+ (x - widthDisplace)  * Settings::pxScale * camera.right
				+ (y - heightDisplace) * Settings::pxScale * camera.up;

			screen.at(x, y) = Pixel(raycast(pxPosition));
		}
	}
}

Color
Scene::raycast(const Vec& target) const {
	auto ray = Ray(camera.position, target);

	const Plane* closest = NULL;
	double dist = inf;

	for (auto& obj : objects) {
		auto temp = obj.intersectWith(ray);
		std::cout << temp << std::endl;
		if (temp < dist && temp > 0) {
			dist    = temp;
			closest = &obj;
		}
	}

	if (closest != NULL && dist > 0) {
		return closest->color;
	} else {
		return Palette::mattWhite;
	}
}
