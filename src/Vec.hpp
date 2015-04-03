#pragma once

#include <cmath>

class vec{
public:
	double x;
	double y;
	double z;

	vec(double x, double y, double z);
	vec(double v);
	vec();
	~vec();

	double magnitude() const;

	friend vec normalize(const vec& v);

	friend vec negative (const vec& v);
	friend vec operator-(const vec& v);
	
	friend vec scale    (const vec& v, const double& scalar);
	friend vec operator*(const vec& v, const double& scalar);
	friend vec operator*(const double scalar, const vec& v);

	friend double dot      (const vec& left, const vec&right);
	friend double operator*(const vec& left, const vec& right);

	friend vec cross       (const vec& left, const vec& right); 
	friend vec operator^   (const vec& left, const vec& right);

	friend vec add         (const vec& left, const vec& right);
	friend vec sub         (const vec& left, const vec& right);
	friend vec operator+   (const vec& left, const vec& right);
	friend vec operator-   (const vec& left, const vec& right);
};
