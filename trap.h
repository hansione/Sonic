#pragma once
#include "enemy.h"

class trap : public enemy
{
private:



public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();
};

