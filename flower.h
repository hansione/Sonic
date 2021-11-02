#pragma once
#include "enemy.h"

class flower : public enemy
{
private:
	image* _bulletImg;
	
	// ÃÑ¾Ë ÁßÁ¡
	int _x, _y;




	RECT _rc1;
public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move();
	virtual void bulletFire();
	virtual void collision();
	virtual void draw();
};

