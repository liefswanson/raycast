#pragma once

#include <algorithm>

class Color {
public:
	double r;
	double g;
	double b;
	double reflectivity;

	Color(double r, double g, double b, double reflectivity = 0);
	Color(double bw, double reflectivity = 0);
	Color();
	~Color();

	friend Color scale    (const Color& left, double scalar);
	friend Color operator*(const Color& left, double scalar);
	friend Color operator*(double scalar, const Color& left);

	friend Color add      (const Color& left, const Color& right);
	friend Color operator+(const Color& left, const Color& right);

	friend Color normalize(const Color& col);
};
