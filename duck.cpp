#include "pch.h"
#include "duck.h"
#include "Sonic.h"

HRESULT duck::init()
{
    _img = IMAGEMANAGER->findImage("DUCK");
    
    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 2, 2);
    _aniL->setPlayFrame(1, 0, false, false);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 2, 2);
    _aniR->setPlayFrame(2, 3, false, false);
    _aniR->setFPS(1);

    return S_OK;
}

void duck::release()
{
}

void duck::update()
{
    move();
    
    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
    _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);



    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 2, _img->getHeight() / 2);
}

void duck::render()
{
    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
}

void duck::move()
{

    

    if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
        _aniL->stop();
        _aniR->stop();

        _s->setIdle();
    }
    else if(KEYMANAGER->isStayKeyDown(VK_DOWN)){
        if (_dir == LEFT)  _aniL->resume();
        if (_dir == RIGHT) _aniR->resume();  
    }

    if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
        _s->setRoll();
    }
    
}

void duck::aniChange()
{
}
