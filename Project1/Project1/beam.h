#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<math.h>

#include "node.h"

class Node;
struct Vector3;

using namespace std;


class Beam {
private:
	pair<Node, Node> nodes;
	pair<Vector3, Vector3> vertices;
	float original_length;

public:

	Beam(pair<Node,Node> nodes) :
		nodes(nodes){
		vertices.first = nodes.first.get_original_position();
		vertices.second = nodes.second.get_original_position();
		original_length = nodes.first.get_original_position().distance(nodes.second.get_original_position());
	}

	bool operator==(Beam beam);
	
	Node getOtherNode(Node node);
	float getLength();
	float getOriginalLength();
	void recalcOriginalLength();
	bool isFixed();
	Vector3 getVector(Node fromNode);
	float getK();
	float getD();
	float getNaturalFrequency();
	float getMinMass();
};



#pragma once
