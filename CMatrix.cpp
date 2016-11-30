#include <iostream>
#include "CMatrix.h"

// This class was made to perform the 4x4 Matrix calculations nessecary for 3D rendering
// Matrix Layout
// X Y Z 0 <- Local X Axis
// X Y Z 0 <- Local Y Axis
// X Y Z 0 <- Local Z Axis
// X Y Z 1 <- World Position

CMatrix::CMatrix() {
	this->identity();
}

// 
void CMatrix::zero() {
	this->m_data[0] = 0.0f;
	this->m_data[1] = 0.0f;
	this->m_data[2] = 0.0f;
	this->m_data[3] = 0.0f;
	this->m_data[4] = 0.0f;
	this->m_data[5] = 0.0f;
	this->m_data[6] = 0.0f;
	this->m_data[7] = 0.0f;
	this->m_data[8] = 0.0f;
	this->m_data[9] = 0.0f;
	this->m_data[10] = 0.0f;
	this->m_data[11] = 0.0f;
	this->m_data[12] = 0.0f;
	this->m_data[13] = 0.0f;
	this->m_data[14] = 0.0f;
	this->m_data[15] = 0.0f;
}

void CMatrix::identity() {
	this->m_data[0] = 1.0f;
	this->m_data[1] = 0.0f;
	this->m_data[2] = 0.0f;
	this->m_data[3] = 0.0f;
	this->m_data[4] = 0.0f;
	this->m_data[5] = 1.0f;
	this->m_data[6] = 0.0f;
	this->m_data[7] = 0.0f;
	this->m_data[8] = 0.0f;
	this->m_data[9] = 0.0f;
	this->m_data[10] = 1.0f;
	this->m_data[11] = 0.0f;
	this->m_data[12] = 0.0f;
	this->m_data[13] = 0.0f;
	this->m_data[14] = 0.0f;
	this->m_data[15] = 1.0f;
}

