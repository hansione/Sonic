#pragma once
#include "State.h"

class duck : public State
{
private:

public:
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	virtual void move();
	virtual void aniChange();
};
