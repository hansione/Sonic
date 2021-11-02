#include "pch.h"
#include "roll.h"
#include "Sonic.h"

HRESULT roll::init()
{
    _img = IMAGEMANAGER->findImage("ROLL & JUMP");

    _aniL = new animation;
    _aniL->init(_img->getWidth(), _img->getHeight(), 5, 2);
    _aniL->setPlayFrame(4, 0, false, true);
    _aniL->setFPS(1);

    _aniR = new animation;
    _aniR->init(_img->getWidth(), _img->getHeight(), 5, 2);
    _aniR->setPlayFrame(5, 9, false, true);
    _aniR->setFPS(1);

    _xSpeed = 0;
    _isRoll = false;

 
    

    return S_OK;
}

void roll::release()
{
}

void roll::update()
{
    move();
    aniChange();

    _aniL->frameUpdate(TIMEMANAGER->getElapsedTime() * _xSpeed * 2);
    _aniR->frameUpdate(TIMEMANAGER->getElapsedTime() * _xSpeed * 2);

    _rc = RectMakeCenter(_x, _y, _img->getWidth() / 5, _img->getHeight() / 2);
    
}

void roll::render()
{
    if (_dir == LEFT)   _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniL);
    if (_dir == RIGHT)  _img->aniRender(getMemDC(), _rc.left, _rc.top, _aniR);

    
}

void roll::move()
{
    if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
        //가속도는 일정속도만큼 올라감
        if (_xSpeed >= 10.0f) _xSpeed = 10.0f;
        else _xSpeed += 0.1f;
        _isSonicMoveX = true;
    }

    if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) {
        _isRoll = true;
    }

    if (_isRoll) {
        if (_isSonicMoveX) {
            if (_dir == LEFT) {
                if (_rc.left > 0) {
                    _x -= _xSpeed;
                    _xSpeed -= _a;

                    if (_x < 200) _isSonicMoveX = false;
                    else _isSonicMoveX = true;
                }
                else _xSpeed -= _a;
            }

            if (_dir == RIGHT) {
                if (_rc.right < WINSIZEX) {
                    _x += _xSpeed;
                    _xSpeed -= _a;

                    if (_x > 600) _isSonicMoveX = false;
                    else _isSonicMoveX = true;
                }
                else _xSpeed -= _a;
            }

            
        }
        else {
            _xSpeed -= _a;
            if (_dir == LEFT) {
                if (_x < 200) _isSonicMoveX = false;
                else _isSonicMoveX = true;
            }
            else {
                if (_x > 600) _isSonicMoveX = false;
                else _isSonicMoveX = true;
            }
        }


        if (_xSpeed <= 0.1f) {
            _xSpeed = 0;
            _isRoll = false;
            _s->setIdle();
        }
    }
    
  
    


    // 굴러서 손뗏으면 쏴라
    /*if (_isRoll) {
        if (_rc.left > 0 && _rc.right < WINSIZEX) {
            if (_dir == LEFT) {
                if (_isSonicMove) {
                    _x -= _xSpeed;
                    _xSpeed -= _a;
                }

            }
            if (_dir == RIGHT) {
                _x += _xSpeed;
                _xSpeed -= _a;
            }
        }
        // 벽끝에 닿으면 속도만 빠져라
        else {
            _xSpeed -= _a;
        }  


        // 속도가 일정이하로 빠지면 IDLE상태로 변경
        if (_xSpeed <= 0.1f) {
            _xSpeed = 0;
            _isRoll = false;
            _s->setIdle();
        }
    }*/
    
    
}

void roll::aniChange()
{
    if (_dir == LEFT) {
        _aniL->resume();
    }
    if (_dir == RIGHT) {
        _aniR->resume();
    }
}
