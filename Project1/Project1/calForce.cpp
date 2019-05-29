#include "calForce.h"

class CalForce{
public:
	Vector3 getF_axial(double l, double l0, Node n1, Node n2, Node_type node_type) {
		double K_axial = EA / l0;
		double k = K_axial * (l0 - l);
		Vector3 I12 = normalize(n1.position, n2.position);
		if(node_type == Node_type::node1)
			return I12 * k;
		return I12 * (-k);
	}

	double getF_crease_k(Crease crease, double l0, double theta, double target_theta) {
		// k_{crease} =
		//	 	moutain or velly:		l_0 * k_{flod}
		//		facet:					l_0 * k_{facet}
		//		boundary or undriven:	0
		double K_crease = crease.getK_crease(l0);
		double theta_val = theta - target_theta;
		return theta_val * K_crease;
	}

	Vector3 getF_crease(Crease crease, double l0, double theta, double target_theta, 
		Theta_type theta_type, Vector3 n1, Vector3 n2, double h1, double h2, 
		double alpha4_31, double alpha4_23, double alpha3_14, double alpha3_42) {

		double k = getF_crease_k(crease, l0, theta, target_theta);

		if (theta_type == Theta_type::theta1) {
			return n1 * (k / h1);
		}
		else if (theta_type == Theta_type::theta2) {
			return n2 * (k / h2);
		}
		else if (theta_type == Theta_type::theta3) {
			double k1 = -( cos(alpha4_31) / sin(alpha4_31) ) / ( cos(alpha3_14) / sin(alpha3_14) + cos(alpha4_31) / sin(alpha4_31) );
			double k2 = -( cos(alpha4_23) / sin(alpha4_23) ) / ( cos(alpha3_42) / sin(alpha3_42) + cos(alpha4_23) / sin(alpha4_23) );
			return (n1 * (k1 / h1) + n2 * (k2 / h2)) * k;
		}
		else {
			double k1 = -( cos(alpha3_14) / sin(alpha3_14) ) / ( cos(alpha3_14) / sin(alpha3_14) + cos(alpha4_31) / sin(alpha4_31) );
			double k2 = -( cos(alpha3_42) / sin(alpha3_42) ) / ( cos(alpha3_42) / sin(alpha3_42) + cos(alpha4_23) / sin(alpha4_23) );
			return (n1 * (k1 / h1) + n2 * (k2 / h2)) * k;
		}
	}

	Vector3 getF_face(double alpha, double alpha0, Alpha_type p, Vector3 n,
		Vector3 p1, Vector3 p2, Vector3 p3) {

		double k = K_face * (alpha - alpha0);

		if (p == Alpha_type::p1) {
			double len = p1.distance(p2);
			return dotVec(n, p1 - p2) * k / (len * len);
		}
		else if (p == Alpha_type::p2) {
			Vector3 v1 = dotVec(n, p1 - p2);
			Vector3 v2 = dotVec(n, p3 - p2);
			double len1 = p1.distance(p2);
			double len2 = p2.distance(p3);
			Vector3 ode = dotVec(n, p3 - p2)/(len2 * len2) - dotVec(n, p1 - p2) / (len1 * len1);
			return ode * k;
		}
		else {
			double len = p3.distance(p2);
			Vector3 ode = dotVec(n, p3 - p2) / (len * len);
			return ode * k;
		}
	}
};
