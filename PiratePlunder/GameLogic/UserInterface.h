#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#pragma once
#include <string>
#include "..\..\Engine\Advanced2D.h"
//#include "GameManager.h"

class UserInterface
{
public:
	UserInterface();
	~UserInterface(void);

	//void InitUI();
	
	//Draws UI Based on Gamstate
	void DrawUI();
private:
	Advanced2D::Font *verdana10;
	std::string GAMETEXT[3];
	void DrawPREGAME(){return;}
	void DrawINGAME(){return;} 
	void DrawENDGAME(){return;}
};

#endif