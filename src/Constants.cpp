#include "Constants.hpp"

const Vec World::x = Vec(1, 0, 0);
const Vec World::y = Vec(0, 1, 0);
const Vec World::z = Vec(0, 0, 1);

const Vec World::origin = Vec(0, 0, 0);

const Color Palette::mattBlack = Color(0, 0, 0, 0);
const Color Palette::mattWhite = Color(1, 1, 1, 0);
const Color Palette::limeGreen = Color(0.5, 1, 0.5, 0.3);
const Color Palette::maroon    = Color(0.5, 0.125, 0.125, 0.3);

const double aliases::inf      = std::numeric_limits<double>::infinity();

double math::quadratic(double a, double b, double c){
	double discriminant = b*b - 4*a*c;
	
	if (discriminant > 0) {
		double smallerRoot = (-b - sqrt(discriminant))/2;

		// only return the smaller root if it is positive
		if (smallerRoot < 0) {
			return smallerRoot;
		} else {
			// might be negative but we will eliminate that later
			double biggerRoot  = (-b + sqrt(discriminant))/2;
			return biggerRoot;
		}
		
	} else {
		// imaginary numbers will result from the equation, and it should be ignored
		// as this ray does not intersect with the sphere on this plane of reality
		return aliases::inf;
	}

	return discriminant;
}
