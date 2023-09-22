#include "Scene.h"

Scene::Scene(int project_factor) {
	this->project_factor = project_factor;
}

void Scene::append_structure(Structure structure) {
	this->structs.push_back(structure);
}