#include "Sphere.hpp"

Sphere::Sphere(Vec center, double radius, Color color) : Object() {
	this->center    = center;
	this->radius    = radius;
	this->radius_sq = radius * radius;
	this->color     = color;
}

Sphere::~Sphere(){}

double
Sphere::intersectWith(const Ray& ray) const{

	auto distVec = ray.origin - center;

	double b =  dot(ray.direction, distVec);
	double c =  dot(distVec, distVec) - radius_sq;
	
	// normally this would be "b*b - 4*a*c" most of that is simplified away
	// https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
	double discriminant = b*b - c; 

	if (discriminant >= 0) {
		discriminant = sqrt(discriminant); //so we never calculate the sqrt twice

		double smallerRoot = (-b - discriminant);
		// only return the smaller root if it is positive
		if (smallerRoot > 0) return smallerRoot;

		double biggerRoot  = (-b + discriminant);
		// once again only return if positive
		if (biggerRoot > 0)  return biggerRoot;
	}
	
	// either an imaginary number or a negative number would have resulted
	// as such it will be ignored...
	// as this ray does not intersect with the sphere on this plane of reality
	return Ray::miss;
}

Vec
Sphere::normalAt(const Vec& point) const {
	return World::origin;
}
