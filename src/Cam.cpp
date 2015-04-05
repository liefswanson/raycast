#include "Cam.hpp"

#include <iostream>

Cam::Cam(Vec position, Vec lookAt){
	this->position  = position;
	std::cout << position << std::endl;
	this->direction = normalize(lookAt - position);
	std::cout << direction << std::endl;

	// this is suspicious, I dont know if this actually works
	// I dont think this will be universally true
	this->right     = normalize(cross(World::y, direction));
	std::cout << right << std::endl;
	this->up        = cross(direction, right);
	std::cout << up << std::endl;
}

Cam::Cam() : Cam(World::origin, World::origin) {}

Cam::~Cam() {}
