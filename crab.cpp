#include "pch.h"
#include "crab.h"

HRESULT crab::init(POINT point)
{
    enemy::init(point);

    _point = point;
    _img = IMAGEMANAGER->findImage("CRAB");

    // IDLE 상태
    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 7, 2);
    _aniL->setPlayFrame(13, 9);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 7, 2);
    _aniR->setPlayFrame(0, 4);
    _aniR->setFPS(1);

    // ATK 상태
    _aniL_Atk = new animation;
    _aniL_Atk->init(_img->getWidth(), _img->getHeight(), 7, 2);
    _aniL_Atk->setPlayFrame(8, 7);
    _aniL_Atk->setFPS(1);

    _aniR_Atk = new animation;
    _aniR_Atk->init(_img->getWidth(), _img->getHeight(), 7, 2);
    _aniR_Atk->setPlayFrame(5, 6);
    _aniR_Atk->setFPS(1);

    _rc = RectMakeCenter(point.x, point.y, _img->getWidth()/7, _img->getHeight()/2);

    // 아무튼 총알임
    _bulletImg = IMAGEMANAGER->findImage("CRAB_BULLET");

    _aniBullet = new animation;
    _aniBullet->init(_bulletImg->getWidth(), _bulletImg->getHeight(), 4, 1);
    _aniBullet->setDefPlayFrame(false, true);
    _aniBullet->setFPS(1);

    _bullet = RectMakeCenter(point.x, point.y, _bulletImg->getWidth() / 4, _bulletImg->getHeight());


    // 초기화
    _timer = 0;
    _isFire = false;
    _state = RIGHT_IDLE;
    _re = false;
    _speed = 10;
    _a = 0.2f;
 
    return S_OK;
}

void crab::release()
{

}

void crab::update()
{
    enemy::update();
    
    bulletFire();
    move();
    collision();
}

void crab::render()
{

    if(!_isRemove) draw();

    //if(KEYMANAGER->isToggleKey(VK_TAB)) Rectangle(getMemDC(), _sonicRc);
    //Rectangle(getMemDC(), _rc);

    char str[128];
    //sprintf_s(str, "_x =  %f, _y =  %f", _x, _y);
    //sprintf_s(str, "_d =  %f", getDistance(_x, _y, _rc.left, _rc.top));
   /* sprintf_s(str, "_state =  %d", _point.x + _bx);
    TextOut(getMemDC(), 0, 220, str, strlen(str));*/
}

void crab::move()
{

    d = getDistance(_sonicRc.right, 0, _rc.left, 0);

    // IDLE 모션
    if (_aniL->isPlay() && _state == LEFT_IDLE) {
        _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
        if (!_aniL->isPlay()) _state = RIGHT_IDLE;
    }
    if (_aniR->isPlay() && _state == RIGHT_IDLE) {
        _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
        if (!_aniR->isPlay()) _state = LEFT_IDLE;
    }
    

    // ATK 모션
    if (d <= DISTANCE) {
        if (((_point.x + _bx) - (_sonicRc.left + _sonicRc.right) / 2 - _bx)) {
            _state = RIGHT_ATK;
        }
        else {
            _state = LEFT_ATK;
        }
    }

   
    if (_aniL_Atk->isPlay() && _state == LEFT_ATK) {
        _aniL_Atk->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
        if (!_aniL_Atk->isPlay()) _isFire = true;
    }
    if (_aniR_Atk->isPlay() && _state == RIGHT_ATK) {
        _aniR_Atk->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
        if (!_aniR_Atk->isPlay()) _isFire = true;
    }
    
    
    
    _rc = RectMakeCenter(_point.x - _bx, _point.y + (WINSIZEY - _by), _img->getWidth() / 7, _img->getHeight() / 2);
}

void crab::bulletFire()
{
    if (_isFire) {

        int d = getDistance(_bullet.right, _bullet.top, _rc.left, _rc.top);

        if (_speed < 0) _re = true;

        _aniBullet->resume();
        _aniBullet->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
    }
    else {
        _re = false;
        _speed = 10;
        _x = _rc.left + _bx;
        _y = _point.y + (WINSIZEY - _by);
        _angle = getAngle(_rc.left, _rc.top, _sonicRc.right, _sonicRc.top);

        if(_state == RIGHT_ATK) _state = LEFT_IDLE;
        if(_state == LEFT_ATK) _state = RIGHT_IDLE;
    }

   



    if (_re) {
        /*RECT temp;
        if (IntersectRect(&temp, &_rc, &_bullet)) _isFire = false;*/

        if (_bullet.right < _bx || _bullet.left > WINSIZEX + _bx) _isFire = false;

    }

    
    // 발사궤도
    _x += cosf(_angle) * _speed;
    _y += -sinf(_angle) * _speed;
    _speed -= _a;

    _bullet = RectMakeCenter(_x - _bx, _y + (WINSIZEY - _by), _bulletImg->getWidth() / 4, _bulletImg->getHeight());
}

void crab::draw()
{
    if (_isFire) {
        _bulletImg->aniRender(getMemDC(), _bullet.left, _bullet.top, _aniBullet);     
    }

    if (_state == RIGHT_IDLE) {
        _aniR->resume();

        _aniL->start();
        _aniL_Atk->start();
        _aniR_Atk->start();

        _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);
    }
    else if (_state == LEFT_IDLE) {
        _aniL->resume();

        _aniR->start();
        _aniL_Atk->start();
        _aniR_Atk->start();

        _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    }
    else if (_state == LEFT_ATK) {
        _aniL_Atk->resume();

        _aniL->start();
        _aniR->start();
        _aniR_Atk->start();

        _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL_Atk);
    }
    else if (_state == RIGHT_ATK) {
        _aniR_Atk->resume();

        _aniL->start();
        _aniR->start();
        _aniL_Atk->start();

        _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR_Atk);
    }
    


    
}

void crab::collision()
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
}