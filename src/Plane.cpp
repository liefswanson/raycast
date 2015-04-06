#include "Plane.hpp"

Plane::Plane(Vec normal, double distance, Color color) : Object() {
	this->normal   = normalize(normal);
	this->distance = distance;
	this->color    = color;
}

Plane::~Plane(){}


// FIXME not moving with adjustmont of distance to origin
double
Plane::intersectWith(const Ray& ray) const {
	double denom = dot(normal, ray.direction);
	
	// shortout, as this  would be a divide by zero
	// ie plane and line intersect at infinity, or negative infinity
	if (denom == 0) return Ray::miss;

	double num  = distance - dot(normal, ray.origin);
	double dist = num/denom;
	
	// we don't care if the intersection is behind us, just call it a miss
	if (dist < 0) return Ray::miss;

	return dist;
}

Vec
Plane::normalAt(const Vec& point) const {
	// point purposely unused for polymorphism
	// check if point is on the plane
	return normal;
}

Color
Plane::colorAt(const Vec& point) const {
	return color;
}

//----------------------------------------------------------------
// CheckerBoard
//----------------------------------------------------------------

CheckerBoard::CheckerBoard(Vec right, Vec forward, double distance,
						   Color color, Color color2, double size) :
	Plane(cross(forward, right), distance, color){

	this->right   = normalize(right);
	this->forward = normalize(forward);
	this->color2  = color2;
	this->size    = size;
}

CheckerBoard::~CheckerBoard(){}

Color
CheckerBoard::colorAt(const Vec& point) const {
	// start at the origin and go out in both the right and forward directions
	// check if the results are both even or both odd when divided by their corresponding vectors
	// true color1
	// false color2
	double distR = dot(point, right);
	double distF = dot(point, forward);

	uint check  = trunc(distR/size); 
	uint check2 = trunc(distF/size);

	if (check%2 == check2%2){
		return color;	
	} else {
		return color2;
	}
}
