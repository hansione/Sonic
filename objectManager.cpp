#include "pch.h"
#include "objectManager.h"

HRESULT objectManager::init()
{

    setCoin(PointMake(1700,250));
    setSafezone(PointMake(2700, 260));

    //setSafezone(PointMake(500, 300));

    return S_OK;
}

void objectManager::release()
{


}

void objectManager::update()
{

    for (int i = 0; i < _vObject.size(); i++) {
        _vObject[i]->update();
    }
}

void objectManager::render()
{

    for (int i = 0; i < _vObject.size(); i++) {
        _vObject[i]->render();
    }
}

void objectManager::setCoin(POINT p)
{
    float _angle = PI / 2;

    for (int i = 0; i < 5; i++) {
        int x = p.x + sinf(_angle) * 100;
        int y = p.y -cosf(_angle) * 50;

        object* _coin;
        _coin = new coin;
        _coin->init(PointMake(x, y));

        _vObject.push_back(_coin);

        _angle -= PI / 4;
    }
}

void objectManager::setSafezone(POINT p)
{
    object* _safezone;
    _safezone = new safezone;
    _safezone->init(p);

    _vObject.push_back(_safezone);

}
