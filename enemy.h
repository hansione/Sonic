#pragma once
#include "gameNode.h"
#include "animation.h"
#include "pixelCol.h"
#include "Sonic.h"

#define EGRAVITY 0.07f

class enemy : public gameNode
{
protected:
	image* _img;
	animation* _ani;

	RECT _rc;
	POINT _point;

	RECT _bullet;
	float _YSpeed = 5, _g = EGRAVITY;

	int _timer;
	bool _isFire;			// 총알 발사했냐?
	bool _isRemove;			// 소닉이 적을 제거했냐?

	//픽셀 충돌
	//image* _ground;
	int _bx, _by;

	// 확인용 삭제 요망
	int r, g, b;

	// 충돌을 위한 소닉 렉트값
	RECT _sonicRc;
	Sonic* _s;

public:
	virtual HRESULT init();
	virtual HRESULT init(POINT point) = 0;

	virtual void release();
	virtual void update();
	virtual void render();

	virtual void bulletFire() {};
	virtual void move() {};
	virtual void draw();
	virtual void pixelCollision();
	virtual void Collision() {};


	// 제거 확인
	virtual bool getIsRemove() { return _isRemove; }
	virtual void setIsRemove(bool isRemove) { _isRemove = isRemove; }

	virtual void setState(Sonic* state) { _s = state; }

	// 픽셀 충돌을 위한 설정자

	virtual int getBX() { return _bx; }
	virtual void setBX(int bx) { _bx = bx; }

	virtual int getBY() { return _by; }
	void setBY(int by) { _by = by; }

	virtual RECT getRect() { return _sonicRc; };
	virtual void setRect(RECT sonicRc) { _sonicRc = sonicRc; }

	//image* getGround() { return _ground; }
	//void setGround(image* ground) { _ground = ground; }

};

