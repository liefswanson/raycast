#include "Ray.hpp"

ray::ray(vec origin, vec destination) {
	this->origin = origin;
	this->destination = destination;
}

ray::ray(vec destination) {
	this->origin = vec();
	this->destination = destination;
}

ray::~ray() {}
