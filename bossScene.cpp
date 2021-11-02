#include "pch.h"
#include "bossScene.h"

HRESULT bossScene::init()
{

    _sonic = new Sonic;
    _sonic->init();

    _bg = IMAGEMANAGER->findImage("º¸½ºÁ¸");

    return S_OK;
}

void bossScene::release()
{
}

void bossScene::update()
{
    _sonic->update();
}

void bossScene::render()
{
    _sonic->render();
    _bg->render(getMemDC());

    char str[128];
    sprintf_s(str, " %f, %f ", _sonic->getState()->getX(), _sonic->getState()->getY());
    TextOut(getMemDC(), 0, 50, str, strlen(str));

    
}
