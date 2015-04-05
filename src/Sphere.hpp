#pragma once

#include <cmath>
#include "Vec.hpp"
#include "Color.hpp"
#include "Object.hpp"
#include "Constants.hpp"

class Sphere : public Object {
public:
	Vec center;
	double radius;
	double radius_sq;

	Sphere(Vec center, double radius, Color color);
	~Sphere();

	virtual double intersectWith(const Ray& ray)   const override;
	virtual Vec    normalAt     (const Vec& point) const override;
};
