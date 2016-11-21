#define _USE_MATH_DEFINES
#include "CConsoleImage.h"

unsigned int CConsoleImage::imageWidth = 78;
unsigned int CConsoleImage::imageHeight = 24;

float CConsoleImage::fov = 60.0f * (M_PI / 180.0f);
float CConsoleImage::screenDistance = (imageWidth*0.5f) / tan(fov*0.5f);
float CConsoleImage::cScreenWidth = 2 * screenDistance * tan(fov*0.5f);
float CConsoleImage::cScreenHeight = 2 * screenDistance * tan(fov*0.5f);

CConsoleImage::CConsoleImage() {
	this->image = new std::string[this->imageHeight];

	for (int x = 0; x < this->imageWidth; ++x) {
		this->line.append(" ");
	}

	for (int y = 0; y < this->imageHeight; ++y) {
		this->image[y] = this->line;
	}
}

CConsoleImage::~CConsoleImage() {
	delete[] this->image;
}

void CConsoleImage::drawPixel(int x,int y) {
	if (x > 0 && x < this->imageWidth && y > 0 && y < this->imageHeight)
		this->image[y][x] = '*';
}

void CConsoleImage::drawLine(float x1,float y1,float x2,float y2) {
	int maxDist = 0;
	(abs(x2 - x1) < abs(y2 - y1)) ? maxDist = abs(y2 - y1) : maxDist = abs(x2 - x1);
	float xStep = (x2 - x1) / maxDist;
	float yStep = (y2 - y1) / maxDist;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	while(maxDist >= 0) {
		this->drawPixel((int) x,(int) y);
		x += xStep;
		y += yStep;
		--maxDist;
	}
}

void CConsoleImage::render() {
	std::string out;
	for (int y = 0; y < this->imageHeight; ++y) {
		out.append(this->image[y] + "\n");
		this->image[y] = this->line;
	}
	std::cout << out;
}