#pragma once

#include <stdint.h>

#include "Color.hpp"

class Pixel {
private:
	static const double toInt;

public:
	Pixel(uint8_t r, uint8_t g, uint8_t b);
	Pixel(Color col);
	~Pixel();
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

