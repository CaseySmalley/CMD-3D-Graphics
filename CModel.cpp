#include "CModel.h"

CModel::CModel(std::vector<CVector> verticies,std::vector<int> indicies) {
	this->verticies = verticies;
	this->indicies = indicies;
}

void CModel::render(CConsoleImage &c,CMatrix &viewMatrix,CMatrix &worldMatrix) {
	std::vector<CVector> coords;
	CMatrix tmp;
	float x,y,z = 0.0f;
	float* data = NULL;

	for (unsigned int i = 0; i < this->verticies.size(); ++i) {
		tmp.identity();
		tmp.translate(this->verticies[i]);
		tmp *= worldMatrix * viewMatrix;
		data = tmp.getData();

		if (data[14] > 0) {

			x = CConsoleImage::screenDistance * (data[12] / data[14]);
			y = CConsoleImage::screenDistance * (data[13] / data[14]);
		
			x = 2 * x / CConsoleImage::cScreenWidth;
			y = 2 * y / CConsoleImage::cScreenHeight;

			x = (x + 1) * (CConsoleImage::imageWidth/2.0f);
			y = (y + 1) * (CConsoleImage::imageHeight/2.0f);

			coords.push_back(CVector(x,y,0.0));
		} else return;
	}

	for (int i = 0; i < this->indicies.size(); i += 4) {
		c.drawLine(
			coords[this->indicies[i]].getX(),coords[this->indicies[i]].getY(),
			coords[this->indicies[i+1]].getX(),coords[this->indicies[i+1]].getY()
		);

		c.drawLine(
			coords[this->indicies[i+1]].getX(),coords[this->indicies[i+1]].getY(),
			coords[this->indicies[i+2]].getX(),coords[this->indicies[i+2]].getY()
		);

		c.drawLine(
			coords[this->indicies[i+2]].getX(),coords[this->indicies[i+2]].getY(),
			coords[this->indicies[i+3]].getX(),coords[this->indicies[i+3]].getY()
		);

		c.drawLine(
			coords[this->indicies[i+3]].getX(),coords[this->indicies[i+3]].getY(),
			coords[this->indicies[i]].getX(),coords[this->indicies[i]].getY()
		);
	}
}