#include "Object.hpp"

Object::Object(){
	this->color = Palette::mattBlack;
}

Object::~Object(){};


double
Object::intersectWith(const Ray& ray) const {
	return 0;
}

Vec
Object::normalAt(const Vec& point) const {
	return World::origin;
}
