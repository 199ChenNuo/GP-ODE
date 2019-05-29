# include "beam.h"

bool Beam::operator==(Beam beam)
{
	return this->nodes == nodes;
}

Node Beam::getOtherNode(Node node)
{
	if (this->nodes.first == node) {
		return this->nodes.second;
	}
	return this->nodes.first;
}

float Beam::getLength()
{
	return getVector(this->nodes.first).length();
}

float Beam::getOriginalLength()
{
	return this->original_length;
}

void Beam::recalcOriginalLength()
{
	this->original_length = getVector(this->nodes.first).length();
}

bool Beam::isFixed()
{
	return this->nodes.first.isFixed() && this->nodes.second.isFixed();
}

Vector3 Beam::getVector(Node fromNode)
{
	if (fromNode == this->nodes.second) {
		return this->vertices.first - this->vertices.second;
	}
	return this->vertices.second - this->vertices.first;
}

float Beam::getK()
{
	//return globals.axialStiffness/getLength();
	return 0.0f;
}

float Beam::getD()
{
	//return globals.percentDamping*2*sqrt(getK()*getMinMass());
	return 0.0f;
}

float Beam::getNaturalFrequency()
{
	return sqrt(getK()/getMinMass());
}

float Beam::getMinMass()
{
	float minMass = this->nodes.first.getSimMass();
	if (this->nodes.second.getSimMass() < minMass) {
		minMass = this->nodes.second.getSimMass();
	}
	return minMass;
}
