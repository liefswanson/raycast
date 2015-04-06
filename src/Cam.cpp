#include "Cam.hpp"

#include <iostream>

Cam::Cam(Vec position, Vec lookAt){
	this->position  = position;
	this->lookAt    = lookAt;
	this->direction = normalize(lookAt - position);

	// this is suspicious, I dont know if this actually works
	// I dont think this will be universally true
	this->right     = normalize(cross(World::y, direction));
	this->left      = -right;
	this->up        = cross(direction, right);
	this->down      = -up;
}

Cam::Cam() : Cam(World::origin, World::origin) {}

Cam::~Cam() {}
