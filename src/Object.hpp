#pragma once

#include "Ray.hpp"
#include "Constants.hpp"

class Object {
	Color color;

public:
	Object ();
	~Object();

	virtual double intersectWith(const Ray& ray)   const;
	virtual Vec    normalAt     (const Vec& point) const;
};
