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
	std::vector<Color> pixels;
	uint32_t height;
	uint32_t width;
	double   aspectRatio;
	double   pxScale;
	Vec      center;

	Screen(uint32_t height, uint32_t width, double pxScale);
	Screen();
	~Screen();

	const Color& at(uint32_t x, uint32_t y) const;
	Color& at(uint32_t x, uint32_t y);

	void normalize();
};
