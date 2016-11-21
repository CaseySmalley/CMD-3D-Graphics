#pragma once
#include <vector>
#include "CMatrix.h"
#include "CVector.h"
#include "CConsoleImage.h"

class CModel {
private:
	std::vector<CVector> verticies;
	std::vector<int> indicies;
public:
	CModel(std::vector<CVector> verticies,std::vector<int> indicies);
	void render(CConsoleImage &c,CMatrix &viewMatrix,CMatrix &worldMatrix);
};
