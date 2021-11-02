#include "pch.h"
#include "State.h"


HRESULT State::init()
{
    gameNode::init();



    return S_OK;
}

void State::release()
{
    gameNode::release();
}

void State::update()
{
    gameNode::update();
}

void State::render()
{
   // gameNode::render();
}

