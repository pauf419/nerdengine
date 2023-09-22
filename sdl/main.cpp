#include <SDL.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <vector>
#include "Scene.h"
#include "Visualizer.h"

int main(int argc, char* argv[])
{
    canvas* cv = new canvas;

    cv->w = 600;
    cv->h = 600;
    
    Vertex* a1 = new Vertex(-5, 5, 1);
    Vertex* a = new Vertex(-5, -5, 1);
    Vertex* d = new Vertex(5, -5, 1);
    Vertex* d1 = new Vertex(5, 5, 1);
    Vertex* b1 = new Vertex(-5, 5, 2);
    Vertex* b = new Vertex(-5, -5, 2);
    Vertex* c = new Vertex(5, -5, 2);
    Vertex* c1 = new Vertex(5, 5, 2);

    Poly fb(d, a1, a);
    Poly ft(d, d1, a1);
    Poly rb(b, c1, c);
    Poly rt(b, b1, c1);
    Poly rib(c, d1, d);
    Poly rit(c, c1, d1);
    Poly lb(a, b1,b);
    Poly lt(a, a1, b1);
    Poly tb(b1, d1, c1);
    Poly tt(b1, a1, d1);
    Poly bb(b, d, a);
    Poly bt(b, c, d);

    vector<Poly> polychain;
    polychain.push_back(rb);
    polychain.push_back(rt);
    polychain.push_back(rib);
    polychain.push_back(rit);
    polychain.push_back(lb);
    polychain.push_back(lt);
    polychain.push_back(tb);
    polychain.push_back(tt);
    polychain.push_back(bb);
    polychain.push_back(bt);
    polychain.push_back(fb);
    polychain.push_back(ft);

    Structure struct1(polychain);

    Scene scene(10);
    scene.append_structure(struct1);

    Visualizer visualizer;

    visualizer.setup_scene(&scene);
  
    visualizer.update([]() {
    }); 

    visualizer.initialize(cv, 10, 2);

    return 0;
}