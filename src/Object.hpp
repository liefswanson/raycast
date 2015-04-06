#pragma once

#include "Ray.hpp"
#include "Constants.hpp"

class Object {
public:
	Color color;

	Object ();
	~Object();

	virtual double intersectWith(const Ray& ray)      const = 0;
	virtual Vec    normalAt     (const Vec& point)    const = 0;
	virtual Color  colorAt      (const Vec& position) const = 0;
};
