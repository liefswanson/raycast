#include "Plane.hpp"

Plane::Plane(Vec normal, double distance, Color color) : Object() {
	this->normal   = normal;
	this->distance = distance;
	this->color    = color;
}

Plane::~Plane(){}


// FIXME drawing plane behind the camera.
double
Plane::intersectWith(const Ray& ray) const {
	auto a = dot(ray.direction, normal);
	// parrallel to plane
	if (a == 0) {
		return inf;
	}

	auto b = dot(normal, -(ray.direction + (normal * distance))); 
	return b/a;
}

Vec
Plane::normalAt(const Vec& point) const {
	// check if point is on the plane
	return normal;
}
