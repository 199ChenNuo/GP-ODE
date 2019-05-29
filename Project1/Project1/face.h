#pragma once

#include "beam.h"

class Face{
private:
    vector<Node> nodes;
    vector<Crease> creases;
    Vector3 normal;

public:
    vector<Node>getNodes();
    void setNode(vector<Node> _nodes);

    vector<Crease>getCreases();
    void setCreases();
    void setCreases(vector<Crease> _creases);

    Vector3 getNormal();
    void setNormal();
    bool setNormal(Vector3 _normal);

    Face(Node n1, Node n2, Node n3);
};