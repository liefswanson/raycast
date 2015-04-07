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
	const extern Color matteBlack;
	const extern Color matteWhite;
	const extern Color mattePurple;

	const extern Color black;
	const extern Color white;
	
	const extern Color limeGreen;
	const extern Color muddyRed;
	const extern Color crimson;
	const extern Color paleBlue;

	const extern Color lightWhite;
}

namespace aliases {
	const extern double inf; 
}
