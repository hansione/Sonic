#include "pch.h"
#include "safezone.h"

HRESULT safezone::init(POINT point)
{
    // 폴대
    _img = IMAGEMANAGER->findImage("폴대");
    
    _x = point.x;
    _y = point.y;

    _rc = RectMakeCenter(_x, _y, _img->getWidth(), _img->getHeight());

    // 원
    _sc = IMAGEMANAGER->findImage("원");

    _scx = (_rc.right + _rc.left) / 2 ;
    _scy = _rc.top + 1;

    _sc->setFrameX(1);
    _scr = RectMakeCenter(_scx, _scy, _sc->getFrameWidth(), _sc->getFrameHeight());
    
    _isFire = _isTurn = false;


    return S_OK;
}

void safezone::release()
{
   
}

void safezone::update()
{
    RECT temp;
    if (IntersectRect(&temp, &_rc, &_sonicRc) ||
        IntersectRect(&temp, &_scr, &_sonicRc)) {
        _isFire = true;

       
    }


    if (_isFire) {
        char str[128];
        vector<string> vStr;

        vStr.push_back(itoa(_x - _bx, str, 10));
        vStr.push_back(itoa(_y + (WINSIZEY - _by), str, 10));

        TXTDATA->txtSave("아.txt", vStr);
    }



    if (_isFire && _scy > _rc.top) {
        _isTurn = true;
    }

    if (KEYMANAGER->isOnceKeyDown(VK_F2))
    {

        vector<string> vStr;
        vStr = TXTDATA->txtLoad("아.txt");

        _s->getState()->setX(atoi(vStr[0].c_str()));
        _s->getState()->setX(atoi(vStr[0].c_str()));
    }



    safe();

    _rc = RectMakeCenter(_x - _bx, _y + (WINSIZEY - _by), _img->getWidth(), _img->getHeight());
    _scr = RectMakeCenter(_scx - _bx, _scy + (WINSIZEY - _by), _sc->getFrameWidth(), _sc->getFrameHeight());
}

void safezone::render()
{
    _img->render(getMemDC(), _rc.left, _rc.top);
    _sc->frameRender(getMemDC(), _scr.left, _scr.top);

}


void safezone::safe()
{
    if (_isFire && _isTurn) {
        _sc->setFrameX(0);

        _scx += +sinf(_angle) * 0.5f;
        _scy += -cosf(_angle) * 0.5f;

        _angle += 0.1f;

        if (_angle > PI * 2) _isTurn = false;

    }

}
