#include "TransformMatrix.h"
#include <cmath>

void TransformMatrix::rotatey(TMConfig c) {
    c.dv->x = (cos(c.rad) * (c.ini.x - c.loc.x)) + (sin(c.rad) * (c.ini.z - c.loc.z));
    c.dv->z = (-(sin(c.rad)) * (c.ini.x - c.loc.x)) + (cos(c.rad) * (c.ini.z - c.loc.z)) + c.max.z;
}

void TransformMatrix::rotatex(TMConfig c) {
    c.dv->y = (cos(c.rad) * (c.ini.y - c.loc.y)) - (sin(c.rad) * (c.ini.z - c.loc.z));
    c.dv->z = (sin(c.rad) * (c.ini.y - c.loc.y)) + (cos(c.rad) * (c.ini.z - c.loc.z)) + c.max.z;
}

void TransformMatrix::rotatez(TMConfig c) {
    c.dv->x = (cos(c.rad) * (c.ini.x - c.loc.x)) - (sin(c.rad) * (c.ini.y - c.loc.y));
    c.dv->y = (sin(c.rad) * (c.ini.x - c.loc.x)) + (cos(c.rad) * (c.ini.y - c.loc.y));
}