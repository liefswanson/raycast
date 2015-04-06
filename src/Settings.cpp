#include "Settings.hpp"

const uint32_t Settings::dpi            = 72;
const double   Settings::pxScale        = 0.01;
const Vec      Settings::camPos         = Vec(3, 1.5, -4);
const Vec      Settings::camLookAt      = World::origin;

const double   Settings::ambient       = 0.2;

const Color    Settings::background     = Palette::mattBlack;

const unsigned Settings::minimumThreads = 4;
const uint     Settings::recursionDepth = 2;