void CMatrix::inverse() {
	float tmpData [16];
	float det = 0.0f;
	tmpData[0] = this->m_data[5]  * this->m_data[10] * this->m_data[15] - 
             this->m_data[5]  * this->m_data[11] * this->m_data[14] - 
             this->m_data[9]  * this->m_data[6]  * this->m_data[15] + 
             this->m_data[9]  * this->m_data[7]  * this->m_data[14] +
             this->m_data[13] * this->m_data[6]  * this->m_data[11] - 
             this->m_data[13] * this->m_data[7]  * this->m_data[10];

    tmpData[4] = -this->m_data[4]  * this->m_data[10] * this->m_data[15] + 
              this->m_data[4]  * this->m_data[11] * this->m_data[14] + 
              this->m_data[8]  * this->m_data[6]  * this->m_data[15] - 
              this->m_data[8]  * this->m_data[7]  * this->m_data[14] - 
              this->m_data[12] * this->m_data[6]  * this->m_data[11] + 
              this->m_data[12] * this->m_data[7]  * this->m_data[10];

    tmpData[8] = this->m_data[4]  * this->m_data[9] * this->m_data[15] - 
             this->m_data[4]  * this->m_data[11] * this->m_data[13] - 
             this->m_data[8]  * this->m_data[5] * this->m_data[15] + 
             this->m_data[8]  * this->m_data[7] * this->m_data[13] + 
             this->m_data[12] * this->m_data[5] * this->m_data[11] - 
             this->m_data[12] * this->m_data[7] * this->m_data[9];

    tmpData[12] = -this->m_data[4]  * this->m_data[9] * this->m_data[14] + 
               this->m_data[4]  * this->m_data[10] * this->m_data[13] +
               this->m_data[8]  * this->m_data[5] * this->m_data[14] - 
               this->m_data[8]  * this->m_data[6] * this->m_data[13] - 
               this->m_data[12] * this->m_data[5] * this->m_data[10] + 
               this->m_data[12] * this->m_data[6] * this->m_data[9];

    tmpData[1] = -this->m_data[1]  * this->m_data[10] * this->m_data[15] + 
              this->m_data[1]  * this->m_data[11] * this->m_data[14] + 
              this->m_data[9]  * this->m_data[2] * this->m_data[15] - 
              this->m_data[9]  * this->m_data[3] * this->m_data[14] - 
              this->m_data[13] * this->m_data[2] * this->m_data[11] + 
              this->m_data[13] * this->m_data[3] * this->m_data[10];

    tmpData[5] = this->m_data[0]  * this->m_data[10] * this->m_data[15] - 
             this->m_data[0]  * this->m_data[11] * this->m_data[14] - 
             this->m_data[8]  * this->m_data[2] * this->m_data[15] + 
             this->m_data[8]  * this->m_data[3] * this->m_data[14] + 
             this->m_data[12] * this->m_data[2] * this->m_data[11] - 
             this->m_data[12] * this->m_data[3] * this->m_data[10];

    tmpData[9] = -this->m_data[0]  * this->m_data[9] * this->m_data[15] + 
              this->m_data[0]  * this->m_data[11] * this->m_data[13] + 
              this->m_data[8]  * this->m_data[1] * this->m_data[15] - 
              this->m_data[8]  * this->m_data[3] * this->m_data[13] - 
              this->m_data[12] * this->m_data[1] * this->m_data[11] + 
              this->m_data[12] * this->m_data[3] * this->m_data[9];

    tmpData[13] = this->m_data[0]  * this->m_data[9] * this->m_data[14] - 
              this->m_data[0]  * this->m_data[10] * this->m_data[13] - 
              this->m_data[8]  * this->m_data[1] * this->m_data[14] + 
              this->m_data[8]  * this->m_data[2] * this->m_data[13] + 
              this->m_data[12] * this->m_data[1] * this->m_data[10] - 
              this->m_data[12] * this->m_data[2] * this->m_data[9];

    tmpData[2] = this->m_data[1]  * this->m_data[6] * this->m_data[15] - 
             this->m_data[1]  * this->m_data[7] * this->m_data[14] - 
             this->m_data[5]  * this->m_data[2] * this->m_data[15] + 
             this->m_data[5]  * this->m_data[3] * this->m_data[14] + 
             this->m_data[13] * this->m_data[2] * this->m_data[7] - 
             this->m_data[13] * this->m_data[3] * this->m_data[6];

    tmpData[6] = -this->m_data[0]  * this->m_data[6] * this->m_data[15] + 
              this->m_data[0]  * this->m_data[7] * this->m_data[14] + 
              this->m_data[4]  * this->m_data[2] * this->m_data[15] - 
              this->m_data[4]  * this->m_data[3] * this->m_data[14] - 
              this->m_data[12] * this->m_data[2] * this->m_data[7] + 
              this->m_data[12] * this->m_data[3] * this->m_data[6];

    tmpData[10] = this->m_data[0]  * this->m_data[5] * this->m_data[15] - 
              this->m_data[0]  * this->m_data[7] * this->m_data[13] - 
              this->m_data[4]  * this->m_data[1] * this->m_data[15] + 
              this->m_data[4]  * this->m_data[3] * this->m_data[13] + 
              this->m_data[12] * this->m_data[1] * this->m_data[7] - 
              this->m_data[12] * this->m_data[3] * this->m_data[5];

    tmpData[14] = -this->m_data[0]  * this->m_data[5] * this->m_data[14] + 
               this->m_data[0]  * this->m_data[6] * this->m_data[13] + 
               this->m_data[4]  * this->m_data[1] * this->m_data[14] - 
               this->m_data[4]  * this->m_data[2] * this->m_data[13] - 
               this->m_data[12] * this->m_data[1] * this->m_data[6] + 
               this->m_data[12] * this->m_data[2] * this->m_data[5];

    tmpData[3] = -this->m_data[1] * this->m_data[6] * this->m_data[11] + 
              this->m_data[1] * this->m_data[7] * this->m_data[10] + 
              this->m_data[5] * this->m_data[2] * this->m_data[11] - 
              this->m_data[5] * this->m_data[3] * this->m_data[10] - 
              this->m_data[9] * this->m_data[2] * this->m_data[7] + 
              this->m_data[9] * this->m_data[3] * this->m_data[6];

    tmpData[7] = this->m_data[0] * this->m_data[6] * this->m_data[11] - 
             this->m_data[0] * this->m_data[7] * this->m_data[10] - 
             this->m_data[4] * this->m_data[2] * this->m_data[11] + 
             this->m_data[4] * this->m_data[3] * this->m_data[10] + 
             this->m_data[8] * this->m_data[2] * this->m_data[7] - 
             this->m_data[8] * this->m_data[3] * this->m_data[6];

    tmpData[11] = -this->m_data[0] * this->m_data[5] * this->m_data[11] + 
               this->m_data[0] * this->m_data[7] * this->m_data[9] + 
               this->m_data[4] * this->m_data[1] * this->m_data[11] - 
               this->m_data[4] * this->m_data[3] * this->m_data[9] - 
               this->m_data[8] * this->m_data[1] * this->m_data[7] + 
               this->m_data[8] * this->m_data[3] * this->m_data[5];

    tmpData[15] = this->m_data[0] * this->m_data[5] * this->m_data[10] - 
              this->m_data[0] * this->m_data[6] * this->m_data[9] - 
              this->m_data[4] * this->m_data[1] * this->m_data[10] + 
              this->m_data[4] * this->m_data[2] * this->m_data[9] + 
              this->m_data[8] * this->m_data[1] * this->m_data[6] - 
              this->m_data[8] * this->m_data[2] * this->m_data[5];

    det = this->m_data[0] * tmpData[0] + this->m_data[1] * tmpData[4] + this->m_data[2] * tmpData[8] + this->m_data[3] * tmpData[12];

    if (det == 0.0f) return;
    det = 1.0f / det;

    this->m_data[0] = tmpData[0] * det;
    this->m_data[1] = tmpData[1] * det;
    this->m_data[2] = tmpData[2] * det;
    this->m_data[3] = tmpData[3] * det;
    this->m_data[4] = tmpData[4] * det;
    this->m_data[5] = tmpData[5] * det;
    this->m_data[6] = tmpData[6] * det;
    this->m_data[7] = tmpData[7] * det;
    this->m_data[8] = tmpData[8] * det;
    this->m_data[9] = tmpData[9] * det;
    this->m_data[10] = tmpData[10] * det;
    this->m_data[11] = tmpData[11] * det;
    this->m_data[12] = tmpData[12] * det;
    this->m_data[13] = tmpData[13] * det;
    this->m_data[14] = tmpData[14] * det;
    this->m_data[15] = tmpData[15] * det;
}

