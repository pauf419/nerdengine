#ifndef __POLY__
#define __POLY__

#include "Vertex.h"

class Poly {
public:
	Vertex *va;
	Vertex *vb;
	Vertex *vc;

	Poly(Vertex *v1, Vertex *v2, Vertex *v3);
};

#endif