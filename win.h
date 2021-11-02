#pragma once
#include "State.h"


class win : public State
{
private:
	int _timer;

public:
	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	virtual void move();
	virtual void aniChange();

};

