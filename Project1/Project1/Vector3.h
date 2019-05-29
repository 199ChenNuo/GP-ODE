#include "node.h"
#include "beam.h"

struct Vector3;

using namespace std;

	
Vector3 normalize(Vector3 pos1, Vector3 pos2) {
    Vector3 direction = Vector3(pos1.x - pos2.x, pos1.y - pos2.y, pos1.z - pos2.z);
    float len = direction.length();
    return Vector3(direction.x / len, direction.y / len, direction.z / len);
}

Vector3 dotVec(Vector3 v1, Vector3 v2) {
    return Vector3(v1.y*v2.z - v2.y*v1.z, v1.z*v2.x - v2.z*v1.x, v1.x*v2.y - v2.x*v1.y);
}

struct Vector3 {
	float x, y, z;

	Vector3(float _x, float _y, float _z)
		:x(_x), y(_y), z(_z) {}

	Vector3()
		:x(0.0f), y(0.0f),z(0.0f) {}

	Vector3(double v)
		:x(v), y(v), z(v){}

	bool operator==(const Vector3 &other) {
		return (other.x == this->x) && (other.y == this->y)&(other.z == this->z);
	}

	Vector3 operator + (const Vector3 & other) {
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Vector3 operator / (const double k) {
		return Vector3(this->x / k, this->y / k, this->z / k);
	}

	Vector3 operator - (const Vector3 & other) {
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	
	Vector3 operator * (const double other) {
		return Vector3(this->x * other, this->y * other, this->z * other);
	}

	Vector3 operator * (const int other) {
		return Vector3(this->x * other, this->y * other, this->z * other);
	}

	Vector3 operator * (const float other) {
		return Vector3(this->x * other, this->y * other, this->z * other);
	}

	// the length of `this`
	float length() {
		return sqrtf(powf(this->x, 2) + powf((this->y), 2) + powf((this->z), 2));
	}

	// distanve from `this` to `other`
	float distance(const Vector3 &other) {
		return sqrtf(powf((other.x - this->x), 2) + powf((other.y - this->y), 2) + powf((other.z - this->z), 2));
	}

	// if two Vector3 is parallel
	bool parallel(const Vector3& other) {
		if (other.x == 0) {
			if (other.y == 0) {
				return true;
			}
			if (other.z == 0) {
				return true;
			}
			return this->x == 0 && this->y / other.y == this->z / other.z;
		}
		return this->x / other.x == this->y / other.y && this->x / other.x == this->z / other.z;
	}
};