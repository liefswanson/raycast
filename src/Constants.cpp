#include "Constants.hpp"

const Vec World::x = Vec(1, 0, 0);
const Vec World::y = Vec(0, 1, 0);
const Vec World::z = Vec(0, 0, 1);

const Vec World::origin = Vec(0, 0, 0);

const Color Palette::mattBlack = Color(0, 0, 0, 0, 0);
const Color Palette::mattWhite = Color(1, 1, 1, 0, 0);
const Color Palette::limeGreen = Color(0.5, 1, 0.5, 0.3, 0);
const Color Palette::maroon    = Color(0.5, 0.125, 0.125, 0.3, 0);

const double aliases::inf      =  std::numeric_limits<double>::infinity();
