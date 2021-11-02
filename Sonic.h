#pragma once
#include "gameNode.h"

#include "run.h"
#include "idle.h"
#include "jump.h"
#include "duck.h"
#include "roll.h"
#include "hit.h"
#include "win.h"

//UNSAFE ������ ���������� �����ϴ� ����
#pragma warning(disable:4996)

class Sonic : public gameNode
{
private:
	// ���µ�
	State* _state;
	
	run* _run;
	idle* _idle;
	jump* _jump;
	duck* _duck;
	roll* _roll;
	hit* _hit;
	win* _win;

public:
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void setValue(State* state);

	State* getState() { return _state; }

	// ���µ鸶�� �ϳ��� ����
	void setRun() { setValue(_run); }
	void setIdle() { setValue(_idle); }
	void setJump() { setValue(_jump); }
	void setDuck() { setValue(_duck); }
	void setRoll() { setValue(_roll); }
	void setHit() { setValue(_hit); }
	void setWin() { setValue(_win); }



	

};

