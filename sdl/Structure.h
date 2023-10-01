#ifndef __STRUCTURE__ 
#define __STRUCTURE__
#include "Poly.h"
#include <iostream>
#include <vector>
#include <functional>
#include "TransformMatrix.h"
using namespace std;

struct Structure_data {
	vector<Poly> polychain;
	vector<Vertex*> vertexchain;
	vector<Vertex> s_vertexchain;
};


class Structure
{
public: 
	vector<Poly> polychain;
	vector<Vertex*> vertexchain;
	vector<Vertex> s_vertexchain;
	Structure(Structure_data data);
	Structure() : polychain(NULL), vertexchain(NULL), s_vertexchain(NULL) {};
	void fold_vector(Vector* vector);
	void prepare_matrix(std::function<void(TMConfig c)> op, int deq);
};

#endif

