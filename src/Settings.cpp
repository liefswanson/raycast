#include "Settings.hpp"

const uint32_t Settings::dpi            = 72;
const double   Settings::pxScale        = 0.01;
const Vec      Settings::camPos         = Vec(5, 1.5, 0);
const Vec      Settings::camLookAt      = Vec(10, 0, 4);

const double   Settings::ambient       = 0.05;

const Color    Settings::background     = Palette::mattBlack;

const unsigned Settings::minimumThreads = 4;
const uint     Settings::recursionDepth = 2;
