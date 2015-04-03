#pragma once

#include <cmath>

class Vec{
public:
	double x;
	double y;
	double z;

	Vec(double x, double y, double z);
	Vec(double v);
	Vec();
	~Vec();

	double magnitude() const;

	friend Vec normalize(const Vec& v);

	friend Vec negative (const Vec& v);
	friend Vec operator-(const Vec& v);
	
	friend Vec scale    (const Vec& v, const double& scalar);
	friend Vec operator*(const Vec& v, const double& scalar);
	friend Vec operator*(const double scalar, const Vec& v);

	friend double dot      (const Vec& left, const Vec&right);
	friend double operator*(const Vec& left, const Vec& right);

	friend Vec cross       (const Vec& left, const Vec& right); 
	friend Vec operator^   (const Vec& left, const Vec& right);

	friend Vec add         (const Vec& left, const Vec& right);
	friend Vec sub         (const Vec& left, const Vec& right);
	friend Vec operator+   (const Vec& left, const Vec& right);
	friend Vec operator-   (const Vec& left, const Vec& right);
};
