#include "CNode.h"

CNode::CNode(CModel* model) {
	this->position.set(0.0f,0.0f,0.0f);
	this->rotation.set(0.0f,0.0f,0.0f);
	this->model = model;
}

void CNode::setPosition(float x,float y,float z) {
	this->position.set(x,y,z);
}

void CNode::setRotation(float x,float y,float z) {
	this->rotation.set(x,y,z);
}

void CNode::addPosition(float x,float y,float z) {
	this->position.set(this->position.getX() + x,this->position.getY() + y,this->position.getZ() + z);
}

void CNode::addRotation(float x,float y,float z) {
	this->rotation.set(this->rotation.getX() + x,this->rotation.getY() + y,this->rotation.getZ() + z);
}

void CNode::updateMatrix() {
	this->matrix.identity();
	this->matrix.rotate(this->rotation);
	this->matrix.translate(this->position);
}

void CNode::inverseMatrix() {
	this->matrix.inverse();
}

CMatrix CNode::getMatrix() {
	return this->matrix;
}

void CNode::render(CConsoleImage &c,CMatrix &viewMatrix) {
	if (this->model) this->model->render(c,viewMatrix,this->matrix);
}