#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "gameMap.h"
#include "NPC.h"


namespace game_framework {

	//NPC class
	NPC::NPC(gameMap* pointer,int x, int y) : currentMap(pointer), x(x), y(y) {}
	NPC::~NPC() {}
	void NPC::LoadBitmap() {}
	
	void NPC::OnMove() {}

	void NPC::OnShow() {}

	void NPC::SetHeroXY(int x1, int x2, int y1, int y2)
	{
		hero["x1"] = x1;
		hero["x2"] = x2;
		hero["y1"] = y1;
		hero["y2"] = y2;
	}


	//NPC_OldMan class
	NPC_oldMan::NPC_oldMan(gameMap* pointer, int x, int y) : NPC(pointer, x, y) {}

	int NPC_oldMan::GetX1() 
	{ 
		return x; 
	}

	int NPC_oldMan::GetY1() 
	{ 
		return y; 
	}

	int NPC_oldMan::GetX2() 
	{ 
		return x + animation.Width(); 
	}

	int NPC_oldMan::GetY2() 
	{ 
		return y + animation.Height(); 
	}

	void NPC_oldMan::LoadBitmap()
	{
		animation.AddBitmap(IDB_OLD_MAN_1, RGB(255, 0, 0));
		animation.AddBitmap(IDB_OLD_MAN_2, RGB(255, 0, 0));
		animation.AddBitmap(IDB_OLD_MAN_3, RGB(255, 0, 0));
		InteractionBar.AddBitmap(IDB_TALK_BAR_1, RGB(255, 255, 255));
		InteractionBar.AddBitmap(IDB_TALK_BAR_2, RGB(255, 255, 255));
		InteractionBar.AddBitmap(IDB_TALK_BAR_3, RGB(255, 255, 255));
		InteractionBar.AddBitmap(IDB_TALK_BAR_4, RGB(255, 255, 255));
	}
	void NPC_oldMan::OnMove()
	{
		animation.OnMove();
		InteractionBar.OnMove();
	}

	void NPC_oldMan::OnShow()
	{
		animation.SetTopLeft(currentMap->ScreenX(x), currentMap->ScreenY(y));
		animation.OnShow();
		if (isAroundHero())
		{
			InteractionBar.SetTopLeft(currentMap->ScreenX(x + 80), currentMap->ScreenY(y));
			InteractionBar.OnShow();
		}
	}

	bool NPC_oldMan::isAroundHero()
	{
		if ((GetX2() >= hero["x1"]) && (hero["x2"] >= GetX1()) && (GetY2() >= hero["y1"]) && (hero["y2"] >= GetY1()))
			return true;
		else
			return false;
	}
}