#pragma once

#include <stdint.h>

class FPixel;

class Pixel {
private:
	static const double toDouble;

public:
	Pixel(uint8_t r, uint8_t g, uint8_t b);
	~Pixel();
	uint8_t r;
	uint8_t g;
	uint8_t b;

	FPixel conv() const;
};

class FPixel {
private:
	static const double toInt;

public:
	FPixel(double r, double g, double b);
	~FPixel();
	double r;
	double g;
	double b;

	Pixel conv() const;
};
