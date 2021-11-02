#pragma once
#include "gameNode.h"
#include "animation.h"

#define ACCEL 0.06f
#define GRAVITY 0.08f

class Sonic;

// ����
enum Dir {
	LEFT,
	RIGHT
};

class State : public gameNode
{
protected:
	animation* _aniL, *_aniR;		// ���⺰ �ִϸ��̼�
	image* _img;				// ���º� �̹���
	int _dir;						// ����
	bool _isSonicMoveX, _isSonicMoveY;

	float _xSpeed, _a = ACCEL;	// _x �ӵ�, ���ӵ�
	float _ySpeed, _g = GRAVITY;	// ���� �ӵ�, �߷�

	bool _isRoll, _isJump;
	bool _isHit;

	// ����
	int _coin;

	//�Ҵ��� �̹���
	RECT _rc;
	float _x, _y;

	//�Ҵ� ���¹ޱ� ���� ����
	Sonic* _s; 
public:

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	virtual void move() = 0;
	virtual void aniChange() = 0;

	virtual void setState(Sonic* state) { _s = state; }

	// ����
	virtual int getCoin() { return _coin; };
	virtual void setCoin(int coin) { _coin = coin; }

	// ī�޶� �̵��� ���� ������, ������
	virtual bool getIsSonicMoveX() { return _isSonicMoveX; }
	virtual void setIsSonicMoveX(bool isSonicMoveX) { _isSonicMoveX = isSonicMoveX; }

	virtual bool getIsSonicMoveY() { return _isSonicMoveY; }
	virtual void setIsSonicMoveY(bool isSonicMoveY) { _isSonicMoveY = isSonicMoveY; }

	// ���� �� ���� ������ ���� ������, ������
	virtual bool getIsRoll() { return _isRoll; }
	virtual void setIsRoll(bool isRoll) { _isRoll = isRoll; }

	virtual bool getIsJump() { return _isJump; }
	virtual void setIsJump(bool isJump) { _isJump = isJump; }

	virtual bool getIsHit() { return _isHit; }
	virtual void setIsHit(bool isHit) { _isHit = isHit; }

	virtual float getXSpeed() { return _xSpeed; };
	virtual void setXSpeed(float xSpeed) { _xSpeed = xSpeed; }

	virtual float getYSpeed() { return _ySpeed; };
	virtual void setYSpeed(float ySpeed) { _ySpeed = ySpeed; }

	// �Ҵ��� �̹����� ���� ������, ������
	virtual RECT getRect() { return _rc; };
	virtual void setRect(RECT rc) { _rc = rc; }

	virtual float getX() { return _x; };
	virtual void setX(float x) { _x = x; }

	virtual float getY() { return _y; };
	virtual void setY(float y) { _y = y; }

	virtual int getDir() { return _dir; }
	virtual void setDir(int dir) { _dir = dir; }
};

