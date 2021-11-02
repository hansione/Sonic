#pragma once
#include "gameNode.h"
#include "animation.h"

class startScene : public gameNode
{
private:
	image* _bg, *_sonic;
	animation* _ani;

public:

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�
};

