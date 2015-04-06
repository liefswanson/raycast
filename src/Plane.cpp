#include "Plane.hpp"

Plane::Plane(Vec normal, double distance, Color color) : Object() {
	this->normal   = normalize(normal);
	this->distance = distance;
	this->color    = color;
}

Plane::~Plane(){}


// FIXME not moving with adjustmont of distance to origin
double
Plane::intersectWith(const Ray& ray) const {
	double denom = dot(normal, ray.direction);
	
	// shortout, as this  would be a divide by zero
	// ie plane and line intersect at infinity, or negative infinity
	if (denom == 0) return Ray::miss;

	double num  = distance - dot(normal, ray.origin);
	double dist = num/denom;
	
	// we don't care if the intersection is behind us, just call it a miss
	if (dist <= 0) return Ray::miss;

	return dist;
}

Vec
Plane::normalAt(const Vec& point) const {
	// point purposely unused for polymorphism
	// check if point is on the plane
	return normal;
}
