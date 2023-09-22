#include "Visualizer.h"

Visualizer::Visualizer() {
	
}

void Visualizer::setup_scene(Scene* scene) {
	this->scene = scene;
}

void Visualizer::update(function<void()> cb) {
	if (this->cb != NULL) throw invalid_argument("Cb already setted up.");
	this->cb = cb;
}

void Visualizer::initialize(canvas * c, int project_factor, int bfw) {
	SDL_Init(SDL_INIT_VIDEO);
	this->w = SDL_CreateWindow("NE 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, c->w, c->h, SDL_WINDOW_SHOWN);
	this->scr = SDL_GetWindowSurface(this->w);
	this->pxs = SDL_CreateRGBSurfaceWithFormat(0, c->w, c->h, 32, SDL_PIXELFORMAT_RGBX8888);

	bool run = 1;

	while (run) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) if (ev.type == SDL_QUIT) run = 0;

		SDL_FillRect(pxs, NULL, 0x00000000);

		for (int i = 0; i < this->scene->structs.size(); i++) {
			for (int a = 0; a < this->scene->structs[i].polychain.size(); a++) {
				Core::render_polygon(this->scene->structs[0].polychain[a], pxs, project_factor, bfw, c);
			}
		}

		this->cb();
		
		SDL_BlitSurface(pxs, NULL, scr, NULL);
		SDL_UpdateWindowSurface(w);
	}
}