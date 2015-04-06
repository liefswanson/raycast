#include "Scene.hpp"

Scene::Scene(Screen& screen, Cam& camera, std::vector<Object*>& objects, std::vector<Light*>& lights){
	this->camera  = camera;

	this->screen  = screen;

	this->objects = objects;
	this->lights  = lights;
}

Scene::~Scene(){}

void
Scene::render(bool superSample, uint depth) {
	// offsets the screen center to the topleft pixel for use of iterating through
	Vec topLeft = camera.lookAt
		+ 0.5 * screen.width  * screen.pxScale * camera.left
		+ 0.5 * screen.height * screen.pxScale * camera.up;

	// only used during super-sampling
	Vec leftAdjust  = 0.25 * screen.pxScale * camera.left;
	Vec rightAdjust = 0.25 * screen.pxScale * camera.right; 

	Vec upAdjust    = 0.25 * screen.pxScale * camera.up;
	Vec downAdjust  = 0.25 * screen.pxScale * camera.down;
	
	for(uint32_t x = 0; x < screen.width; x++) {
		Vec deltaX = (x + 0.5) * screen.pxScale * camera.right;

		for(uint32_t y = 0; y < screen.height; y++) {
			Vec deltaY = (y + 0.5) * screen.pxScale * camera.down;

			Vec pxPosition = topLeft + deltaX + deltaY;
			// std::cout << pxPosition << std::endl;
			
			if (superSample) {
				screen.at(x, y)
					= raycast(Ray(camera.position, pxPosition),
							  NULL, depth)
					
					+ raycast(Ray(camera.position, pxPosition + leftAdjust  + upAdjust),
							  NULL, depth)

					+ raycast(Ray(camera.position, pxPosition + rightAdjust + upAdjust),
							  NULL, depth)

					+ raycast(Ray(camera.position, pxPosition + leftAdjust  + downAdjust),
							  NULL, depth)

					+ raycast(Ray(camera.position, pxPosition + rightAdjust + downAdjust),
							  NULL, depth);	
			} else {
				screen.at(x, y)
					= raycast(Ray(camera.position, pxPosition),
							  NULL, depth);
			}
		}
	}
}

Color
Scene::raycast(const Ray& ray, const Object* ingnore, uint depth) const {
	
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

		auto point     = ray.origin + ray.direction * dist;

		auto objcol    = closest->colorAt(point);

		auto norm      = closest->normalAt(point); 
		auto direction = normalize(lights[0]->position - point);

		// FIXME this should not be the negative dot product, it is very possible the world is inverted vertically
		double factor  = -dot(direction, norm) * lights[0]->intensity;
		// if(factor < 0) std::cout << norm << " " << direction << std::endl;
		
		if (factor < 0) return objcol * Settings::ambient;

		return  objcol * Settings::ambient + objcol * factor;

	} else {
		return Settings::background;
	}
}
