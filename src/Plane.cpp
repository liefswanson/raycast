#include "Plane.hpp"

Plane::Plane(Vec normal, double distance, Color color) : Object() {
	this->normal   = normalize(normal);
	this->distance = distance;
	this->color    = color;
}

Plane::~Plane(){}


// FIXME drawing plane behind the camera.
double
Plane::intersectWith(const Ray& ray) const {
	auto denominator = dot(ray.direction, normal);
	if (denominator == 0) {
		return -aliases::inf;
	}

	auto pointOnPlane = normal * distance;
	auto numerator    = dot(normal, pointOnPlane - ray.origin);
	
	return numerator/denominator;
}

Vec
Plane::normalAt(const Vec& point) const {
	// point purposely unused for polymorphism
	// check if point is on the plane
	return normal;
}
