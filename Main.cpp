#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "CVector.h"
#include "CConsoleImage.h"
#include "CModel.h"
#include "CNode.h"

int main() {
	CConsoleImage c;
	CModel squareModel(
		{
			CVector(-0.5f,0.5f,0.5f),
			CVector(0.5f,0.5f,0.5f),
			CVector(-0.5f,-0.5f,0.5f),
			CVector(0.5f,-0.5f,0.5f),
			CVector(-0.5f,0.5f,-0.5f),
			CVector(0.5f,0.5f,-0.5f),
			CVector(-0.5f,-0.5f,-0.5f),
			CVector(0.5f,-0.5f,-0.5f)
		},{
			0,1,3,2,
			4,5,7,6,
			0,4,6,2,
			1,5,7,3
		}
	);

	CNode camera(NULL);
	CNode square(&squareModel);

	camera.setPosition(0.0f,0.0f,0.0f);
	square.setPosition(0.0f,0.0f,2.0f);

	camera.updateMatrix();
	square.updateMatrix();

	camera.inverseMatrix();

	bool loop = true;
	while(loop) {
		system("cls");
		square.addRotation(0.1f,0.1f,0.0f);
		square.updateMatrix();
		square.render(c,camera.getMatrix());
		c.render();
		Sleep(10);
	}
}