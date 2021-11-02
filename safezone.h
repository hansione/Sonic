#pragma once
#include "object.h"
class safezone : public object
{
	image* _sc;


	RECT _scr;
	float _scx, _scy, _angle;

	bool _isTurn;

public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();

	void safe();



};

