#ifndef __VERTEX__
#define __VERTEX__

class Vertex {
public:
	double x;
	double y;
	double z;

	Vertex() : x(0.0), y(0.0), z(0.0) {}
	Vertex(double x, double y, double z);
};

#endif