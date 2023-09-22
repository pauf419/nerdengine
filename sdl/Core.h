#ifndef __CORE__ 
#define __CORE__ 

#include <iostream>
#include <vector>
#include <SDL.h>
#include "Poly.h"
#include <cmath>
#include "Core.h"
#include "Common.h"


struct canvas {
    int w;
    int h;
};

using namespace std;

class Core
{
public:
    static vector<int> interpolate(
        double i0,
        double d0,
        double i1,
        double d1);
    static void render_segment(CARTPoint p0, CARTPoint p1, SDL_Surface* surf, Uint32 c);
    static void render_polygon(Poly& poly, SDL_Surface* surf, int project_factor, int bfw, canvas * c);
    static CARTPoint project_vertex2CART(Vertex* v);
    static CARTPoint project_vertex2centric_coosys(Vertex* v, canvas * c, int project_factor);
    static void project_CARTP2centric_coosys(CARTPoint* p, canvas * c, int project_factor);
    static CARTPoint covert_scene_vertex2CARTP(Vertex* v, int bfw);
    static CARTPoint project_CARTP2centric_coosys(CARTPoint p, canvas* c, int project_factor);
};

#endif

