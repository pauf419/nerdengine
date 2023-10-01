#include <SDL.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <vector>
#include "Scene.h"
#include "Visualizer.h"
#include "StructurePattern.h"
#include "Common.h"
#include "TransformMatrix.h"

int main(int argc, char* argv[])
{
    canvas* cv = new canvas;

    cv->w = 600;
    cv->h = 600;

    Structure* struct1 = new Structure(StructurePattern::Cube(100, 0, 8, 10));


    Scene* scene = new Scene(10);
    scene->append_structure(struct1);
    Visualizer visualizer;

    visualizer.setup_scene(scene);


    float rad = 0;
  
    visualizer.update([scene, struct1, &rad]() {
        rad -= 0.05;
        scene->structs[0]->prepare_matrix(TransformMatrix::rotatey,rad);
    }); 

    visualizer.initialize(cv, 10, 3);

    return 0;
}