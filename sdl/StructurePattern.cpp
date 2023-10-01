#include "StructurePattern.h"
StructurePattern::StructurePattern() {

}

Structure_data StructurePattern::Segment() {
    Vertex* a1 = new Vertex(-5, 5, 2);
    Vertex* a = new Vertex(-5, -5, 2);
    Vertex* d = new Vertex(5, -5, 2);
    Vertex* d1 = new Vertex(5, 5, 2);

    vector<Vertex*> vertexchain;
    vertexchain.push_back(a1);
    vertexchain.push_back(a);
    vertexchain.push_back(d);
    vertexchain.push_back(d1);

    Poly fb(d, a1, a);

    vector<Poly> polychain;

    polychain.push_back(fb);

    return Structure_data{ polychain, vertexchain };
}

Structure_data StructurePattern::Cube(
    int posx, 
    int posy, 
    int posz, 
    float h) {

    /* 
    x
    |    5___________1
    |  / |          /|
    | 6___________2  |        z
    | |  |        |  |       /
    | |  |        |  |      /
    | |  7________|__3     /
    | | /         | /     /
    | 8___________4      /
    |_______________________________y
    */

    Vertex ce(posx, posy, posz);
    
    Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Vertex* v3 = new Vertex();
    Vertex* v4 = new Vertex();
    Vertex* v5 = new Vertex();
    Vertex* v6 = new Vertex();
    Vertex* v7 = new Vertex();
    Vertex* v8 = new Vertex();

    vector<Vertex> s_vertexchain;

    vector<Vertex*> vertexchain;
    vertexchain.push_back(v1);
    vertexchain.push_back(v2);
    vertexchain.push_back(v3);
    vertexchain.push_back(v4);
    vertexchain.push_back(v5);
    vertexchain.push_back(v6);
    vertexchain.push_back(v7);
    vertexchain.push_back(v8);

    vector<Vector> vectorchain;
    vectorchain.push_back(Vector(ce.x + h/2, ce.y + h/2, ce.z + h/2));
    vectorchain.push_back(Vector(ce.x + h/2, ce.y + h/2, ce.z - h/2));
    vectorchain.push_back(Vector(ce.x + h/2, ce.y - h/2, ce.z + h/2));
    vectorchain.push_back(Vector(ce.x + h/2, ce.y - h/2, ce.z - h/2));
    vectorchain.push_back(Vector(ce.x - h/2, ce.y + h/2, ce.z + h/2));
    vectorchain.push_back(Vector(ce.x - h/2, ce.y + h/2, ce.z - h/2));
    vectorchain.push_back(Vector(ce.x - h/2, ce.y - h/2, ce.z + h/2));
    vectorchain.push_back(Vector(ce.x - h/2, ce.y - h/2, ce.z - h/2));

    for (int i = 0; i < vertexchain.size(); i++) {
        vertexchain[i]->fold_vector(vectorchain[i]);
        s_vertexchain.push_back(*vertexchain[i]);
    }

    Poly fb(v6, v4, v2);
    Poly ft(v6, v8, v4);
    Poly lb(v8, v5, v7);
    Poly lt(v8, v6, v5);

    Poly rb(v3, v2, v4);
    Poly rt(v3, v1, v2);

    Poly zt(v7, v1, v3);
    Poly zb(v7, v5, v1);

    Poly tt(v6, v1, v2);
    Poly tb(v6, v5, v1);

    Poly bb(v8, v3, v4);
    Poly bt(v8, v7, v3);


    vector<Poly> polychain;
    polychain.push_back(fb);
    polychain.push_back(ft);
    polychain.push_back(lb);
    polychain.push_back(lt);
    polychain.push_back(rb);
    polychain.push_back(rt);

    polychain.push_back(zb);
    polychain.push_back(zt);

    polychain.push_back(tb);
    polychain.push_back(tt);

    polychain.push_back(bb);
    polychain.push_back(bt);

    return Structure_data{ polychain, vertexchain, s_vertexchain };
}