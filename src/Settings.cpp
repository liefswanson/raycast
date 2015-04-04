#include "Settings.hpp"

const uint32_t Settings::dpi           = 72;
const double   Settings::pxScale       = 0.01;
const Vec      Settings::camPos        = Vec(0, 1, -2);
const Vec      Settings::screenCenter  = World::origin;

const Light    Settings::light         = Light(Vec(-7, 10, -10), Palette::mattWhite);
const std::vector<Object> Settings::objects =
{
	// the ground
	Plane(World::y, -1, Palette::maroon)
};
