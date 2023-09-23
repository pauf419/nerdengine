#ifndef __STRUCTURE__ 
#define __STRUCTURE__
#include "Poly.h"
#include <iostream>
#include <vector>

using namespace std;

struct Structure_data {
	vector<Poly> polychain;
	vector<Vertex*> vertexchain; 
};

using namespace std;


class Structure
{
public: 
	vector<Poly> polychain;
	vector<Vertex*> vertexchain;
	Structure(Structure_data data);
	Structure() : polychain(NULL), vertexchain(NULL) {};
	void load_from_pattern();
	void fold_vector(Vector* vector);
};

#endif

