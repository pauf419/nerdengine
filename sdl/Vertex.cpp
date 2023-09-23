#include "Vertex.h"
#include "Common.h"

Vertex::Vertex(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vertex::fold_vector(Vector* v) {
	this->x = this->x + v->x;
	this->y = this->y + v->y;
	this->z = this->z + v->z;
}