#pragma once
#include "Vec.hpp"

class Ray{
public:
	const static double miss; 

	Vec origin;
	Vec destination;
	Vec direction;
	
	Ray(Vec origin, Vec destination);
	~Ray();
};
