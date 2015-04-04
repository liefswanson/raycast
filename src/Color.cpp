#include "Color.hpp"

Color::Color(double r, double g, double b, double reflectivity) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->reflectivity = reflectivity;
}

Color::Color(double bw, double reflectivity) : Color(bw, bw, bw, reflectivity){}

Color::Color() : Color(0, 0, 0, 0){}

Color::~Color(){}

Color
scale(const Color& left, double scalar) {
	return Color(left.r*scalar,
				 left.g*scalar,
				 left.b*scalar,
				 left.reflectivity*scalar);
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
add (const Color& left, const Color& right) {
	return Color(left.r + right.r,
				 left.g + right.g,
				 left.b + right.b,
				 left.reflectivity + right.reflectivity);
}

Color
operator+(const Color& left, const Color& right){
	return add(left, right);
}

Color
normalize(const Color& col){
	double scale = std::max(col.r, col.g);
	scale = std::max(scale, col.b);
	scale = std::max(scale, col.reflectivity);

	double factor = 1.0/scale;
	return col * factor;
}
