#ifndef __VERTEX__
#define __VERTEX__

#include "Vector.h"

class Vertex {
public:
	double x;
	double y;
	double z;

	Vertex() : x(0.0), y(0.0), z(0.0) {}
	Vertex(double x, double y, double z);
	void fold_vector(Vector* v);
	void fold_vector(Vector v);
};

#endif