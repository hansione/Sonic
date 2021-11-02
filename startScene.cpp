#include "pch.h"
#include "startScene.h"

HRESULT startScene::init()
{

    _bg = IMAGEMANAGER->findImage("Ÿ��Ʋ���");

    _sonic = IMAGEMANAGER->findImage("Ÿ��Ʋ�Ҵ�");
    _sonic->setX(WINSIZEX / 2 - _sonic->getWidth() / 4);
    _sonic->setY(WINSIZEY / 2 - _sonic->getHeight() / 2);


    _ani = new animation;
    _ani->init(_sonic->getWidth(), _sonic->getHeight(), 2, 1);
    _ani->setDefPlayFrame(false, true);
    _ani->setFPS(1);

    return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
    _ani->resume();

    if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) {
        SCENEMANAGER->changeScene("����ȭ��");
    }

    _ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
}

void startScene::render()
{
    _bg->render(getMemDC());
    _sonic->aniRender(getMemDC(), _sonic->getX(), _sonic->getY(), _ani);
}
