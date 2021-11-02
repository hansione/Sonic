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
	
	// �Ѿ� ����
	float _x, _y;
	float _angle;
	
	// ���� �Ҵ��� �Ÿ�
	int d;

	//�Ѿ� �̵�
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

