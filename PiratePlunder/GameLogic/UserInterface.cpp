#include "UserInterface.h"


UserInterface::UserInterface(void)
{
	//load the Verdana12 font
    verdana10 = new Advanced2D::Font();
    if (!verdana10->loadImage("verdana10.tga")) {
        g_engine->message("Error loading verdana10.tga");
		//SOME SORT OF ERROR CODE HERE
        //return false;
    }
    verdana10->setColumns(16);
    verdana10->setCharSize(20,16);

    if (!verdana10->loadWidthData("verdana10.dat")) {
        g_engine->message("Error loading verdana10.dat");
		//SOME SORT OF ERROR CODE HERE
        //return false;
    }
}


UserInterface::~UserInterface(void)
{
}

void UserInterface::DrawUI(void)
{
	/*
	if (GameManager::CurrentState == GameManager::PREGAME)
	{
		DrawPREGAME();
	}
	else if(GameManager::CurrentState == GameManager::INGAME)
	{
		DrawINGAME();
	}
	else if(GameManager::CurrentState == GameManager::ENDGAME)
	{
		DrawENDGAME();
	}
	*/
}
