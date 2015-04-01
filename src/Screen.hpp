#pragma once

#include <vector>

#include <stdint.h>

#include "Pixel.hpp"

class screen {
public:

	screen(uint32_t height, uint32_t width, uint32_t dpi);
	~screen();
	
	std::vector<glpixel> pixels;
	uint32_t height;
	uint32_t width;
	uint32_t dpi;
	
	void normalize();
	
	std::vector<uint8_t> bgr24() const;
};
