#ifndef __SCENE__
#define __SCENE__

#include "Structure.h"

class Scene
{	
public:
	int project_factor;

	vector<Structure*> structs;
	void append_structure(Structure* structure);
	Scene(int project_factor);
};

#endif

