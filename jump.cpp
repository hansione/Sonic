#include "pch.h"
#include "jump.h"
#include "Sonic.h"

HRESULT jump::init()
{
    _img = IMAGEMANAGER->findImage("ROLL & JUMP");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 5, 2);
    _aniL->setPlayFrame(4, 0, false, true);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 5, 2);
    _aniR->setPlayFrame(5, 9, false, true);
    _aniR->setFPS(1);

    _xSpeed = 0;
    _ySpeed = 5;
    _isJump = false;

    return S_OK;
}

void jump::release()
{
}

void jump::update()
{
    move();
    aniChange();

    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
    _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
  
    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 5, _img->getHeight() / 2);
    
}

void jump::render()
{
    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
}

void jump::move()
{

    // 점프 구현
    if (_isJump) {     
        if (_dir == LEFT) _aniL->resume();
        if (_dir == RIGHT) _aniR->resume();

        if(_isSonicMoveY) _y -= _ySpeed;
        _ySpeed -= _g;
   
    }
    else if(!_isJump){
        _aniL->stop();
        _aniR->stop();
        _ySpeed = 5;
        _xSpeed = 0;

        _s->setIdle();
    }
   
    
    // 좌우 이동
    if (!KEYMANAGER->isStayKeyDown(VK_RIGHT) || _dir == LEFT) {
        if (_xSpeed > 1 && KEYMANAGER->isOnceKeyDown(VK_LEFT)) _xSpeed = 1;

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
            _dir = LEFT;

            if (_xSpeed < 5) _xSpeed += _a + 0.5f;
            else _xSpeed = 5;
        }

    }

    if (!KEYMANAGER->isStayKeyDown(VK_LEFT) || _dir == RIGHT) {
        if (_xSpeed > 1 && KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _xSpeed = 1;

        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
            _dir = RIGHT;

            if (_xSpeed < 5) _xSpeed += _a + 0.5f;
            else _xSpeed = 5;
        }
    }

    moveChange();


    /*if (!KEYMANAGER->isStayKeyDown(VK_RIGHT) || _dir == LEFT) {
        if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0) {
            _dir = LEFT;

            if (_isSonicMove) {
                _x -= _xSpeed;
            }

            // 카메라 이동조건
            if (_x < 200) {
                _isSonicMove = false;
            }
            else {
                _isSonicMove = true;
            }

        }
    }

    if (!KEYMANAGER->isStayKeyDown(VK_LEFT) || _dir == RIGHT) {
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZEX) {
            _dir = RIGHT;

            if (_isSonicMove) {
                _x += _xSpeed;
            }

            // 카메라 이동조건
            if (_x > 600) {
                _isSonicMove = false;
            }
            else {
                _isSonicMove = true;
            }

        }
    }*/
}

void jump::moveChange()
{

   
    if (_xSpeed <= 0) {
        _xSpeed = 0;
    }

    // 아니면 누가 움직일까?
    if (_isSonicMoveX) {
        if (_dir == LEFT) {
            if (_rc.left > 0) {
                _x -= _xSpeed;
                _xSpeed -= _a;

                if (_x < 200) _isSonicMoveX = false;
                else _isSonicMoveX = true;
            }
            else _xSpeed -= _a;
        }

        if (_dir == RIGHT) {
            if (_rc.right < WINSIZEX) {
                _x += _xSpeed;
                _xSpeed -= _a;

                if (_x > 600) _isSonicMoveX = false;
                else _isSonicMoveX = true;
            }
            else _xSpeed -= _a;
        }
    }
    else {
        _xSpeed -= _a;
        if (_dir == LEFT) {
            if (_x < 200) _isSonicMoveX = false;
            else _isSonicMoveX = true;
        }
        else {
            if (_x > 600) _isSonicMoveX = false;
            else _isSonicMoveX = true;
        }
    }


    if (_y <= WINSIZEY / 2) {
        _isSonicMoveY = false;
    }
    else {
        _isSonicMoveY = true;
    }

}

void jump::aniChange()
{
}

