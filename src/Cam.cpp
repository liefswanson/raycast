#include "Cam.hpp"

const vec cam::worldUp = vec(0, 1, 0);

cam::cam(vec position, vec direction, vec up){
	this->position  = position;
	this->direction = direction;
	this->up        = up;
}

cam::cam(vec direction) {
	this->position  = vec();
	this->direction = direction;
	this->up        = worldUp;
}

cam::~cam() {}
