#pragma once

#include "Object.hpp"

class Plane : public Object {
public:
	Vec    normal;
	double distance;
	Color  color;

	Plane(Vec normal, double distance, Color color);
	~Plane();

	double intersectWith(const Ray& ray)   const override;
	Vec    normalAt     (const Vec& point) const override;
};
