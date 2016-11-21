#pragma once
#include "CVector.h"

class CMatrix {
private:
	float m_data[16];
public:
	CMatrix();
	void zero();
	void identity();
	void inverse();

	void translate(float x,float y,float z);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void copy(CMatrix& m);

	void translate(CVector &v);
	void rotate(CVector &v);

	void toConsole();
	float* getData();

	CMatrix operator+(CMatrix &m);
	CMatrix operator+=(CMatrix &m);
	CMatrix operator-(CMatrix &m);
	CMatrix operator-=(CMatrix &m);
	CMatrix operator*(CMatrix &m);
	CMatrix operator*=(CMatrix &m);
	CMatrix operator/(CMatrix &m);
	CMatrix operator/=(CMatrix &m);

	CMatrix operator+(CVector &v);
	CMatrix operator+=(CVector &v);
	CMatrix operator-(CVector &v);
	CMatrix operator-=(CVector &v);
	CMatrix operator*(CVector &v);
	CMatrix operator*=(CVector &v);
	CMatrix operator/(CVector &v);
	CMatrix operator/=(CVector &v);
};
