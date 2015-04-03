#include "Screen.hpp"

Screen::Screen(uint32_t width, uint32_t height, uint32_t dpi){
	this->width  = width;
	this->height = height;
	this->dpi    = dpi;
	this->pixels.resize(width*height, FPixel(0.f, 0.f, 0.f));
}

FPixel&
Screen::at(uint32_t x, uint32_t y) {
	return this->pixels[y*width +x];
}

Screen::~Screen(){}

void
Screen::normalize(){
	auto factor = 1.0/normalFactor(); 
	
	for (auto &i : pixels) {
		i.r *= factor;
		i.g *= factor;
		i.b *= factor;
	}
}

double
Screen::normalFactor() {
	auto i = pixels.begin();
	double factor = 0;

	while (i != pixels.end()) {
		double temp = std::max(i->r, i->g);
		temp = std::max(i->b, temp); 

		factor = std::max(factor, temp);
		i++;
	}
	return factor;
}


std::vector<uint8_t> Screen::bgr24() const{
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
