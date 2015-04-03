#pragma once
#include "Vec.hpp"

class ray{
public:
	vec origin;
	vec destination;
	
	ray(vec origin, vec destination);
	ray(vec destination);
	~ray();
};