void CMatrix::rotateX(float angle) {
	CMatrix tmp;
	tmp.m_data[5] = cos(angle);
	tmp.m_data[6] = -sin(angle);
	tmp.m_data[9] = sin(angle);
	tmp.m_data[10] = cos(angle);
	(*this) *= tmp;
}

void CMatrix::rotateY(float angle) {
	CMatrix tmp;
	tmp.m_data[0] = cos(angle);
	tmp.m_data[2] = sin(angle);
	tmp.m_data[8] = -sin(angle);
	tmp.m_data[10] = cos(angle);
	(*this) *= tmp;
}

void CMatrix::rotateZ(float angle) {
	CMatrix tmp;
	tmp.m_data[0] = cos(angle);
	tmp.m_data[1] = -sin(angle);
	tmp.m_data[4] = sin(angle);
	tmp.m_data[5] = cos(angle);
	(*this) *= tmp;
}

void CMatrix::translate(float x,float y,float z) {
	this->m_data[12] += x;
	this->m_data[13] += y;
	this->m_data[14] += z;
}

void CMatrix::translate(CVector &v) {
	(*this) += v;
}

void CMatrix::rotate(CVector &v) {
	this->rotateX(v.getX());
	this->rotateY(v.getY());
	this->rotateZ(v.getZ());
}

void CMatrix::copy(CMatrix &m) {
	float* data = m.getData();
	this->m_data[0] = data[0];
	this->m_data[1] = data[1];
	this->m_data[2] = data[2];
	this->m_data[3] = data[3];
	this->m_data[4] = data[4];
	this->m_data[5] = data[5];
	this->m_data[6] = data[6];
	this->m_data[7] = data[7];
	this->m_data[8] = data[8];
	this->m_data[9] = data[9];
	this->m_data[10] = data[10];
	this->m_data[11] = data[11];
	this->m_data[12] = data[12];
	this->m_data[13] = data[13];
	this->m_data[14] = data[14];
	this->m_data[15] = data[15];
}

void CMatrix::toConsole() {
	std::cout << this->m_data[0] << "," << this->m_data[1] << "," << this->m_data[2] << "," << this->m_data[3] << std::endl
			  << this->m_data[4] << "," << this->m_data[5] << "," << this->m_data[6] << "," << this->m_data[7] << std::endl
			  << this->m_data[8] << "," << this->m_data[9] << "," << this->m_data[10] << "," << this->m_data[11] << std::endl
			  << this->m_data[12] << "," << this->m_data[13] << "," << this->m_data[14] << "," << this->m_data[15] << std::endl;
}

