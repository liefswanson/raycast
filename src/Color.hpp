#pragma once

class Color {
public:
	double r;
	double g;
	double b;
	double special;

	Color(double r, double g, double b, double special = 0);
	~Color();


	friend Color scale(const Color& left, double scalar);
	friend Color operator*(const Color& left, double scalar);
	friend Color operator*(double scalar, const Color& left);

	friend Color add(const Color& left, const Color& right);
	friend Color sub(const Color& left, const Color& right);

	friend Color operator+(const Color& left, const Color& right);
	friend Color operator-(const Color& left, const Color& right);
};
