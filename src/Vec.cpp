#include "Vec.hpp"

vec::vec(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

vec::vec(double val) : vec(val, val, val){}

vec::vec() : vec(0, 0, 0){}

vec::~vec(){}


double
vec::magnitude() const{
	return sqrt(x*x + y*y + z*z);
}




// friends


vec
normalize(const vec& v){
	double s = 1/v.magnitude();
	return s * v;
}

vec
negative(const vec& v) {
	return vec(-v.x, -v.y, -v.z);
}

vec
operator-(const vec& v){
	return negative(v);
}

vec
scale(const vec& v, const double& scalar) {
	return vec (v.x * scalar,
				v.y * scalar,
				v.z * scalar);
}

vec
operator*(const vec& v, const double& scalar){
	return scale(v, scalar);
}

vec
operator*(const double& scalar, const vec& v){
	return scale(v, scalar);
}

double 
dot(const vec& left, const vec& right){
	return left.x * right.x
		+  left.y * right.y
		+  left.z * right.z;
}

double
operator*(const vec& left, const vec& right){
	return dot(left, right);
}

vec
cross(const vec& left, const vec& right) {
	return vec(left.y*right.z - left.z*right.y,
			   left.x*right.z - left.z*right.x,
			   left.x*right.y - left.y*right.x);
}

vec
operator^(const vec& left, const vec& right){
	return cross(left, right);
}

vec
add (const vec& left, const vec& right) {
	return vec(left.x + right.x,
			   left.y + right.y,
			   left.z + right.z);
}

vec
sub(const vec& left, const vec& right) {
	return add(left, -right);
}

vec
operator+(const vec& left, const vec& right) {
	return add(left, right);
}

vec
operator-(const vec& left, const vec& right) {
	return add(left, -right);
}
