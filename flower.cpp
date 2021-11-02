#include "pch.h"
#include "flower.h"

HRESULT flower::init(POINT point)
{
    enemy::init(point);

    // 아무튼 꽃임
    _point = point;
    _img = IMAGEMANAGER->findImage("FLOWER");

    _ani = new animation;
    _ani->init(_img->getWidth(), _img->getHeight(), 5, 1);
    _ani->setPlayFrame(0, 3);
    _ani->setFPS(1);

    _rc = RectMakeCenter(point.x, point.y, _img->getWidth() / 5, _img->getHeight());

    // 아무튼 총알임
    _bulletImg = IMAGEMANAGER->findImage("FLOWER_BULLET");
    _bullet = RectMakeCenter(point.x, point.y, _bulletImg->getWidth(), _bulletImg->getHeight());

    _timer = 0;
    _isFire = false;

    return S_OK;
}

void flower::release()
{
}

void flower::update()
{
    enemy::update();
    
    move();
    bulletFire();
    collision();

    // 장애물
    _rc1 = RectMakeCenter(4020 - _bx, 340 + (WINSIZEY - _by), 100, 100);
}

void flower::render()
{
    /*char str[128];
    sprintf_s(str, "r : %d, g : %d, b : %d", r, g, b);
    
    //sprintf_s(str, "_bx : %d, _by : %d", _bx, _by);
    ///sprintf_s(str, "_x : %d, _y : %d", _x, _y);
    //sprintf_s(str, "_point.x : %d, _point.y : %d", _point.x - _bx, _point.y);
    TextOut(getMemDC(), 0, 220, str, strlen(str));*/
    
    draw();
}

void flower::move()
{
    //포인트는 상수여야 해(절대좌표)

    _rc = RectMakeCenter(_point.x - _bx, _point.y + (WINSIZEY - _by), _img->getWidth() / 5, _img->getHeight());
}

void flower::bulletFire()
{
    if (_y > (_rc.bottom + _rc.top) / 2) _isFire = false;
    if (_timer > 100) _ani->resume();
  
    if (_ani->isPlay()) {
        _ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
        if (!_ani->isPlay()) {
            _isFire = true;
            _timer = 0;

            _ani->stop();
        }
    }

    if (_isFire){       
        _y -= _YSpeed;
        _YSpeed -= _g;
    }
    else {
        _timer++;
        _x = _point.x;
        _y = _point.y;
        _YSpeed = 5;
    }

    _bullet = RectMakeCenter(_x - _bx, _y + (WINSIZEY - _by), _bulletImg->getWidth(), _bulletImg->getHeight());
}

void flower::collision()
{
    RECT temp;
    if (IntersectRect(&temp, &_bullet, &_sonicRc) && !_isRemove) 
    {
        _s->getState()->setIsHit(true);
        _s->setHit();
    }

    if (IntersectRect(&temp, &_rc, &_sonicRc) && !_isRemove
        && (_s->getState()->getIsJump() || _s->getState()->getIsRoll()))
    {
        _isRemove = true;
    }


    // 점프용 렉트충돌
    if (IntersectRect(&temp, &_rc1, &_sonicRc) && _s->getState()->getIsRoll())
    {
        _s->getState()->setIsJump(true);
        _s->setJump();
    }
}

void flower::draw() {
    
    if (_isFire) {
        _bulletImg->render(getMemDC(), _bullet.left, _bullet.top);
    }

    _img->aniRender(getMemDC(), _rc.left, _rc.top, _ani);


    /*char str[128];
    sprintf_s(str, "play : %d", _ani->isPlay());
    TextOut(getMemDC(), 0, 180, str, strlen(str));
    

    char str1[128];
    sprintf_s(str1, "_isFire : %d", _isFire);
    TextOut(getMemDC(), 0, 200, str1, strlen(str1));*/

}

