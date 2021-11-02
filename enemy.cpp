#include "pch.h"
#include "enemy.h"

HRESULT enemy::init()
{
    
    return S_OK;
}

HRESULT enemy::init(POINT point)
{

    return S_OK;
}

void enemy::release()
{

}

void enemy::update()
{
    //pixelCollision();
}

void enemy::render()
{
    draw();
}

void enemy::draw()
{
	char str[128];
	sprintf_s(str, "r : %d, g : %d, b : %d", r, g, b);
	TextOut(getMemDC(), 0, 220, str, strlen(str));
}

void enemy::pixelCollision()
{
	// 볼의 아래쪽
	//int _probeY = _rc.bottom;

	for (int i = _point.y; i <= _rc.bottom + 10; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("언덕")->getMemDC(), _point.x - _bx, i);

		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 255))
		{
			_point.y = (i - (_rc.bottom - _rc.top) / 2);
			break;
		}
		else _point.y += 0.5f;
	}
}


