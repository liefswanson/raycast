#pragma once

#include "Vec.hpp"
#include "Color.hpp"

class Light {
public:
	Vec position;
	Color color;
	double intensity;

	Light(Vec   position   = Vec  (0, 0, 0),
		  Color color      = Color(0, 0, 0, 0),
		  double intensity = 0);
	~Light();
};
