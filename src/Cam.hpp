#include "Vec.hpp"


class cam {
public:
	vec position;
	vec direction;
	vec up;
	const static vec worldUp;

	cam(vec position, vec direction, vec up = cam::worldUp);
	cam(vec direction = vec(0, 0, 1));
	~cam();
};
