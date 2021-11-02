#include "pch.h"
#include "run.h"
#include "Sonic.h"

HRESULT run::init()
{

    _img = IMAGEMANAGER->findImage("RUN");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 4, 2);
    _aniL->setPlayFrame(3, 0, false, true);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 4, 2);
    _aniR->setPlayFrame(4, 7, false, true);
    _aniR->setFPS(1);

    _xSpeed = 0;
    _a = 0.06f;

    return S_OK;
}

void run::release()
{
    gameNode::release();
}

void run::update()
{
    move();
    

    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
    _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 4, _img->getHeight() / 2);
}

void run::render()
{
    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
}

void run::move()
{
    // 점프 상태로 변경
    if (KEYMANAGER->isStayKeyDown(VK_UP)) {
        _aniL->stop();
        _aniR->stop();

        _s->setJump();
    }

    // 키는 한쪽만 눌리게 만들어야지 (다른쪽 안눌렸을 경우 || 눌렸지만 같은 방향인 경우엔 OK
    // 속도 설정
    if (!KEYMANAGER->isStayKeyDown(VK_RIGHT) || _dir == LEFT) {
        if (_xSpeed > 1 && KEYMANAGER->isOnceKeyDown(VK_LEFT)) _xSpeed = 1;

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)){          
             _dir = LEFT;
             _aniL->resume();

             if (_xSpeed < 5) _xSpeed += _a + 0.5f;
             else _xSpeed = 5;
        }
        
    }
    
    if (!KEYMANAGER->isStayKeyDown(VK_LEFT) || _dir == RIGHT) {
        if (_xSpeed > 1 && KEYMANAGER->isOnceKeyDown(VK_RIGHT)) _xSpeed = 1;

        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
            _dir = RIGHT;
            _aniR->resume();

            if (_xSpeed < 5) _xSpeed += _a + 0.5f;
            else _xSpeed = 5;
        }
    }
    
    moveChange();   
}

void run::moveChange()
{

    // 속도 0이면 IDLE
    if (_xSpeed < 0) {
        _aniL->stop();
        _aniR->stop();

        _s->setIdle();
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
 
}

void run::aniChange()
{
    
}

