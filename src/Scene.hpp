#pragma once

#include <vector>
#include <iostream>

#include "Screen.hpp"
#include "Cam.hpp"
#include "Light.hpp"

#include "Object.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Ray.hpp"
#include "Settings.hpp"

class Scene {
public:
	Cam    camera;
	Screen screen;
	
	std::vector<Plane> objects;
	Light light;
	
	Scene(uint32_t height, uint32_t width);
	~Scene();

	void render();
	Color raycast(const Vec& scene) const;
};
