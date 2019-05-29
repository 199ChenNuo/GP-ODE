#include "crease.h"

using namespace std;

class Crease {
    
private:
	Crease_type type;
    int id;

public:
	bool operator==(const Crease& other) {
		return this->id == other.id;
	}

	double getK_crease(double l0) {
		if (this->type == Crease_type::mountain || this->type == Crease_type::velly) {
			return l0 * K_flod;
		}
		else if (this->type == Crease_type::facet) {
			return l0 * K_facet;
		}
		// boundary crease or undriven crease
		return 0;
	}
};
