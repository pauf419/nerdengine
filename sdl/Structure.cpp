#include "Structure.h"

Structure::Structure(Structure_data data) {
	this->polychain = data.polychain;
	this->vertexchain = data.vertexchain;
}

void Structure::fold_vector(Vector* v) {
	for (int i = 0; i < this->vertexchain.size(); i++) {
		this->vertexchain[i]->fold_vector(v);
	}
}