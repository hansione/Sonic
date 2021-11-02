#pragma once
#include "gameNode.h"
#include "Sonic.h"


class pixelCol : public gameNode
{
private:
	image* _ground, *_bossGround;	//��� �̹���
	int _bx, _by;

	RECT _rc;			//��Ʈ
	float  _x, _y;		//������ǥ

	int _probeY;		//Y�� Ž��

	int r, g, b;

	bool _isJump;

	int a;

	Sonic* _s;
	bool _isBoss;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void Boss();

	void setRect(RECT rc) { _rc = rc; }

	int getX() { return _x; }
	int getY() { return _y; }

	void setBX(int bx) { _bx = bx; }
	void setBY(int by) { _by = by; }

	image* getImage() { return _ground; }

	bool getIsJump() { return _isJump; }
	void setIsJump(bool isJump) { _isJump = isJump; }

	void setState(Sonic* state) { _s = state; }

	void setIsBoss(bool isBoss) { _isBoss = isBoss; }

};

