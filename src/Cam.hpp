#pragma once
#include "Vec.hpp"
#include "Constants.hpp"

class Cam {
public:
	Vec position;
	Vec lookAt;
	Vec direction;
	Vec right;
	Vec up;

	Cam(Vec position, Vec LookAt);
	Cam();
	~Cam();
};
