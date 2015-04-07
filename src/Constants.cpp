#include "Constants.hpp"

const Vec World::x = Vec(1, 0, 0);
const Vec World::y = Vec(0, 1, 0);
const Vec World::z = Vec(0, 0, 1);

const Vec World::origin = Vec(0, 0, 0);

const Color Palette::matteBlack  = Color(0, 0, 0, 0, 0);
const Color Palette::matteWhite  = Color(1, 1, 1, 0, 0);
const Color Palette::muddyRed    = Color(0.4, 0.1, 0.1, 0, 0);
const Color Palette::mattePurple = Color(0.15, 0.0625, 0.15, 0, 0);

const Color Palette::black = Color(0, 0, 0, 0.45, 0);
const Color Palette::white = Color(1, 1, 1, 0.45, 0);

const Color Palette::limeGreen = Color(0.5, 1, 0.5, 0.4, 0);
const Color Palette::crimson   = Color(0.9, 0.1, 0.3, 0.6, 0);
const Color Palette::paleBlue  = Color(0.25, 0.3, 0.9, 0.6, 0);

const double aliases::inf      =  std::numeric_limits<double>::infinity();

