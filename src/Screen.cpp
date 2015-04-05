#include "Screen.hpp"

Screen::Screen(uint32_t width, uint32_t height, double pxScale,
			   Vec center){
	this->width  = width;
	this->height = height;
	this->center = center;
	
	this->aspectRatio = (double)width / (double)height;

	this->pixels.resize(width*height, Pixel(0, 0, 0));
}

Screen::Screen() : Screen(0, 0, 0, World::origin){}

Pixel&
Screen::at(uint32_t x, uint32_t y) {
	return this->pixels[y*width +x];
}

Screen::~Screen(){}
