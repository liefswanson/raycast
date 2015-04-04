#include "Screen.hpp"

Screen::Screen(uint32_t width, uint32_t height, double pxScale,
			   Vec center){
	this->width  = width;
	this->height = height;
	this->center = center;
	
	this->aspectRatio = (double)width / (double)height;

	this->pixels.resize(width*height, Pixel(0.f, 0.f, 0.f));
}

Screen::Screen() : Screen(0, 0, 0, World::origin){}

Pixel&
Screen::at(uint32_t x, uint32_t y) {
	return this->pixels[y*width +x];
}

Screen::~Screen(){}

std::vector<uint8_t> Screen::bgr24() const{
	auto raw = std::vector<uint8_t>();
	raw.reserve(this->width * this->height);

	for(auto &px: pixels){
		raw.push_back(px.b);
		raw.push_back(px.g);
		raw.push_back(px.r);
	}

	return raw;
}
