#include "pch.h"
#include "camera.h"


HRESULT camera::init()
{
    
    _bg = IMAGEMANAGER->findImage("BG");
    _bossBg = IMAGEMANAGER->findImage("보스존");

    _bx = 0;
    _by = WINSIZEY;

    _isSonicMoveX = _isSonicMoveY = false;

    _isBoss = false;
    _fadeIn = 0;
    _fadeOut = 255;

    return S_OK;
}

void camera::release()
{
}

void camera::update()
{
    if (_bx >= _bg->getWidth() - WINSIZEX - 3) _isBoss = true;


    if (!_isBoss) {
        if (!_isRoll) {
            if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
                _dir = 0;
            }
            if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
                _dir = 1;
            }
        }

        if (!_isSonicMoveX) {
            if (_dir == 0 && _bx > 5) _bx -= _xSpeed;
            else if (_dir == 1 && _bx < _bg->getWidth() - WINSIZEX - 5) _bx += _xSpeed;

        }
        if (_bx <= 5 || _bx >= _bg->getWidth() - WINSIZEX - 5) {
            // 소닉 움직여라
            _isSonicMoveX = true;
        }

        if (!_isSonicMoveY && _by <= WINSIZEY) {
            _by -= _ySpeed;
            if (_by >= WINSIZEY) _by = WINSIZEY;
        }
        if (_by == WINSIZEY) _isSonicMoveY = true;

    }
    else {
        if (_fadeIn < 254) _fadeIn++;
        if (_fadeOut > 0) _fadeOut--;

        _isSonicMoveX = true;
        _isSonicMoveY = true;
    }


}

void camera::render()
{
    _bg->alphaRender(getMemDC(), 0, 0, _bx, _by, WINSIZEX, WINSIZEY, _fadeOut);
    _bossBg->alphaRender(getMemDC(), _fadeIn);
   
   
  
    //_bg->alphaRender(getMemDC(), 0, 0, 255);


    /*char str[128];
    sprintf_s(str, " %f, %f", 3700 - _bx, 300 + (WINSIZEY - _by));
    TextOut(getMemDC(), 10, 300, str, strlen(str));*/

    /*sprintf_s(str, "_isSonicMove : %d", _isSonicMoveY);
    TextOut(getMemDC(), 10, 140, str, strlen(str));*/
    //Rectangle(getMemDC(), _rc1);

    char str1[128];

    /*sprintf_s(str1, "_xSpeed : %f", _xSpeed);
    TextOut(getMemDC(), 10, 120, str1, strlen(str1));*/

}
