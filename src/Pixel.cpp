#include "Pixel.hpp"

const double Pixel::toInt = 255;

// Todo might be redundant now
Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b){
	this->r = r;
	this->g = g;
	this->b = b;
}

Pixel::Pixel(Color col){
	this->r = col.r * toInt;
	this->g = col.g * toInt;
	this->b = col.b * toInt;
}

Pixel::~Pixel(){}
