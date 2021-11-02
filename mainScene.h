#pragma once
#include "gameNode.h"

#include "pixelCol.h"
#include "camera.h"
#include "Sonic.h"
#include "enemyManager.h"
#include "objectManager.h"

#include "boss.h"

class mainScene : public gameNode
{
private:
	Sonic* _sonic;

	camera* _bg;
	pixelCol* _pc;

	enemyManager* _em;
	objectManager* _om;

	boss* _boss;

	//시작
	bool _isStart;
	image* _startImg;
	int _timer;

public:

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수
};

