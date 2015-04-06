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
	std::vector<Light*>  lights;
	
	Scene(Screen& screen, Cam& camera, std::vector<Object*>& objects, std::vector<Light*>& lights);
	~Scene();

	void render(bool superSample);

	Color raycast(const Ray& ray, const Object*, uint depth) const;
};
