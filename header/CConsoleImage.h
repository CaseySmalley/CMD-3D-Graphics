#pragma once
#include <iostream>
#include <string>
#include <math.h>

class CConsoleImage {
private:
	std::string* image;
	std::string line;
public:
	unsigned static int imageWidth;
	unsigned static int imageHeight;
	static float fov;
	static float screenDistance;
	static float cScreenWidth;
	static float cScreenHeight;
	CConsoleImage();
	~CConsoleImage();

	void drawLine(float x1,float y1,float x2,float y2);
	void drawPixel(int x,int y);
	void render();
};
