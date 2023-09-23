#ifndef __POLY__
#define __POLY__

#include "Vertex.h"
#include <iostream>

class Poly {
public:
	Vertex *va;
	Vertex *vb;
	Vertex *vc;

	Poly() : va(NULL), vb(NULL), vc(NULL) {}

	Poly(Vertex *v1, Vertex *v2, Vertex *v3);
};

#endif