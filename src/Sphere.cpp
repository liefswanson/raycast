#include "Sphere.hpp"

Sphere::Sphere(Vec center, double radius, Color color) : Object() {
	this->center = center;
	this->radius = radius;
	this->color  = color;
}

Sphere::~Sphere(){}

double
Sphere::intersectWith(const Ray& ray) const{
	double a = 1;

	auto distVec = ray.origin - center;
	double b = 2 *
		(  (ray.direction.x * distVec.x)
		 + (ray.direction.y * distVec.y)
		 + (ray.direction.z * distVec.z));

	double c =
		  distVec.x * distVec.x
		+ distVec.x * distVec.x
		+ distVec.x * distVec.x
		- radius    * radius;
	return -math::quadratic(a, b, c);
}

Vec
Sphere::normalAt(const Vec& point) const {
	return World::origin;
}
