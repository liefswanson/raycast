#pragma once

#include <limits>
#include "Vec.hpp"
#include "Color.hpp"

namespace World {
	const extern Vec x;
	const extern Vec y;
	const extern Vec z;
	const extern Vec origin;
}

namespace Palette {
	const extern Color mattBlack;
	const extern Color mattWhite;
	
	const extern Color limeGreen;
	const extern Color maroon;
}

namespace aliases {
	const extern double inf; 
}

namespace math {
	extern double quadratic(double a, double b, double c);
}
