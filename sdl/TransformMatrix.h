#ifndef __TRANSFORM_MATRIX__ 
#define __TRANSFORM_MATRIX__

#include "Vertex.h"

struct TMConfig {
	float rad;
	Vertex ini;
	Vertex* dv;
	Vertex loc;
	Vertex max;
	Vertex min;
};

class TransformMatrix
{
public: 
	static void rotatey(TMConfig c);
	static void rotatex(TMConfig c);
	static void rotatez(TMConfig c);
	static void translate(TMConfig c);
};

#endif

