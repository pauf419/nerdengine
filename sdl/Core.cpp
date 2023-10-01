#include "Core.h"
#include "Windows.h"

vector<int> Core::interpolate(
    double i0,
    double d0,
    double i1,
    double d1) {
    std::vector<int> vls;
    if (i0 == i1) {
        vls.push_back(d0);
        return vls;
    }
    double a = static_cast<double>((d1 - d0) / (i1 - i0));
    double d = d0;
    for (int i = i0; i < i1; i++) {
        vls.push_back(d);
        d = d + a;
    }
    return vls;
}

void Core::render_segment(CARTPoint p0, CARTPoint p1, SDL_Surface* surf, Uint32 c) {
    if (abs(p1.x - p0.x) > abs(p1.y - p0.y)) {
        if (p0.x > p1.x) {
            swap(p1.x, p0.x);
            swap(p1.y, p0.y);
        }
        std::vector<int> ys = interpolate(p0.x, p0.y, p1.x, p1.y);
        for (int x = p0.x; x < p1.x; x++) {
            unsigned int* row = (unsigned int*)((char*)surf->pixels + surf->pitch * ys[x - p0.x]);
            row[x] = c;
        }
    }

    else {
        if (p0.y > p1.y) {
            swap(p1.x, p0.x);
            swap(p1.y, p0.y);
        }
        std::vector<int> xs = interpolate(p0.y, p0.x, p1.y, p1.x);
        for (int y = p0.y; y < p1.y; y++) {
            unsigned int* row = (unsigned int*)((char*)surf->pixels + surf->pitch * y);
            row[xs[y - p0.y]] = c;
        }
    }
}

CARTPoint Core::project_vertex2CART(Vertex* v) {
    CARTPoint cp;
    cp.x = v->x;
    cp.y = v->y;
    return cp;
}

CARTPoint Core::project_vertex2centric_coosys(Vertex* v, canvas* c, int project_factor) {
    CARTPoint p;
    if (v->x < 0) p.x = (c->w / 2) - abs(v->x * project_factor);
    else p.x = (c->w / 2) + (v->x * project_factor);
    if (v->y < 0) p.y = (c->h / 2) + abs(v->y * project_factor);
    else p.y = (c->h / 2) - (v->y * project_factor);
    return p;
}

CARTPoint Core::project_CARTP2centric_coosys(CARTPoint _p, canvas* c, int project_factor) {
    CARTPoint p;
    if (_p.x < 0) p.x = ((c->w / 2) - abs(_p.x * project_factor));
    else p.x = (c->w / 2) + (_p.x * project_factor);
    if (_p.y < 0) p.y = (c->h / 2) + abs(_p.y * project_factor);
    else p.y = (c->h / 2) - (_p.y * project_factor);
    return p;
}

void Core::project_CARTP2centric_coosys(CARTPoint* _p, canvas* c, int project_factor) {
    if (_p->x < 0) _p->x = (c->w / 2) - abs(_p->x * project_factor);
    else _p->x = (c->w / 2) + (_p->x * project_factor);
    if (_p->y < 0) _p->y = (c->h / 2) + abs(_p->y * project_factor);
    else _p->y = (c->h / 2) - (_p->y * project_factor);
}

CARTPoint Core::covert_scene_vertex2CARTP(Vertex* v, int bfw) {
    CARTPoint p;
    p.x = v->x * bfw / v->z;
    p.y = v->y * bfw / v->z;
    return p;
}

void Core::render_polygon(Poly& poly, SDL_Surface* surf, int project_factor, int bfw, canvas* c) {
    CARTPoint p1, p2, p3;
    if(project_factor != NULL) {
        CARTPoint p1c = Core::covert_scene_vertex2CARTP(poly.va, bfw);
        p1 = Core::project_CARTP2centric_coosys(p1c, c, project_factor);
        CARTPoint p2c = Core::covert_scene_vertex2CARTP(poly.vb, bfw);
        p2 = Core::project_CARTP2centric_coosys(p2c, c, project_factor);
        CARTPoint p3c = Core::covert_scene_vertex2CARTP(poly.vc, bfw);
        p3= Core::project_CARTP2centric_coosys(p3c, c, project_factor);
    }
    else {
        p1 = Core::project_vertex2CART(poly.va);
        p2 = Core::project_vertex2CART(poly.vb);
        p3 = Core::project_vertex2CART(poly.vc);
    }

    Core::render_segment(p1, p2, surf, 0xff000000);
    Core::render_segment(p2, p3, surf, 0x00ff0000);
    Core::render_segment(p1, p3, surf, 0x00EEff00);
}