#include "Settings.hpp"

const uint32_t Settings::dpi          = 72;
const double   Settings::pxScale      = 0.01;
const Vec      Settings::camPos       = Vec(3, 1.5, -4);
const Vec      Settings::screenCenter = World::origin;

const Light    Settings::light        = Light(Vec(-7, 10, -10), Palette::mattWhite);

const Color    Settings::background   = Palette::mattWhite;
