#include "face.h"

using namespace std;

class Face{
private:
    vector<Node> nodes;
    vector<Crease> creases;
    Vector3 normal;

public:
    Face(Node n1, Node n2, Node n3){
        vector<Node> _nodes;
        _nodes.push_back(n1);
        _nodes.push_back(n2);
        _nodes.push_back(n3);
        this->nodes = _nodes;
        setNormal();
        setCreases();
    }

    vector<Node>getNodes(){
        return this->nodes;
    }
	void setNode(vector<Node> _nodes){
        this->nodes = _nodes;
    }

    vector<Crease> getCreases(){
        return creases;
    }
    void setCreases(){
        // set Creases according to nodes
    }
    void setCreases(vector<Crease> _creases){
        this->creases = _creases;
    }

    Vector3 getNormal(){
        return normal;
    }
    void setNormal(){
        // calculate normal according to nodes
    }
    bool setNormal(Vector3 _normal){
        if(!_normal.parallel(this->normal)){
            cout << "Fail to set normal, conflict with nodes." << endl
                 << "Try to set nodes first." << endl;
            return false;
        }
        this->normal = _normal;
        return true;
    }
};