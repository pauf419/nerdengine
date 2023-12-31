#ifndef __STRUCTURE_PATTERN__
#define __STRUCTURE_PATTERN__

#include "Poly.h"
#include "Structure.h"
#include <vector>

using namespace std;

class StructurePattern
{
public: 
	StructurePattern();
	static Structure_data Cube(int posx,
        int posy,
        int posz,
        float h);
	static Structure_data Segment();
};
#endif

