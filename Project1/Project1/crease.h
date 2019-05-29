#include "macro.h"

class Crease {
private:
    Crease_type type;
    int id;
public:
    bool operator == (const Crease& other);
    double getK_crease(double l0);
};