#include "Light.hpp"

Light::Light(Vec position, Color color, double intensity){
	this->position  = position;
	this->color     = color;
	this->intensity = intensity;
}

Light::~Light(){}
