#pragma once
#include "gameNode.h"
#include "animation.h"

#define ACCEL 0.06f
#define GRAVITY 0.08f

class Sonic;

// 방향
enum Dir {
	LEFT,
	RIGHT
};

class State : public gameNode
{
protected:
	animation* _aniL, *_aniR;		// 방향별 애니메이션
	image* _img;				// 상태별 이미지
	int _dir;						// 방향
	bool _isSonicMoveX, _isSonicMoveY;

	float _xSpeed, _a = ACCEL;	// _x 속도, 가속도
	float _ySpeed, _g = GRAVITY;	// 점프 속도, 중력

	bool _isRoll, _isJump;
	bool _isHit;

	// 동전
	int _coin;

	//소닉의 이미지
	RECT _rc;
	float _x, _y;

	//소닉 상태받기 위한 변수
	Sonic* _s; 
public:

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	virtual void move() = 0;
	virtual void aniChange() = 0;

	virtual void setState(Sonic* state) { _s = state; }

	// 동전
	virtual int getCoin() { return _coin; };
	virtual void setCoin(int coin) { _coin = coin; }

	// 카메라 이동을 위한 설정자, 접근자
	virtual bool getIsSonicMoveX() { return _isSonicMoveX; }
	virtual void setIsSonicMoveX(bool isSonicMoveX) { _isSonicMoveX = isSonicMoveX; }

	virtual bool getIsSonicMoveY() { return _isSonicMoveY; }
	virtual void setIsSonicMoveY(bool isSonicMoveY) { _isSonicMoveY = isSonicMoveY; }

	// 공격 및 점프 유무를 위한 설정자, 접근자
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

	// 소닉의 이미지를 위한 설정자, 접근자
	virtual RECT getRect() { return _rc; };
	virtual void setRect(RECT rc) { _rc = rc; }

	virtual float getX() { return _x; };
	virtual void setX(float x) { _x = x; }

	virtual float getY() { return _y; };
	virtual void setY(float y) { _y = y; }

	virtual int getDir() { return _dir; }
	virtual void setDir(int dir) { _dir = dir; }
};

