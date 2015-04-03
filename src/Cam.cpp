#include "Cam.hpp"

const Vec Cam::worldUp = Vec(0, 1, 0);

Cam::Cam(Vec position, Vec direction, Vec up){
	this->position  = position;
	this->direction = direction;
	this->up        = up;
}

Cam::Cam(Vec direction) {
	this->position  = Vec();
	this->direction = direction;
	this->up        = worldUp;
}

Cam::~Cam() {}
