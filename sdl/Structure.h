#ifndef __STRUCTURE__ 
#define __STRUCTURE__
#include "Poly.h"
#include <iostream>
#include <vector>
using namespace std;
class Structure
{
public: 
	vector<Poly> polychain;
	Structure(vector<Poly> polychain);
};

#endif

