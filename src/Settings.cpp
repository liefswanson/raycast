#include "Settings.hpp"

const uint32_t Settings::width          = 512;
const uint32_t Settings::height         = 512;
const uint32_t Settings::dpi            = 72;
const double   Settings::pxScale        = 0.01;
const Vec      Settings::camPos         = Vec(100, 0, 100);
const Vec      Settings::camLookAt      = camPos + Vec(5, 0, 4);

const double   Settings::ambient       = 0.1;
const double   Settings::specularMax   = 50;

const Color    Settings::background     = Palette::mattePurple;

// currently unused
const unsigned    Settings::minimumThreads = 4;
const uint        Settings::defaultDepth   = 0;
const std::string Settings::defaultPath    = "out/output.bmp";

