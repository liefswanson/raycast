#include "Pixel.hpp"

const GLfloat pixel::toFloat = 1.f/255.f;
const GLfloat glpixel::toInt = 255.f;

pixel::pixel(uint8_t r, uint8_t g, uint8_t b){
	this->r = r;
	this->g = g;
	this->b = b;
}

pixel::~pixel(){}

pixel
glpixel::conv() const{
	auto _r = (uint8_t) (r*toInt);
	auto _g = (uint8_t) (g*toInt);
	auto _b = (uint8_t) (b*toInt);
	return pixel(_r, _g, _b);
}

glpixel::glpixel(GLfloat r, GLfloat g, GLfloat b){
	this->r = r;
	this->g = g;
	this->b = b;
}

glpixel::~glpixel(){}

glpixel
pixel::conv() const{
	auto _r = (GLfloat) (r*toFloat);
	auto _g = (GLfloat) (g*toFloat);
	auto _b = (GLfloat) (b*toFloat);
	return glpixel(_r, _g, _b);
}
