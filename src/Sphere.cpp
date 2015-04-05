#include "Sphere.hpp"

Sphere::Sphere(Vec center, double radius, Color color) : Object() {
	this->center = center;
	this->radius = radius;
	this->color  = color;
}

Sphere::~Sphere(){}

// TODO stub
double
Sphere::intersectWith(const Ray& ray) const{
	
	return 0;
}

// TODO stub
Vec
Sphere::normalAt(const Vec& point) const {
	return World::origin;
}
