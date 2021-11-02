#pragma once
#include "enemy.h"

#define DISTANCE 200

/*enum enemyState {
	LEFT,
	RIGHT,

	IDLE,
	ATK
};*/

enum enemyState {
	LEFT_IDLE,
	RIGHT_IDLE,

	LEFT_ATK,
	RIGHT_ATK
};


class crab : public enemy
{
private:
	animation* _aniL, * _aniR;
	animation* _aniL_Atk, * _aniR_Atk;
	int _state;

	image* _bulletImg;
	animation* _aniBullet;
	
	// 총알 중점
	float _x, _y;
	float _angle;
	
	// 적과 소닉의 거리
	int d;

	//총알 이동
	bool _re;
	float _speed, _a;
	
	int _timer;

public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void bulletFire();
	virtual void draw();
	virtual void collision();

};

