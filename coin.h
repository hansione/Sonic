#pragma once
#include "object.h"



class coin : public object
{

private:
	bool _isHit;
	int _count;

	float angle;

	float _ySpeed;
	int _die;

public:
	virtual HRESULT init(POINT point);
	virtual void release();
	virtual void update();
	virtual void render();


	void coinMove();

};

