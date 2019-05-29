#pragma once
#include "calForce.h"

using namespace std;

class updatePosition {
	Vector3 getSumF();

	Vector3 getSumA();

	void updateStep(Vector3 prevPos, Vector3 prevSpd, double deltaT);
};
