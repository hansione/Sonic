#pragma once
#include "gameNode.h"
#include "animation.h"
#include "Sonic.h"

class object : public gameNode
{
protected:
	RECT _rc;
	float _x, _y;

	image* _img;
	animation* _ani;

	bool _isFire;

	int _bx, _by;

	// �浹�� ���� �Ҵ� ��Ʈ��
	RECT _sonicRc;
	Sonic* _s;

public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();
	
	// ���� �� ��

	virtual int getBX() { return _bx; }
	virtual void setBX(int bx) { _bx = bx; }

	virtual int getBY() { return _by; }
	void setBY(int by) { _by = by; }

	virtual RECT getRect() { return _sonicRc; };
	virtual void setRect(RECT sonicRc) { _sonicRc = sonicRc; }

	virtual void setState(Sonic* state) { _s = state; }

};

