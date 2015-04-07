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
	uint   depth;
	bool   shadows;
	bool   reflections;
	bool   refractions;
	bool   stochasticDiffuse;
	bool   superSample;
	
	std::vector<Object*> objects;
	std::vector<Light*>  lights;
	
	Scene(Screen& screen, Cam& camera, std::vector<Object*>& objects, std::vector<Light*>& lights,
		  uint depth,
		  bool shadows, bool reflections, bool refractions,
		  bool stochasticDiffuse, bool superSample);
	~Scene();

	void render();

	Color
	raycast(const Ray& ray, const Object* ignore, uint depth) const;

	std::pair<const Object*, double>
	raycollide(const Ray& ray, const Object*) const;
};
