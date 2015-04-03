#pragma once

#include <vector>
#include <algorithm>
#include <stdint.h>

#include "Pixel.hpp"

class Screen {
private:
	double normalFactor();
	
public:

	Screen(uint32_t height, uint32_t width, uint32_t dpi);
	~Screen();
	
	std::vector<FPixel> pixels;
	uint32_t height;
	uint32_t width;
	uint32_t dpi;

	FPixel& at(uint32_t x, uint32_t y);
	void normalize();
	
	std::vector<uint8_t> bgr24() const;
};
