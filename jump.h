#pragma once
#include "State.h"

class jump : public State
{
public:
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	virtual void move();
	void moveChange();
	virtual void aniChange();
};

