#include "StructurePattern.h"
StructurePattern::StructurePattern() {

}
Structure_data StructurePattern::Cube() {

    Vertex* a1 = new Vertex(-5, 5, 1);
    Vertex* a = new Vertex(-5, -5, 1);
    Vertex* d = new Vertex(5, -5, 1);
    Vertex* d1 = new Vertex(5, 5, 1);
    Vertex* b1 = new Vertex(-5, 5, 2);
    Vertex* b = new Vertex(-5, -5, 2);
    Vertex* c = new Vertex(5, -5, 2);
    Vertex* c1 = new Vertex(5, 5, 2);

    vector<Vertex*> vertexchain;
    vertexchain.push_back(a1);
    vertexchain.push_back(a);
    vertexchain.push_back(d1);
    vertexchain.push_back(d);
    vertexchain.push_back(b1);
    vertexchain.push_back(b);
    vertexchain.push_back(c1);
    vertexchain.push_back(c);

    Poly fb(d, a1, a);
    Poly ft(d, d1, a1);
    Poly rb(b, c1, c);
    Poly rt(b, b1, c1);
    Poly rib(c, d1, d);
    Poly rit(c, c1, d1);
    Poly lb(a, b1, b);
    Poly lt(a, a1, b1);
    Poly tb(b1, d1, c1);
    Poly tt(b1, a1, d1);
    Poly bb(b, d, a);
    Poly bt(b, c, d);

    vector<Poly> polychain;
    polychain.push_back(rb);
    polychain.push_back(rt);
    polychain.push_back(rib);
    polychain.push_back(rit);
    polychain.push_back(lb);
    polychain.push_back(lt);
    polychain.push_back(tb);
    polychain.push_back(tt);
    polychain.push_back(bb);
    polychain.push_back(bt);
    polychain.push_back(fb);
    polychain.push_back(ft);

    return Structure_data{ polychain, vertexchain };
}