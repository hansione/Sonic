#pragma once
#include "gameNode.h"

#include "mainScene.h"
#include "startScene.h"

class playGround : public gameNode
{
private:
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	
	

};

