#pragma once
#include "gameNode.h"
#include <vector>

#include "trap.h"
#include "flower.h"
#include "crab.h"


class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:
	vEnemy _vEnemy;
	viEnemy _viEnemy;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setFlower(POINT point);
	void setCrab(POINT point);
	void setTrap(POINT point);

	vector<enemy*> getVEnemy() { return _vEnemy; }
	
	vector<enemy*>::iterator getVIEnemy() { return _viEnemy; }

};

