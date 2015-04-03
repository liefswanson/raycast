#include "Ray.hpp"

Ray::Ray(Vec origin, Vec destination) {
	this->origin = origin;
	this->destination = destination;
}

Ray::Ray(Vec destination) {
	this->origin = Vec();
	this->destination = destination;
}

Ray::~Ray() {}
