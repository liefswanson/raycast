#include "Ray.hpp"
#include "Constants.hpp"

const double Ray::miss = -aliases::inf;

Ray::Ray(Vec origin, Vec destination) {
	this->origin      = origin;
	this->destination = destination;
	this->direction   = normalize(destination - origin);
}

Ray::~Ray() {}
