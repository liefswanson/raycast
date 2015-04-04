#pragma once

#include <cmath>
#include "Vec.hpp"
#include "Color.hpp"
#include "Object.hpp"

class Sphere : public Object {
	Vec center;
	double radius;

public:
	Sphere(Vec center, double radius, Color color);
	~Sphere();

	virtual double intersectWith(const Ray& ray)   const override;
	virtual Vec    normalAt     (const Vec& point) const override;
};
