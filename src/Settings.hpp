#pragma once

#include <stdint.h>
#include <vector>

#include "Light.hpp"

#include "Object.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Ray.hpp"

#include "Vec.hpp"

namespace Settings {
	// used to determine the size of the screen in the world
	// smaller px size means the rays are grouped closer together
	const extern double pxScale;

	const extern Vec camPos;
	const extern Vec camLookAt;

	const extern double ambient;
	const extern double specularMax;

	// just for saving the image
	const extern uint32_t dpi;

	const extern Color background;

	const extern unsigned    minimumThreads;
	const extern uint        defaultDepth;
	const extern std::string defaultPath;
}
