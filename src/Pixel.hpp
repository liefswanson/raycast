#pragma once

#include <stdint.h>
#include <GL/glew.h>

class glpixel;

class pixel {
private:
	static const GLfloat toFloat;
	
public:
	pixel(uint8_t r, uint8_t g, uint8_t b);
	~pixel();
	uint8_t r;
	uint8_t g;
	uint8_t b;

	glpixel conv() const;
};

class glpixel {
private:
	static const GLfloat toInt;

public:
	glpixel(GLfloat r, GLfloat g, GLfloat b);
	~glpixel();
	GLfloat r;
	GLfloat g;
	GLfloat b;

	pixel conv() const;
};
