#include "pch.h"
#include "Sonic.h"

HRESULT Sonic::init()
{
    gameNode::init();

    // ���µ� �ʱ�ȭ
    _run = new run;
    _run->init();

    _idle = new idle;
    _idle->init();

    _jump = new jump;
    _jump->init();

    _duck = new duck;
    _duck->init();

    _roll = new roll;
    _roll->init();
    
    _hit = new hit;
    _hit->init();

    _win = new win;
    _win->init();

    // ù ����
    _state = _idle;
    _state -> init();

    // ��ó�� ����
    char str[128];
    vector<string> vStr;

    vStr.push_back(gcvt((int)_state->getX(), 10, str));
    vStr.push_back(gcvt((int)_state->getY(), 20, str));


    TXTDATA->txtSave("��.txt", vStr);

    return S_OK;
}

void Sonic::release()
{
    gameNode::release();
}

void Sonic::update()
{
    gameNode::update();


    /*if (KEYMANAGER->isOnceKeyDown(VK_F1))
    {
        char str[128];
        vector<string> vStr;

        vStr.push_back(gcvt((int)_state->getX(), 10, str));
        vStr.push_back(gcvt((int)_state->getY(), 20, str));
        //vStr.push_back(gcvt(120, 20, str));


        TXTDATA->txtSave("��.txt", vStr);
    }*/

    if (KEYMANAGER->isOnceKeyDown(VK_F2))
    {

        vector<string> vStr;
        vStr = TXTDATA->txtLoad("��.txt");

        _state->setX(atof(vStr[0].c_str()));
        _state->setY(atof(vStr[1].c_str()));
    }

    _state->update();
}

void Sonic::render()
{
    _state->render();

    /*char str[128];
    char str1[128];

    sprintf_s(str, "sonic.left : %f", _state->getX());
    sprintf_s(str1, "sonic.top : %f", _state->getY());

    TextOut(getMemDC(), 0, 60 ,str, strlen(str));
    TextOut(getMemDC(), 0, 80 ,str1, strlen(str1));


    char str2[128];
    sprintf_s(str2, "count : %d", _state->getCoin());
    TextOut(getMemDC(), 0, 260, str2, strlen(str2));*/

}

void Sonic::setValue(State* state)
{
    state->setCoin(_state->getCoin());
    state ->setRect(_state->getRect());
    state->setX(_state->getX());
    state->setY(_state->getY());
    state->setDir(_state->getDir());
    state->setIsJump(_state->getIsJump());
    state->setIsSonicMoveY(_state->getIsSonicMoveY());
    state->setIsHit(_state->getIsHit());
    _state = state;
}



