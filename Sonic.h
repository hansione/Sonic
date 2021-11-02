#pragma once
#include "gameNode.h"

#include "run.h"
#include "idle.h"
#include "jump.h"
#include "duck.h"
#include "roll.h"
#include "hit.h"
#include "win.h"

//UNSAFE 오류좀 띄우지말라고 선언하는 것임
#pragma warning(disable:4996)

class Sonic : public gameNode
{
private:
	// 상태들
	State* _state;
	
	run* _run;
	idle* _idle;
	jump* _jump;
	duck* _duck;
	roll* _roll;
	hit* _hit;
	win* _win;

public:
	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void setValue(State* state);

	State* getState() { return _state; }

	// 상태들마다 하나씩 쓰기
	void setRun() { setValue(_run); }
	void setIdle() { setValue(_idle); }
	void setJump() { setValue(_jump); }
	void setDuck() { setValue(_duck); }
	void setRoll() { setValue(_roll); }
	void setHit() { setValue(_hit); }
	void setWin() { setValue(_win); }



	

};

