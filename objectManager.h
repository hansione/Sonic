#pragma once
#include "gameNode.h"
#include "coin.h"
#include "safezone.h"

#include <vector>

class objectManager : public gameNode
{
private:
	typedef vector<object*> vObject;
	typedef vector<object*>::iterator viObject;
private:
	vObject _vObject;
	viObject _viObject;


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setCoin(POINT p);
	void setSafezone(POINT p);

	vector<object*> getVObject() { return _vObject; }
	vector<object*>::iterator getVIObject() { return _viObject; }

};

