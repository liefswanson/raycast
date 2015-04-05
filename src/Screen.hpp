#pragma once

#include <vector>
#include <algorithm>
#include <stdint.h>

#include "Pixel.hpp"
#include "Vec.hpp"
#include "Ray.hpp"
#include "Cam.hpp"

class Screen {
public:
	std::vector<Pixel> pixels;
	uint32_t height;
	uint32_t width;
	double   aspectRatio;
	double   pxScale;
	Vec      center;

	Screen(uint32_t height, uint32_t width, double pxScale,
		   Vec center);
	Screen();
	~Screen();

	const Pixel& at(uint32_t x, uint32_t y) const;
	Pixel& at(uint32_t x, uint32_t y);

};
