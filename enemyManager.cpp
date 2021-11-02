#include "pch.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{
    // 난 여기에서 생성해줄래
    setFlower(PointMake(3800, 360));
    setCrab(PointMake(1000, 350));
    
    // 연습용
    //setFlower(PointMake(600, 450));
    //setCrab(PointMake(600, 300));
    //setTrap(PointMake(WINSIZEX - 200, 400));

    return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
    for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
    {
        (*_viEnemy)->update();
    }

}

void enemyManager::render()
{
    for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy) 
    {
        if(!(*_viEnemy)->getIsRemove()) (*_viEnemy)->render();
    }
}

void enemyManager::setFlower(POINT point)
{

    flower* _flower;
    _flower = new flower;
    _flower->init(point);

    _vEnemy.push_back(_flower);

}

void enemyManager::setCrab(POINT point)
{
    crab* _crab;
    _crab = new crab;
    _crab->init(point);

    _vEnemy.push_back(_crab);
}

void enemyManager::setTrap(POINT point)
{
    trap* _trap;
    _trap = new trap;
    _trap->init(point);

    _vEnemy.push_back(_trap);
}
