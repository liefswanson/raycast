#include "Color.hpp"

Color::Color(double r, double g, double b,
			 double reflectivity, double transparency,
			 double refractionIndex) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->reflectivity = reflectivity;
	this->transparency = transparency;
	this->refractionIndex = refractionIndex;
}

Color::Color() : Color(0, 0, 0, 0, 0){}

Color::~Color(){}

Color
scale(const Color& left, double scalar) {
	return Color(left.r*scalar,
				 left.g*scalar,
				 left.b*scalar,
				 left.reflectivity,
				 left.transparency,
				 left.refractionIndex);
}

Color
operator*(const Color& left, double scalar) {
	return scale(left, scalar);
}

Color
operator*(double scalar, const Color& left) {
	return scale(left, scalar);
}

Color
operator/(const Color& left, double scalar) {
	return scale(left, 1/scalar);
}


Color
add (const Color& left, const Color& right) {
	return Color(left.r + right.r,
				 left.g + right.g,
				 left.b + right.b,
				 (left.reflectivity + right.reflectivity)/2,
				 (left.transparency + right.transparency)/2,
				 (left.refractionIndex + right.refractionIndex)/2);
}

Color
operator+(const Color& left, const Color& right){
	return add(left, right);
}

Color
normalize(const Color& col){
	double scale = std::max(col.r, col.g);
	scale = std::max(scale, col.b);

	double factor = 1.0/scale;
	return col * factor;
}
