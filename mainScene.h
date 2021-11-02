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

	//����
	bool _isStart;
	image* _startImg;
	int _timer;

public:

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�
};

