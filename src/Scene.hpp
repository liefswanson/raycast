#pragma once

#include <thread>
#include <utility>
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
private:

public:
	Cam    camera;
	Screen screen;
	
	std::vector<Object*> objects;
	Light light;
	
	Scene(uint32_t height, uint32_t width, std::vector<Object*> objects);
	~Scene();

	void render();

	Color raycast(const Ray& ray) const;
};