float* CMatrix::getData() {
	return this->m_data;
}

// Mathmatic Operators Matrix - Matrix
CMatrix CMatrix::operator+(CMatrix &m) {
	CMatrix tmp;
	float* data = m.getData();
	tmp.m_data[0] = this->m_data[0] + data[0];
	tmp.m_data[1] = this->m_data[1] + data[1];
	tmp.m_data[2] = this->m_data[2] + data[2];
	tmp.m_data[3] = this->m_data[3] + data[3];
	tmp.m_data[4] = this->m_data[4] + data[4];
	tmp.m_data[5] = this->m_data[5] + data[5];
	tmp.m_data[6] = this->m_data[6] + data[6];
	tmp.m_data[7] = this->m_data[7] + data[7];
	tmp.m_data[8] = this->m_data[8] + data[8];
	tmp.m_data[9] = this->m_data[9] + data[9];
	tmp.m_data[10] = this->m_data[10] + data[10];
	tmp.m_data[11] = this->m_data[11] + data[11];
	tmp.m_data[12] = this->m_data[12] + data[12];
	tmp.m_data[13] = this->m_data[13] + data[13];
	tmp.m_data[14] = this->m_data[14] + data[14];
	tmp.m_data[15] = this->m_data[15] + data[15];
	return tmp;
}

CMatrix CMatrix::operator+=(CMatrix &m) {
	float* data = m.getData();
	this->m_data[0] = this->m_data[0] + data[0];
	this->m_data[1] = this->m_data[1] + data[1];
	this->m_data[2] = this->m_data[2] + data[2];
	this->m_data[3] = this->m_data[3] + data[3];
	this->m_data[4] = this->m_data[4] + data[4];
	this->m_data[5] = this->m_data[5] + data[5];
	this->m_data[6] = this->m_data[6] + data[6];
	this->m_data[7] = this->m_data[7] + data[7];
	this->m_data[8] = this->m_data[8] + data[8];
	this->m_data[9] = this->m_data[9] + data[9];
	this->m_data[10] = this->m_data[10] + data[10];
	this->m_data[11] = this->m_data[11] + data[11];
	this->m_data[12] = this->m_data[12] + data[12];
	this->m_data[13] = this->m_data[13] + data[13];
	this->m_data[14] = this->m_data[14] + data[14];
	this->m_data[15] = this->m_data[15] + data[15];
	return (*this);
}

CMatrix CMatrix::operator-(CMatrix &m) {
	CMatrix tmp;
	float* data = m.getData();
	tmp.m_data[0] = this->m_data[0] - data[0];
	tmp.m_data[1] = this->m_data[1] - data[1];
	tmp.m_data[2] = this->m_data[2] - data[2];
	tmp.m_data[3] = this->m_data[3] - data[3];
	tmp.m_data[4] = this->m_data[4] - data[4];
	tmp.m_data[5] = this->m_data[5] - data[5];
	tmp.m_data[6] = this->m_data[6] - data[6];
	tmp.m_data[7] = this->m_data[7] - data[7];
	tmp.m_data[8] = this->m_data[8] - data[8];
	tmp.m_data[9] = this->m_data[9] - data[9];
	tmp.m_data[10] = this->m_data[10] - data[10];
	tmp.m_data[11] = this->m_data[11] - data[11];
	tmp.m_data[12] = this->m_data[12] - data[12];
	tmp.m_data[13] = this->m_data[13] - data[13];
	tmp.m_data[14] = this->m_data[14] - data[14];
	tmp.m_data[15] = this->m_data[15] - data[15];
	return tmp;
}

CMatrix CMatrix::operator-=(CMatrix &m) {
	float* data = m.getData();
	this->m_data[0] = this->m_data[0] - data[0];
	this->m_data[1] = this->m_data[1] - data[1];
	this->m_data[2] = this->m_data[2] - data[2];
	this->m_data[3] = this->m_data[3] - data[3];
	this->m_data[4] = this->m_data[4] - data[4];
	this->m_data[5] = this->m_data[5] - data[5];
	this->m_data[6] = this->m_data[6] - data[6];
	this->m_data[7] = this->m_data[7] - data[7];
	this->m_data[8] = this->m_data[8] - data[8];
	this->m_data[9] = this->m_data[9] - data[9];
	this->m_data[10] = this->m_data[10] - data[10];
	this->m_data[11] = this->m_data[11] - data[11];
	this->m_data[12] = this->m_data[12] - data[12];
	this->m_data[13] = this->m_data[13] - data[13];
	this->m_data[14] = this->m_data[14] - data[14];
	this->m_data[15] = this->m_data[15] - data[15];
	return (*this);
}

