#include <iostream>
#include "CVector.h"

CVector::CVector() {
	this->m_data[0] = 0.0f;
	this->m_data[1] = 0.0f;
	this->m_data[2] = 0.0f;
}

CVector::CVector(float x,float y,float z) {
	this->m_data[0] = x;
	this->m_data[1] = y;
	this->m_data[2] = z;
}

void CVector::setX(float x) {
	this->m_data[0] = x;
}

void CVector::setY(float y) {
	this->m_data[0] = y;
}

void CVector::setZ(float z) {
	this->m_data[0] = z;
}

void CVector::set(float x,float y,float z) {
	this->m_data[0] = x;
	this->m_data[1] = y;
	this->m_data[2] = z;
}

float CVector::getX() {
	return this->m_data[0];
}

float CVector::getY() {
	return this->m_data[1];
}

float CVector::getZ() {
	return this->m_data[2];
}

void CVector::toConsole() {
	std::cout << this->m_data[0] << "," << this->m_data[1] << "," << this->m_data[2] << std::endl;
}

CVector CVector::operator+(CVector &v) {
	CVector tmp;
	tmp.m_data[0] = this->m_data[0] + v.m_data[0];
	tmp.m_data[1] = this->m_data[1] + v.m_data[1];
	tmp.m_data[2] = this->m_data[2] + v.m_data[2];
	return tmp;
}

CVector CVector::operator+=(CVector &v) {
	CVector tmp;
	this->m_data[0] += v.m_data[0];
	this->m_data[1] += v.m_data[1];
	this->m_data[2] += v.m_data[2];
	return (*this);
}

CVector CVector::operator-(CVector &v) {
	CVector tmp;
	tmp.m_data[0] = this->m_data[0] - v.m_data[0];
	tmp.m_data[1] = this->m_data[1] - v.m_data[1];
	tmp.m_data[2] = this->m_data[2] - v.m_data[2];
	return tmp;
}

CVector CVector::operator-=(CVector &v) {
	CVector tmp;
	this->m_data[0] -= v.m_data[0];
	this->m_data[1] -= v.m_data[1];
	this->m_data[2] -= v.m_data[2];
	return (*this);
}

CVector CVector::operator*(CVector &v) {
	CVector tmp;
	tmp.m_data[0] = this->m_data[0] * v.m_data[0];
	tmp.m_data[1] = this->m_data[1] * v.m_data[1];
	tmp.m_data[2] = this->m_data[2] * v.m_data[2];
	return tmp;
}

CVector CVector::operator*=(CVector &v) {
	CVector tmp;
	this->m_data[0] *= v.m_data[0];
	this->m_data[1] *= v.m_data[1];
	this->m_data[2] *= v.m_data[2];
	return (*this);
}

CVector CVector::operator/(CVector &v) {
	CVector tmp;
	tmp.m_data[0] = this->m_data[0] / v.m_data[0];
	tmp.m_data[1] = this->m_data[1] / v.m_data[1];
	tmp.m_data[2] = this->m_data[2] / v.m_data[2];
	return tmp;
}

CVector CVector::operator/=(CVector &v) {
	CVector tmp;
	this->m_data[0] /= v.m_data[0];
	this->m_data[1] /= v.m_data[1];
	this->m_data[2] /= v.m_data[2];
	return (*this);
}