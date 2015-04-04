#include "Light.hpp"

Light::Light(Vec position, Color color){
	this->position = position;
	this->color    = color;
}

Light::~Light(){}
