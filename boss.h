#pragma once
#include "gameNode.h"
#include "Sonic.h"


struct tagBall {
	RECT rc;
	float x, y;
	float speed;
};



class boss : public gameNode
{
	bool _isStart;
	image* _boss, * _ring, * _ball;

	int _x, _y;

	RECT _bossRc;
	int _count;

	bool _isBossDir , _isBallDir;
	bool _isDie , _isHit;
	float speed;

	float _angle;

	tagBall _ringRc[3];
	tagBall _ballRc;

	Sonic* _s;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void dieMove();
	void collision();


	void setSonic(Sonic* s) { _s = s; }

};

