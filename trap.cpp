#include "pch.h"
#include "trap.h"

HRESULT trap::init(POINT point)
{
    _point = point;
    _img = IMAGEMANAGER->findImage("TRAP");

    _ani = new animation;
    _ani->init(_img->getWidth(), _img->getHeight(), 4, 1);
    _ani->setDefPlayFrame(false, false);
    _ani->setFPS(1);

    _rc = RectMakeCenter(point.x, point.y, _img->getWidth(), _img->getHeight());

    return S_OK;
}

void trap::release()
{
}

void trap::update()
{
}

void trap::render()
{
	enemy::render();
}
