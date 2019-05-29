#include "node.h"

void Node::setFixed(bool _fixed){
	this->fixed = _fixed;
	// update material according to changes
	// if(fixed){
	// 	update material and geometry to fixed ones
	// 	hide force for this node
	// } else {
	// 	update material and geometry to dynamic ones
	// 	show force for this node
	// }
}

bool Node::isFixed(){
	return this->fixed;
}

void Node::addExternalForce(Vector3 force){
	this->externalForce = force;
	// Vector3 position = this->getOriginalPosition();
	// add force to `position`
	// if (fixed) this.externalForce.hide()
}
	

Vector3 Node::getExternalForce() {
	return this->externalForce;
}

Vector3 Node::get_original_position() {
	return this->originPosition;
}

bool Node::operator == (const Node& other) {
	return this->id == other.id;
}

double Node::getSimMass() {
	// mass
	return 1;
}