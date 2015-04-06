#include "Screen.hpp"

Screen::Screen(uint32_t width, uint32_t height, double pxScale){
	this->width   = width;
	this->height  = height;
	this->pxScale = pxScale;

	this->aspectRatio = (double)width / (double)height;

	this->pixels.resize(width*height, Color(0, 0, 0));
}

Screen::Screen() : Screen(0, 0, 0){}

const Color&
Screen::at(uint32_t x, uint32_t y) const {
	return this->pixels[y*width +x];
}

Color&
Screen::at(uint32_t x, uint32_t y) {
	return this->pixels[y*width +x];
}

Screen::~Screen(){}

void
Screen::normalize(){
	double factor = 0; 
	for(auto& px : pixels) {
		factor = std::max(factor, px.r);
		factor = std::max(factor, px.g);
		factor = std::max(factor, px.b);
	}

	for(auto&px : pixels) {
		px = px/factor;
	}
}
