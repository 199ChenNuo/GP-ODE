#pragma once

#ifndef  NODE_H

#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<math.h>

#include "macro.h"
#include "crease.h"
#include "Vector3.h"

using namespace std;


class Node {
private:
	Node_type type;
	int id;
	Vector3 originPosition;
	bool fixed;
	Vector3 externalForce;

public:
	Vector3 position;
	bool operator == (const Node& other);
	void setFixed(bool _fixed);
	bool isFixed();

	void addExternalForce(Vector3 force);
	Vector3 getExternalForce();

	Vector3 get_original_position();

	double getSimMass();

};

#endif // ! NODE_H


