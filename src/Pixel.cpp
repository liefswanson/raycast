#include "Pixel.hpp"

const double Pixel::toDouble = 1.0/255.0;
const double FPixel::toInt = 255.0;

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b){
	this->r = r;
	this->g = g;
	this->b = b;
}

Pixel::~Pixel(){}

Pixel
FPixel::conv() const{
	auto _r = (uint8_t) (r*toInt);
	auto _g = (uint8_t) (g*toInt);
	auto _b = (uint8_t) (b*toInt);
	return Pixel(_r, _g, _b);
}

FPixel::FPixel(double r, double g, double b){
	this->r = r;
	this->g = g;
	this->b = b;
}

FPixel::~FPixel(){}

FPixel
Pixel::conv() const{
	auto _r = (double) (r*toDouble);
	auto _g = (double) (g*toDouble);
	auto _b = (double) (b*toDouble);
	return FPixel(_r, _g, _b);
}
