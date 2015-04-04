#include "Ray.hpp"
#include "Constants.hpp"

Ray::Ray(Vec origin, Vec destination) {
	this->origin      = origin;
	this->destination = destination;
	this->direction   = normalize(origin - destination);
}

Ray::Ray(Vec destination) : Ray(World::origin, destination) {}

Ray::~Ray() {}
