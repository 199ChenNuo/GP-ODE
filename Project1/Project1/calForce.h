#pragma once
#include <iostream>
#include <string>
#include <math.h>

#include "beam.h"

using namespace std;


class CalForce {
private:
public:
	double F_axial;
	double F_crease;
	double F_face;

	Vector3 getF_axial(double l, double l0, Node n1, Node n2, Node_type node_type);

	double getF_crease_k(Crease crease, double l0, double theta, double target_theta);

	Vector3 getF_crease(Crease crease, double l0, double theta, double target_theta, 
		Theta_type theta_type, Vector3 n1, Vector3 n2, double h1, double h2, 
		double alpha4_31, double alpha4_23, double alpha3_14, double alpha3_42);

	Vector3 getF_face(double alpha, double alpha0, Alpha_type p, Vector3 n,
		Vector3 p1, Vector3 p2, Vector3 p3);

};
