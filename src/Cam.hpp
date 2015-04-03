#include "Vec.hpp"


class Cam {
public:
	Vec position;
	Vec direction;
	Vec up;
	const static Vec worldUp;

	Cam(Vec position, Vec direction, Vec up = Cam::worldUp);
	Cam(Vec direction = Vec(0, 0, 1));
	~Cam();
};
