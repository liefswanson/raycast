#include "Screen.hpp"

screen::screen(uint32_t width, uint32_t height, uint32_t dpi){
	this->width  = width;
	this->height = height;
	this->dpi    = dpi;
	this->pixels.resize(width*height, glpixel(0.f,0.f,0.f));
}

glpixel&
screen::at(uint32_t x, uint32_t y) {
	return this->pixels[y*width +x];
}

screen::~screen(){}

std::vector<uint8_t> screen::bgr24() const{
	auto raw = std::vector<uint8_t>();
	raw.reserve(this->width*this->height);

	for(auto &px: pixels){
		auto temp = px.conv();

		raw.push_back(temp.b);
		raw.push_back(temp.g);
		raw.push_back(temp.r);
	}
	return raw;
}