CMatrix CMatrix::operator*(CMatrix &m) {
	CMatrix tmp;
	float* tmpData = tmp.getData();
	float* data = m.getData();

	tmpData[0] = this->m_data[0]*data[0] + this->m_data[1]*data[4] + this->m_data[2]*data[8] + this->m_data[3]*data[12];
	tmpData[1] = this->m_data[0]*data[1] + this->m_data[1]*data[5] + this->m_data[2]*data[9] + this->m_data[3]*data[13];
	tmpData[2] = this->m_data[0]*data[2] + this->m_data[1]*data[6] + this->m_data[2]*data[10] + this->m_data[3]*data[14];
	tmpData[3] = this->m_data[0]*data[3] + this->m_data[1]*data[7] + this->m_data[2]*data[11] + this->m_data[3]*data[15];
		
	tmpData[4] = this->m_data[4]*data[0] + this->m_data[5]*data[4] + this->m_data[6]*data[8] + this->m_data[7]*data[12];
	tmpData[5] = this->m_data[4]*data[1] + this->m_data[5]*data[5] + this->m_data[6]*data[9] + this->m_data[7]*data[13];
	tmpData[6] = this->m_data[4]*data[2] + this->m_data[5]*data[6] + this->m_data[6]*data[10] + this->m_data[7]*data[14];
	tmpData[7] = this->m_data[4]*data[3] + this->m_data[5]*data[7] + this->m_data[6]*data[11] + this->m_data[7]*data[15];
	
	tmpData[8] = this->m_data[8]*data[0] + this->m_data[9]*data[4] + this->m_data[10]*data[8] + this->m_data[11]*data[12];
	tmpData[9] = this->m_data[8]*data[1] + this->m_data[9]*data[5] + this->m_data[10]*data[9] + this->m_data[11]*data[13];
	tmpData[10] = this->m_data[8]*data[2] + this->m_data[9]*data[6] + this->m_data[10]*data[10] + this->m_data[11]*data[14];
	tmpData[11] = this->m_data[8]*data[3] + this->m_data[9]*data[7] + this->m_data[10]*data[11] + this->m_data[11]*data[15];
	
	tmpData[12] = this->m_data[12]*data[0] + this->m_data[13]*data[4] + this->m_data[14]*data[8] + this->m_data[15]*data[12];
	tmpData[13] = this->m_data[12]*data[1] + this->m_data[13]*data[5] + this->m_data[14]*data[9] + this->m_data[15]*data[13];
	tmpData[14] = this->m_data[12]*data[2] + this->m_data[13]*data[6] + this->m_data[14]*data[10] + this->m_data[15]*data[14];
	tmpData[15] = this->m_data[12]*data[3] + this->m_data[13]*data[7] + this->m_data[14]*data[11] + this->m_data[15]*data[15];
	return tmp;
}

