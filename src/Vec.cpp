#include "Vec.hpp"

Vec::Vec(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec::Vec(double val) : Vec(val, val, val){}

Vec::Vec() : Vec(0, 0, 0){}

Vec::~Vec(){}


double
Vec::magnitude() const{
	return sqrt(x*x + y*y + z*z);
}




// friends


Vec
normalize(const Vec& v){
	double s = 1/v.magnitude();
	return s * v;
}

Vec
negative(const Vec& v) {
	return Vec(-v.x, -v.y, -v.z);
}

Vec
operator-(const Vec& v){
	return negative(v);
}

Vec
scale(const Vec& v, const double& scalar) {
	return Vec (v.x * scalar,
				v.y * scalar,
				v.z * scalar);
}

Vec
operator*(const Vec& v, const double& scalar){
	return scale(v, scalar);
}

Vec
operator*(double scalar, const Vec& v){
	return scale(v, scalar);
}

double 
dot(const Vec& left, const Vec& right){
	return left.x * right.x
		+  left.y * right.y
		+  left.z * right.z;
}

double
operator*(const Vec& left, const Vec& right){
	return dot(left, right);
}

Vec
cross(const Vec& left, const Vec& right) {
	return Vec(left.y*right.z - left.z*right.y,
			   left.x*right.z - left.z*right.x,
			   left.x*right.y - left.y*right.x);
}

Vec
operator^(const Vec& left, const Vec& right){
	return cross(left, right);
}

Vec
add (const Vec& left, const Vec& right) {
	return Vec(left.x + right.x,
			   left.y + right.y,
			   left.z + right.z);
}

Vec
sub(const Vec& left, const Vec& right) {
	return add(left, -right);
}

Vec
operator+(const Vec& left, const Vec& right) {
	return add(left, right);
}

Vec
operator-(const Vec& left, const Vec& right) {
	return add(left, -right);
}
