#include "pch.h"
#include "boss.h"

HRESULT boss::init()
{
	_boss = IMAGEMANAGER->findImage("����");
	_ring = IMAGEMANAGER->findImage("��");
	_ball = IMAGEMANAGER->findImage("��");

	// �¿�θ� ������
	_x = WINSIZEX + 100;
	_y = 100;
	_bossRc = RectMakeCenter(_x, _y, _boss->getWidth(), _boss->getHeight());

	// ���� �ʿ���
	for (int i = 0; i < 3; i++) {
		_angle = PI;
		

		if (i == 0) {
			_ringRc[i].speed = 30;
			_ringRc[i].x = _x + sinf(_angle) * _ringRc[i].speed;
			_ringRc[i].y = _bossRc.bottom + _ring->getHeight() / 2;
		}
		else {
			_ringRc[i].speed = 10;
			_ringRc[i].x = _ringRc[i-1].x;
			_ringRc[i].y = _ringRc[i-1].rc.bottom + _ring->getHeight() / 2;
		}

		_ringRc[i].rc = RectMakeCenter(_ringRc[i].x, _ringRc[i].y, _ring->getWidth(), _ring->getHeight());
	}

	// ���� �ʿ���
	_ballRc.speed = 15;
	_ballRc.x = _ringRc[2].x + sinf(_angle) * _ballRc.speed; ;
	_ballRc.y = _ringRc[2].rc.bottom + _ball->getHeight()/2;

	_ballRc.rc = RectMakeCenter(_ballRc.x, _ballRc.y, _ball->getWidth(), _ball->getHeight());

	_isBossDir = _isBallDir = _isDie =  false;
	_count = 0;

	speed = 5;

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	if (_isStart) {

		move();
		collision();

		if (_isDie) dieMove();
	}
	else {
		_x -= 5;

		if (_x < WINSIZEX / 2) _isStart = true;
	}


	_bossRc = RectMakeCenter(_x, _y, _boss->getWidth(), _boss->getHeight());

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			_ringRc[i].x = _x + sinf(_angle) * _ringRc[i].speed;
			_ringRc[i].y = _bossRc.bottom + _ring->getHeight() / 2;
		}
		else {
			_ringRc[i].x = _ringRc[i - 1].x + sinf(_angle) * _ringRc[i].speed;
			_ringRc[i].y = _ringRc[i - 1].rc.bottom + _ring->getHeight() / 2;
		}

		_ringRc[i].rc = RectMakeCenter(_ringRc[i].x, _ringRc[i].y, _ring->getWidth(), _ring->getHeight());
	}

	// ���� �ʿ���
	_ballRc.x = _ringRc[2].x + sinf(_angle) * _ballRc.speed;;
	_ballRc.y = _ringRc[2].rc.bottom + _ball->getHeight() / 2;
	_ballRc.rc = RectMakeCenter(_ballRc.x, _ballRc.y, _ball->getWidth(), _ball->getHeight());
}


void boss::render()
{
	_boss->render(getMemDC(), _bossRc.left, _bossRc.top);

	for (int i = 0; i < 3; i++) {
		_ring->render(getMemDC(), _ringRc[i].rc.left, _ringRc[i].rc.top);
	}
	
	_ball->render(getMemDC(), _ballRc.rc.left, _ballRc.rc.top);
}

void boss::move()
{

	if (!_isDie) {
		// ���� ����
		if (_angle > PI * 5 / 4) _isBallDir = true;
		if (_angle < PI * 3 / 4) _isBallDir = false;

		if (_isBallDir) _angle += 0.04f;
		else _angle -= 0.04f;



		// ���� ������
		if (_x < 150) _isBossDir = true;
		if (_x > 650) _isBossDir = false;

		if (_isBossDir) _x += 5;
		else _x -= 5;
		
	}
	else {
		_y -= speed;
		speed -= 0.2f;
	}

	
	

	
	
}

void boss::dieMove()
{
	_s->setWin();
}

void boss::collision()
{
	RECT temp;
	RECT rc = _s->getState()->getRect();
	
	//����
	if (IntersectRect(&temp, &rc, &_bossRc))
	{
		// �� �ѹ��� ���� ��
		if (!_isHit) {
			_count++;
			_isHit = true;


			//�ٷ� ���������� ���� (Ÿ���� ������ ����)
			_s->getState()->setYSpeed(0);
		}
	}
	else {
		_isHit = false;
	}



	// ��Ʈ
	if (IntersectRect(&temp, &rc, &_ballRc.rc) && !_isDie) {
		_s->setHit();
	}


	if (_count >= 3) _isDie = true;
}
