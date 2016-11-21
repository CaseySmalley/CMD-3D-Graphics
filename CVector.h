#pragma once

class CVector {
private:
	float m_data [3];
public:
	CVector();
	CVector(float x,float y,float z);

	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void set(float x,float y,float z);

	float getX();
	float getY();
	float getZ();

	void toConsole();

	CVector operator+(CVector &v);
	CVector operator+=(CVector &v);
	CVector operator-(CVector &v);
	CVector operator-=(CVector &v);
	CVector operator*(CVector &v);
	CVector operator*=(CVector &v);
	CVector operator/(CVector &v);
	CVector operator/=(CVector &v);
};