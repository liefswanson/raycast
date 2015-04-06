#pragma once
#include "Vec.hpp"
#include "Constants.hpp"

class Cam {
public:
	Vec position;
	Vec lookAt;
	Vec direction;
	Vec right;
	Vec left;
	Vec up;
	Vec down;

	Cam(Vec position, Vec LookAt);
	Cam();
	~Cam();
};