CMatrix CMatrix::operator*=(CMatrix &m) {
	float tmpData [16];
	float* data = m.getData();

	tmpData[0] = this->m_data[0]*data[0] + this->m_data[1]*data[4] + this->m_data[2]*data[8] + this->m_data[3]*data[12];
	tmpData[1] = this->m_data[0]*data[1] + this->m_data[1]*data[5] + this->m_data[2]*data[9] + this->m_data[3]*data[13];
	tmpData[2] = this->m_data[0]*data[2] + this->m_data[1]*data[6] + this->m_data[2]*data[10] + this->m_data[3]*data[14];
	tmpData[3] = this->m_data[0]*data[3] + this->m_data[1]*data[7] + this->m_data[2]*data[11] + this->m_data[3]*data[15];
		
	tmpData[4] = this->m_data[4]*data[0] + this->m_data[5]*data[4] + this->m_data[6]*data[8] + this->m_data[7]*data[12];
	tmpData[5] = this->m_data[4]*data[1] + this->m_data[5]*data[5] + this->m_data[6]*data[9] + this->m_data[7]*data[13];
	tmpData[6] = this->m_data[4]*data[2] + this->m_data[5]*data[6] + this->m_data[6]*data[10] + this->m_data[7]*data[14];
	tmpData[7] = this->m_data[4]*data[3] + this->m_data[5]*data[7] + this->m_data[6]*data[11] + this->m_data[7]*data[15];
	
	tmpData[8] = this->m_data[8]*data[0] + this->m_data[9]*data[4] + this->m_data[10]*data[8] + this->m_data[11]*data[12];
	tmpData[9] = this->m_data[8]*data[1] + this->m_data[9]*data[5] + this->m_data[10]*data[9] + this->m_data[11]*data[13];
	tmpData[10] = this->m_data[8]*data[2] + this->m_data[9]*data[6] + this->m_data[10]*data[10] + this->m_data[11]*data[14];
	tmpData[11] = this->m_data[8]*data[3] + this->m_data[9]*data[7] + this->m_data[10]*data[11] + this->m_data[11]*data[15];
	
	tmpData[12] = this->m_data[12]*data[0] + this->m_data[13]*data[4] + this->m_data[14]*data[8] + this->m_data[15]*data[12];
	tmpData[13] = this->m_data[12]*data[1] + this->m_data[13]*data[5] + this->m_data[14]*data[9] + this->m_data[15]*data[13];
	tmpData[14] = this->m_data[12]*data[2] + this->m_data[13]*data[6] + this->m_data[14]*data[10] + this->m_data[15]*data[14];
	tmpData[15] = this->m_data[12]*data[3] + this->m_data[13]*data[7] + this->m_data[14]*data[11] + this->m_data[15]*data[15];
		
	this->m_data[0] = tmpData[0];
	this->m_data[1] = tmpData[1];
	this->m_data[2] = tmpData[2];
	this->m_data[3] = tmpData[3];
	this->m_data[4] = tmpData[4];
	this->m_data[5] = tmpData[5];
	this->m_data[6] = tmpData[6];
	this->m_data[7] = tmpData[7];
	this->m_data[8] = tmpData[8];
	this->m_data[9] = tmpData[9];
	this->m_data[10] = tmpData[10];
	this->m_data[11] = tmpData[11];
	this->m_data[12] = tmpData[12];
	this->m_data[13] = tmpData[13];
	this->m_data[14] = tmpData[14];
	this->m_data[15] = tmpData[15];
	return (*this);
}

CMatrix CMatrix::operator/(CMatrix &m) {
	CMatrix tmp;
	CMatrix res;
	tmp.copy(m);
	tmp.inverse();
	res = (*this) * tmp;
	return res;
}

CMatrix CMatrix::operator/=(CMatrix &m) {
	CMatrix tmp;
	tmp.copy(m);
	tmp.inverse();
	(*this) *= tmp;
	return (*this);
}

// Matrix - Vector Operators

CMatrix CMatrix::operator+(CVector &v) {
	CMatrix tmp;
	tmp.copy(*this);
	float* data = tmp.getData();
	data[12] += v.getX();
	data[13] += v.getY();
	data[14] += v.getZ();
	return tmp;
}

CMatrix CMatrix::operator+=(CVector &v) {
	this->m_data[12] += v.getX();
	this->m_data[13] += v.getY();
	this->m_data[14] += v.getZ();
	return (*this);
}

CMatrix CMatrix::operator-(CVector &v) {
	CMatrix tmp;
	tmp.copy(*this);
	float* data = tmp.getData();
	data[12] -= v.getX();
	data[13] -= v.getY();
	data[14] -= v.getZ();
	return tmp;
}

CMatrix CMatrix::operator-=(CVector &v) {
	this->m_data[12] -= v.getX();
	this->m_data[13] -= v.getY();
	this->m_data[14] -= v.getZ();
	return (*this);
}

CMatrix CMatrix::operator*(CVector &v) {
	CMatrix tmp;
	tmp.copy(*this);
	float* data = tmp.getData();
	data[12] *= v.getX();
	data[13] *= v.getY();
	data[14] *= v.getZ();
	return tmp;
}

CMatrix CMatrix::operator*=(CVector &v) {
	this->m_data[12] *= v.getX();
	this->m_data[13] *= v.getY();
	this->m_data[14] *= v.getZ();
	return (*this);
}

CMatrix CMatrix::operator/(CVector &v) {
	CMatrix tmp;
	tmp.copy(*this);
	float* data = tmp.getData();
	data[12] /= v.getX();
	data[13] /= v.getY();
	data[14] /= v.getZ();
	return tmp;
}

CMatrix CMatrix::operator/=(CVector &v) {
	this->m_data[12] /= v.getX();
	this->m_data[13] /= v.getY();
	this->m_data[14] /= v.getZ();
	return (*this);
}
