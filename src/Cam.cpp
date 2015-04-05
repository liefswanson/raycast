#include "Cam.hpp"

#include <iostream>

Cam::Cam(Vec position, Vec lookAt){
	this->position  = position;
	this->direction = -normalize(lookAt - position);
	
	// this is suspicious, I dont know if this actually works
	// I dont think this will be universally true
	this->right     = normalize(cross(World::y, direction));
	this->up        = normalize(cross(direction, right));
}

Cam::Cam(Vec lookAt) : Cam(World::origin, lookAt) {}

Cam::~Cam() {}
