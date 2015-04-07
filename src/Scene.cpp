#include "Scene.hpp"

Scene::Scene(Screen& screen, Cam& camera, std::vector<Object*>& objects, std::vector<Light*>& lights,
			 uint depth,
			 bool shadows, bool reflections, bool refractions,
			 bool stochasticDiffuse, bool superSample){
	
	this->camera  = camera;

	this->screen  = screen;

	this->objects = objects;
	this->lights  = lights;

	this->depth = depth;

	this->shadows = shadows;
	this->reflections = reflections;
	this->refractions = refractions;
	this->stochasticDiffuse = stochasticDiffuse;
	this->superSample = superSample;
}

Scene::~Scene(){}

void
Scene::render() {
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
Scene::raycast(const Ray& ray, const Object* ignore, uint depth) const {
	depth--;

	auto collision = raycollide(ray, ignore); 

	auto closest = collision.first;
	auto dist    = collision.second;
	
	// don't need to do any reflection here, we didn't hit anything
	if (dist == Ray::miss) return Settings::background;

	// TODO this should be the color of the refraction ray
	Color color = Color(0, 0, 0, 0, 0);
	
	for (auto light: lights) {
		auto point     = ray.origin + ray.direction * dist;

		auto objcol    = closest->colorAt(point);

		auto normal    = closest->normalAt(point); 
		auto direction = normalize(light->position - point);

		double diffuse  = dot(direction, normal);
		double specular = pow(diffuse, objcol.reflectivity * Settings::specularMax);

		double shadowStatus; 
		if(shadows) {
			auto temp = raycollide(Ray(point, light->position), closest);
			shadowStatus = temp.second;
		} else {
			shadowStatus = Ray::miss;
		}

		if (diffuse < 0 || shadowStatus != Ray::miss) {

			color = color + Settings::ambient * objcol;
			
		} else {
			if (depth > 0) {
				color = color + objcol.reflectivity *raycast(Ray(point, point + normal), closest, depth);
			}
			color = color +
				Settings::ambient
				* objcol

				+ diffuse
				* (1 - objcol.reflectivity) * objcol * light->intensity 

				+ specular
				* objcol.reflectivity       * objcol * light->intensity;
		}
	}
	return color;
}

std::pair<const Object*, double>
Scene::raycollide(const Ray& ray, const Object* ignore) const{

	const Object* closest = NULL;
	double dist = aliases::inf;

	for (auto obj : objects) {
		if (obj != ignore) {
			auto temp = obj->intersectWith(ray);
			if (temp <  dist &&
				temp != Ray::miss) {
				dist    = temp;
				closest = obj;
			}	
		}
	}
	if (dist == aliases::inf) dist = Ray::miss;
	
	return std::make_pair(closest, dist);
}
