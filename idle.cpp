#include "pch.h"
#include "idle.h"
#include "Sonic.h"

HRESULT idle::init()
{

    _img = IMAGEMANAGER->findImage("IDLE");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 6, 2);
    _aniL->setPlayFrame(5, 0, false, false);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 6, 2);
    _aniR->setPlayFrame(6, 11, false, false);
    _aniR->setFPS(1);

    _timer = 0;

    //처음 시작이 IDLE이니까 여기에 초기화
    _x = 50;
    _y = WINSIZEY/2;
    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 6, _img->getHeight()/2);

    _isSonicMoveY = true;

    return S_OK;
}

void idle::release()
{
    gameNode::release();
}

void idle::update()
{
    //gameNode::update();
    
    move();
    aniChange();
    
    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 0.5f);
    _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 0.5f);


    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 6, _img->getHeight() / 2);
}

void idle::render()
{

    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
 
}

void idle::move()
{
    // 시작할때 내려가셈

    if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
        _dir = LEFT;
        _aniL->stop();

        if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
            _isJump = true;
            _s->setJump();
        }
        else _s->setRun();
    }
    else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
        _dir = RIGHT;
        _aniR->stop();

        if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
            _isJump = true;
            _s->setJump();
        }
        else _s->setRun();
    }
    else if (KEYMANAGER->isOnceKeyDown(VK_DOWN)) {
        _aniL->stop();
        _aniR->stop();

        _s->setDuck();
    }
    else if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
        _aniL->stop();
        _aniR->stop();

        _isJump = true;
        _s->setJump();
    }
    
}

void idle::aniChange()
{
    _timer++;

    if (_timer >= 200) {

        if (_dir == LEFT) {
            _aniL->resume();
        }
        if (_dir == RIGHT) {
            _aniR->resume();
        }

        _timer = 0;
    }

    // 처음부터 시작
    if (_timer == 0) {
        _aniL->start();
        _aniR->start();
    }
   
}
