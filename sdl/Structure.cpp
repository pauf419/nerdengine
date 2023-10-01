#include "Structure.h"
#include <math.h>
#include "TransformMatrix.h"
#include <iostream>
# define M_PI 3.14159265358979323846

Structure::Structure(Structure_data data) {
	this->polychain = data.polychain;
	this->vertexchain = data.vertexchain;
	this->s_vertexchain = data.s_vertexchain;
}

void Structure::fold_vector(Vector* v) {
	for (int i = 0; i < this->vertexchain.size(); i++) {
		this->vertexchain[i]->fold_vector(v);
	}
}

void Structure::prepare_matrix(std::function<void(TMConfig c)> op, int deq) {
    Vertex min;
    min.x = 100;
    min.y = 100;
    min.z = 100;
    Vertex max;
    max.x = -100;
    max.y = -100;
    max.z = -100;

    for (int i = 0; i < this->vertexchain.size(); i++) {
        if (this->s_vertexchain[i].x > max.x) max.x = this->s_vertexchain[i].x;
        if (this->s_vertexchain[i].x < min.x) min.x = this->s_vertexchain[i].x;
        if (this->s_vertexchain[i].y > max.y) max.y = this->s_vertexchain[i].y;
        if (this->s_vertexchain[i].y < min.y) min.y = this->s_vertexchain[i].y;
        if (this->s_vertexchain[i].z > max.z) max.z = this->s_vertexchain[i].z;
        if (this->s_vertexchain[i].z < min.z) min.z = this->s_vertexchain[i].z;
    }

    Vertex loc;
    loc.x = (min.x + max.x) / 2;
    loc.y = (min.y + max.y) / 2;
    loc.z = (min.z + max.z) / 2;

    TMConfig cf = {};

    cf.loc = loc;
    cf.max = max;
    cf.min = min;

    for (int i = 0; i < this->vertexchain.size(); i++) {
        const float rad = deq * (M_PI / 180);
        cf.rad = rad;
        cf.ini = this->s_vertexchain[i];
        cf.dv = this->vertexchain[i];
        op(cf);
    }
}