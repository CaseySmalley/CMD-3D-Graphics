#pragma once
#include "CVector.h"
#include "CMatrix.h"
#include "CModel.h"
#include "CConsoleImage.h"

class CNode {
private:
	CVector position;
	CVector rotation;
	CMatrix matrix;
	CModel* model;
public:
	CNode(CModel* model);
	void setPosition(float x,float y,float z);
	void setRotation(float x,float y,float z);
	void addPosition(float x,float y,float z);
	void addRotation(float x,float y,float z);
	void updateMatrix();
	void inverseMatrix();
	CMatrix getMatrix();
	void render(CConsoleImage &c,CMatrix &viewMatrix);
};