/*
  Name: Pirate Plunder
  Date: 2014/02/23
  Team members: Jefferson Fraser, Jean-Guy Spencer, Pat Rune
*/
#include "..\Engine\Advanced2D.h"
#include "GameLogic\GameEntity.h"
#include "GameLogic\GameManager.h"
#include "GameLogic\GridUtilities.h"

using namespace Advanced2D;

#define SCREENW 256
#define SCREENH 320
#define GAMEAREA_H 256

Sprite *panel;
Character *player;
Character *enemy;

//Font *system12;
Font *nonprop;
Font *verdana10;

const float MOVE_SPEED = 0.1f;
DWORD lastFrameTime = 0;
DWORD deltaTime = 0;

bool game_preload() 
{
    g_engine->setAppTitle("Pirate Plunder");
    g_engine->setFullscreen(false);
    g_engine->setScreenWidth(SCREENW);
    g_engine->setScreenHeight(SCREENH);
    g_engine->setColorDepth(32);
    return 1;
}

void LoadCharacters()
{
	player = new Character(PLAYER, Position(0,0,1), "ppsprites.png", 96, 192, 3, 12);
	enemy = new Character(ENEMY, Position(6,6,2), "ppsprites.png", 192, 192, 6, 24);
}

bool game_init(HWND) 
{
	//load the characters
	LoadCharacters();
	 //load the panel
    panel = new Sprite();
    panel->loadImage("panel.tga");
    float scale = SCREENW / 640.0f;
    panel->setScale(scale);
    panel->setColor(D3DCOLOR_XRGB(100,100,255));
	panel->setPosition(0,GAMEAREA_H+1);
	//load the Verdana12 font
    verdana10 = new Font();
    if (!verdana10->loadImage("verdana10.tga")) {
        g_engine->message("Error loading verdana10.tga");
        return false;
    }
    verdana10->setColumns(16);
    verdana10->setCharSize(20,16);

    if (!verdana10->loadWidthData("verdana10.dat")) {
        g_engine->message("Error loading verdana10.dat");
        return false;
    }

    return true;
}

void game_update()
{
	if(lastFrameTime == 0)
		lastFrameTime = timeGetTime();
	
	deltaTime = timeGetTime() - lastFrameTime;
	lastFrameTime = timeGetTime();
    
}

void game_keyPress(int key)
{

}

void game_keyRelease(int key)
{
    if (key == DIK_ESCAPE) 
		g_engine->Close();
}

void game_mouseButton(int button)
{

}

void game_mouseMotion(int x,int y)
{
}

void game_mouseMove(int x,int y)
{

}

void game_mouseWheel(int wheel)
{
}


void game_render3d()
{
    g_engine->ClearScene(D3DCOLOR_XRGB(0,0,0));
}

void game_render2d()
{
	panel->draw();
	verdana10->Print(10,256+10, "PIRATE PLUNDER", D3DCOLOR_XRGB(255,255,255));
	verdana10->Print(10,256+22, "DO NOT LET THE", D3DCOLOR_XRGB(255,255,255));
	verdana10->Print(10,256+34, "CAPTAIN CATCH YOU", D3DCOLOR_XRGB(255,255,255));
}


void game_end() 
{
	delete nonprop;
	delete verdana10;
	delete panel;
	delete player;
	delete enemy;
}