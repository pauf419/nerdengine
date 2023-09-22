#ifndef __VISUALIZER__
#define __VISUALIZER__

#include "Scene.h"
#include "Core.h"
#include <functional>


class Visualizer
{
public: 
	Scene * scene = NULL;
	SDL_Window* w;
	SDL_Surface* scr;
	SDL_Surface* pxs;
	function<void()> cb = NULL;
	
	Visualizer();
	void setup_scene(Scene* scene);

	void update(function<void()> cb);
	void initialize(canvas * c, int project_factor, int bfw);
};

#endif

