#include "pch.h"
#include "mainScene.h"

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT mainScene::init()
{
	// �Ҵ�
	_sonic = new Sonic;
	_sonic->init();

	// ���ȭ��
	_bg = new camera;
	_bg->init();

	_startImg = IMAGEMANAGER->findImage("����");
	_startImg->setX(WINSIZEX + _startImg->getWidth()/2);
	_startImg->setY(WINSIZEY / 2 - _startImg->getHeight()/2);
	_isStart = false;
	_timer = 0;

	// �ȼ��浹(�ٴ�)
	_pc = new pixelCol;
	_pc->init();

	// �� ����
	_em = new enemyManager;
	_em->init();


	// ������Ʈ ����
	_om = new objectManager;
	_om->init();


	// �� ���� ����
	_boss = new boss;
	_boss->init();

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void mainScene::release()
{

}

//����ó���� ����ٰ�!
void mainScene::update()
{
	if (!_isStart) {
		if(_startImg->getX() + _startImg->getWidth()/2 > WINSIZEX / 2) _startImg->setX(_startImg->getX() - 20);
		else {
			_timer++;
			if (_timer > 50) {
				_startImg->setX(_startImg->getX() - 20);
			}
		}

		if (_startImg->getX() + _startImg->getWidth() < 0) _isStart = true;

	}
	else {

		//��� ȭ�� �̵�
		_bg->update();
		_pc->setIsBoss(_bg->getIsBoss());

		// ��� -> �Ҵ� (���� ������ ��)
		_sonic->getState()->setIsSonicMoveX(_bg->getIsSonicMoveX());
		_sonic->getState()->setIsSonicMoveY(_bg->getIsSonicMoveY());

		// �������� -> �ȼ��浹 (��������)
		_pc->setIsJump(_sonic->getState()->getIsJump());

		// �Ҵ��� ���º����� ���� ������
		_sonic->getState()->setState(_sonic);
		_pc->setState(_sonic);


		// �ȼ��浹 �ϱ� ���� ��Ʈ,�߽���ǥ ������
		_pc->setRect(_sonic->getState()->getRect());
		_pc->update();

		// �ȼ��浹 ��� �����̱� ���� ������
		_pc->setBX(_bg->getBX());
		_pc->setBY(_bg->getBY());

		// �ȼ��浹 -> �������� (��������)
		if (_sonic->getState()->getYSpeed() < 0)
			_sonic->getState()->setIsJump(_pc->getIsJump());

		// �ȼ��浹���� ��� �߽���ǥ ���� �ٽ� �Ҵп��� �ѱ��
		_sonic->getState()->setX(_pc->getX());
		_sonic->getState()->setY(_pc->getY());
		_sonic->update();

		// �Ҵ� -> ��� (���� ������ ��)
		_bg->setIsSonicMoveX(_sonic->getState()->getIsSonicMoveX());
		_bg->setIsSonicMoveY(_sonic->getState()->getIsSonicMoveY());

		_bg->setXSpeed(_sonic->getState()->getXSpeed());
		_bg->setYSpeed(_sonic->getState()->getYSpeed());

		_bg->setIsRoll(_sonic->getState()->getIsRoll());


		// �� �ȼ��浹
		for (int i = 0; i < _em->getVEnemy().size(); i++) {

			// ��� ��ǥ��
			_em->getVEnemy()[i]->setBX(_bg->getBX());
			_em->getVEnemy()[i]->setBY(_bg->getBY());

			// �浹ó���� ���� �Ҵ��� ��Ʈ��
			_em->getVEnemy()[i]->setRect(_sonic->getState()->getRect());

			// Hit ������ �� ������Ʈ ������ ����
			_em->getVEnemy()[i]->setState(_sonic);
		}


		// �� ����
		_em->update();


		for (int i = 0; i < _om->getVObject().size(); i++) {
			// ��� ��ǥ��
			_om->getVObject()[i]->setBX(_bg->getBX());
			_om->getVObject()[i]->setBY(_bg->getBY());

			// �浹ó���� ���� �Ҵ��� ��Ʈ��
			_om->getVObject()[i]->setRect(_sonic->getState()->getRect());

			// Hit ������ �� ������Ʈ ������ ����
			_om->getVObject()[i]->setState(_sonic);
		}
		// ������Ʈ
		_om->update();

		

		// ����
		_boss->setSonic(_sonic);
		if (_bg->getIsBoss() && _bg->getFadeOut() == 0)
			_boss->update();
	}
}

//����� �׷����!!!
void mainScene::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============

		
		_bg->render();
		_startImg->render(getMemDC(), _startImg->getX(), _startImg->getY());

		_pc->render();
		_em->render();
		_om->render();

		if (_bg->getIsBoss() && _bg->getFadeOut() == 0)
			_boss->render();

		_sonic->render();

	/*char str[128];
	sprintf_s(str, "isHit : %d", _sonic->getState()->getIsHit());
	TextOut(getMemDC(), 0, 220, str, strlen(str));*/
	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

