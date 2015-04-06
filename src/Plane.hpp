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
	virtual Color  colorAt      (const Vec& point) const override;
};

class CheckerBoard : public Plane {
public:
	Vec    right;
	Vec    forward;
	Color  color2;
	double size;

	CheckerBoard(Vec right, Vec forward, double distance,
				 Color color, Color color2, double size);
	~CheckerBoard();

	virtual Color colorAt (const Vec& point) const override;
};
