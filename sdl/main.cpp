#include <SDL.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <vector>
#include "Scene.h"
#include "Visualizer.h"
#include "StructurePattern.h"
#include "Common.h"

int main(int argc, char* argv[])
{
    canvas* cv = new canvas;

    cv->w = 600;
    cv->h = 600;


    Structure* struct1 = new Structure(StructurePattern::Cube());

    Scene* scene = new Scene(10);
    scene->append_structure(struct1);

    Visualizer visualizer;

    visualizer.setup_scene(scene);
  
    visualizer.update([scene]() {

        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
            Vector* v = new Vector(0, 0.1, 0);
            scene->structs[0]->fold_vector(v);
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
            Vector* v = new Vector(0, -0.1, 0);
            scene->structs[0]->fold_vector(v);
        }
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
            Vector* v = new Vector(-0.1, 0, 0);
            scene->structs[0]->fold_vector(v);
        }
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
            Vector* v = new Vector(0.1, 0, 0);
            scene->structs[0]->fold_vector(v);
        }
    }); 

    visualizer.initialize(cv, 5, 1);

    return 0;
}