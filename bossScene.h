#pragma once
#include "gameNode.h"
#include "Sonic.h"

class bossScene : public gameNode
{
private:
	Sonic* _sonic;
	image* _bg;



public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

