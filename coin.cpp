#include "pch.h"
#include "coin.h"

HRESULT coin::init(POINT point)
{
    _img = IMAGEMANAGER->findImage("동전");

    _x = point.x;
    _y = point.y;

    

    _ani = new animation;
    _ani->init(_img->getWidth(), _img->getHeight(), 9, 1);
    _ani->setDefPlayFrame(false, true);
    _ani->setFPS(1);


    _rc = RectMakeCenter(_x, _y, _img->getWidth()/9, _img->getHeight());

    _isFire = true;
    _count = 0;


    return S_OK;
}

void coin::release()
{
}

void coin::update()
{
    _ani->resume();


    RECT temp;
    if (IntersectRect(&temp, &_rc, &_sonicRc) && _isFire) {
        _isFire = false;
        _s->getState()->setCoin(_s->getState()->getCoin() + 1);
    }

    if (_s->getState()->getIsHit()) {
        _isHit = true;
    }
    else if(!_s->getState()->getIsHit() && !_isFire) {
        _x = _s->getState()->getX() + _bx;
        _y = _s->getState()->getY() + (WINSIZEY - _by);
        _ySpeed = -cosf(angle) * 3;
    }


    if (_isHit) {
        _count++;
        _isFire = true;
        coinMove();
       
        if (_count > 100) {          
            _isHit = false;
            _isFire = false;
        }
    }
    else {
        angle = RND->getFromFloatTo(-PI / 3, PI / 3);
        _count = 0;
    }

    _rc = RectMakeCenter(_x - _bx, _y + (WINSIZEY - _by), _img->getWidth() / 9, _img->getHeight());
    _ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}

void coin::render()
{
    if(_isFire)
        _img->aniRender(getMemDC(), _rc.left, _rc.top, _ani);
}

void coin::coinMove()
{
    //float angle = -PI / 4;
  
    if (_die == 0) {
        _x += sinf(angle) * 3;
        _y += _ySpeed;

        _ySpeed += 0.05f;
    }
    else {
        // _s->setDie(); 죽는 모션 구현 예정
    }

}
