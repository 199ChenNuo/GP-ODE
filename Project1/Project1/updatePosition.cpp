#include "updatePosition.h"

using namespace std;

class updatePosition {
	Vector3 getSumF() {
		// call getF_xxx to get all force
		return Vector3(0);
	}

	Vector3 getSumA() {
		// calculate a according to force and mass
		double mass = 1;
		return getSumF() / mass;
	}

	void updateStep(Vector3 prevPos, Vector3 prevSpd, double deltaT){
		Vector3 a = getSumA();
		Vector3 spd = prevSpd + a * deltaT;
		Vector3 pos = prevPos + spd * deltaT;
	}
};