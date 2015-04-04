#pragma once

#include "Object.hpp"

class Plane : public Object {
public:
	Vec    normal;
	double distance;

	Plane(Vec normal, double distance, Color color);
	~Plane();

	virtual double intersectWith(const Ray& ray)   const override;
	virtual Vec    normalAt     (const Vec& point) const override;
};
