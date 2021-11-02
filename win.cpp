#include "pch.h"
#include "win.h"

HRESULT win::init()
{
    _img = IMAGEMANAGER->findImage("WIN");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 2, 1);
    _aniL->setDefPlayFrame(false, false);
    _aniL->setFPS(1);

    return S_OK;
}

void win::release()
{
}

void win::update()
{
    _timer++;

    if (_timer > 100) _aniL->resume();

    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);



    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 2, _img->getHeight() / 2);
}

void win::render()
{

    _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);

}

void win::move()
{

}

void win::aniChange()
{

}
