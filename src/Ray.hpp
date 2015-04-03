#pragma once
#include "Vec.hpp"

class Ray{
public:
	Vec origin;
	Vec destination;
	
	Ray(Vec origin, Vec destination);
	Ray(Vec destination);
	~Ray();
};
