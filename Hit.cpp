#include "pch.h"
#include "hit.h"
#include "Sonic.h"

HRESULT hit::init()
{
    _img = IMAGEMANAGER->findImage("HIT");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 1, 2);
    _aniL->setPlayFrame(0, 1, false, false);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 1, 2);
    _aniR->setPlayFrame(1, 0, false, false);
    _aniR->setFPS(1);

    _angle = PI* 2;


    // 아래는 코인임?




    return S_OK;
}

void hit::release()
{
}

void hit::update()
{
    move();

    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 2, _img->getHeight() / 2);
}

void hit::render()
{
    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);

}

void hit::move()
{
    if (_isHit) {
        _x += sinf(_angle) * 7;
        _y += -cosf(_angle) * 7;

        if(_dir == LEFT && _angle < 3.f * PI)_angle += 0.07f;
        if(_dir == RIGHT && _angle > PI)_angle -= 0.07f;
    }
    else if (!_isHit) {
        
        _angle = PI * 2;
        _coin = 0;
        _s->setIdle();
    }
}

void hit::aniChange()
{
}

