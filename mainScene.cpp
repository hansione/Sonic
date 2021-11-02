#include "pch.h"
#include "mainScene.h"

//초기화는 여기에다 해라!!!
HRESULT mainScene::init()
{
	// 소닉
	_sonic = new Sonic;
	_sonic->init();

	// 배경화면
	_bg = new camera;
	_bg->init();

	_startImg = IMAGEMANAGER->findImage("시작");
	_startImg->setX(WINSIZEX + _startImg->getWidth()/2);
	_startImg->setY(WINSIZEY / 2 - _startImg->getHeight()/2);
	_isStart = false;
	_timer = 0;

	// 픽셀충돌(바닥)
	_pc = new pixelCol;
	_pc->init();

	// 적 생성
	_em = new enemyManager;
	_em->init();


	// 오브젝트 생성
	_om = new objectManager;
	_om->init();


	// 적 보스 생성
	_boss = new boss;
	_boss->init();

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void mainScene::release()
{

}

//연산처리는 여기다가!
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

		//배경 화면 이동
		_bg->update();
		_pc->setIsBoss(_bg->getIsBoss());

		// 배경 -> 소닉 (누가 움직일 지)
		_sonic->getState()->setIsSonicMoveX(_bg->getIsSonicMoveX());
		_sonic->getState()->setIsSonicMoveY(_bg->getIsSonicMoveY());

		// 점프상태 -> 픽셀충돌 (점프유무)
		_pc->setIsJump(_sonic->getState()->getIsJump());

		// 소닉의 상태변경을 위한 설정자
		_sonic->getState()->setState(_sonic);
		_pc->setState(_sonic);


		// 픽셀충돌 하기 위한 렉트,중심좌표 설정자
		_pc->setRect(_sonic->getState()->getRect());
		_pc->update();

		// 픽셀충돌 배경 움직이기 위한 설정자
		_pc->setBX(_bg->getBX());
		_pc->setBY(_bg->getBY());

		// 픽셀충돌 -> 점프상태 (점프유무)
		if (_sonic->getState()->getYSpeed() < 0)
			_sonic->getState()->setIsJump(_pc->getIsJump());

		// 픽셀충돌에서 계산 중심좌표 값을 다시 소닉에게 넘기기
		_sonic->getState()->setX(_pc->getX());
		_sonic->getState()->setY(_pc->getY());
		_sonic->update();

		// 소닉 -> 배경 (누가 움직일 지)
		_bg->setIsSonicMoveX(_sonic->getState()->getIsSonicMoveX());
		_bg->setIsSonicMoveY(_sonic->getState()->getIsSonicMoveY());

		_bg->setXSpeed(_sonic->getState()->getXSpeed());
		_bg->setYSpeed(_sonic->getState()->getYSpeed());

		_bg->setIsRoll(_sonic->getState()->getIsRoll());


		// 적 픽셀충돌
		for (int i = 0; i < _em->getVEnemy().size(); i++) {

			// 배경 좌표값
			_em->getVEnemy()[i]->setBX(_bg->getBX());
			_em->getVEnemy()[i]->setBY(_bg->getBY());

			// 충돌처리를 위한 소닉의 렉트값
			_em->getVEnemy()[i]->setRect(_sonic->getState()->getRect());

			// Hit 당했을 때 스테이트 변경을 위한
			_em->getVEnemy()[i]->setState(_sonic);
		}


		// 적 생성
		_em->update();


		for (int i = 0; i < _om->getVObject().size(); i++) {
			// 배경 좌표값
			_om->getVObject()[i]->setBX(_bg->getBX());
			_om->getVObject()[i]->setBY(_bg->getBY());

			// 충돌처리를 위한 소닉의 렉트값
			_om->getVObject()[i]->setRect(_sonic->getState()->getRect());

			// Hit 당했을 때 스테이트 변경을 위한
			_om->getVObject()[i]->setState(_sonic);
		}
		// 오브젝트
		_om->update();

		

		// 보스
		_boss->setSonic(_sonic);
		if (_bg->getIsBoss() && _bg->getFadeOut() == 0)
			_boss->update();
	}
}

//여기다 그려줘라!!!
void mainScene::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============

		
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
	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

