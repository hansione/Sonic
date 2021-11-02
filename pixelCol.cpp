#include "pch.h"
#include "pixelCol.h"

HRESULT pixelCol::init()
{
	_ground = IMAGEMANAGER->findImage("���");
	_bossGround = IMAGEMANAGER->findImage("�������");

	// ��Ʈ �߾�
	_x = (_rc.right + _rc.left) / 2;
	_y = (_rc.top + _rc.bottom) / 2;

	// ���� �Ʒ���
	_probeY = _rc.bottom;

	return S_OK;
}

void pixelCol::release()
{
	
}

void pixelCol::update()
{

	// ��Ʈ �߾�
	_x = (_rc.right + _rc.left) / 2;
	_y = (_rc.top + _rc.bottom) / 2;

	// ���� �Ʒ���
	_probeY = _rc.bottom;
	
		// ���� ��Ȳ����
		if (!_isJump) {
			for (int i = _y; i <= _probeY; ++i)
			{
				COLORREF color;
				if (!_isBoss) color = GetPixel(_ground->getMemDC(), _bx + _x, i + _by);
				else color = GetPixel(_bossGround->getMemDC(), _x, i );

				r = GetRValue(color);
				g = GetGValue(color);
				b = GetBValue(color);

				if ((r == 0 && g == 0 && b == 255))
				{
					_y = (i - (_rc.bottom - _rc.top) / 2);
					break;
				}
				else _y += 0.2f;
			}
		}
		else if (_isJump && !_s->getState()->getIsHit()) {
			for (int i = _y; i <= _probeY; ++i)
			{
				COLORREF color;
				if (!_isBoss) color = GetPixel(_ground->getMemDC(), _bx + _x, i + _by);
				else color = GetPixel(_bossGround->getMemDC(), _x, i);


				r = GetRValue(color);
				g = GetGValue(color);
				b = GetBValue(color);


				if ((r == 0 && g == 0 && b == 255))
				{
					_y = (i - (_rc.bottom - _rc.top) / 2);
					_isJump = false;
					break;
				}
				else _isJump = true;
			}
		}

		// ��Ʈ ��Ȳ����
		if (_s->getState()->getIsHit()) {
			for (int i = _y; i <= _probeY; ++i)
			{
				COLORREF color;
				if (!_isBoss) color = GetPixel(_ground->getMemDC(), _bx + _x, i + _by);
				else color = GetPixel(_bossGround->getMemDC(), _x, i );

				r = GetRValue(color);
				g = GetGValue(color);
				b = GetBValue(color);

				if ((r == 0 && g == 0 && b == 255))
				{
					_y = (i - (_rc.bottom - _rc.top) / 2);
					_s->getState()->setIsHit(false);
					break;
				}
			}
		}

	
	
	//Ȯ�ο�
	_rc = RectMakeCenter(_x, _y, (_rc.right - _rc.left), _rc.bottom - _rc.top);

}

void pixelCol::render()
{

	//Rectangle(getMemDC(), _rc);

	if (KEYMANAGER->isToggleKey(VK_TAB)) {
		if (!_isBoss) _ground->render(getMemDC(), 0, 0, _bx, _by, WINSIZEX, WINSIZEY);
		else _bossGround->render(getMemDC());
	}
		

	/*char str[128];

	sprintf_s(str, "r : %d, g : %d, b : %d", r, g, b);
	TextOut(getMemDC(), 0, 100, str, strlen(str));


	char str1[128];

	sprintf_s(str1, "_isJump : %d", _isJump);
	TextOut(getMemDC(), 0, 160, str1, strlen(str1));*/
}

void pixelCol::Boss()
{
	/*for (int i = _y; i <= _probeY; ++i)
	{
		COLORREF color = GetPixel(_bossGround->getMemDC(), _x, i);

		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 255))
		{
			_y = (i - (_rc.bottom - _rc.top) / 2);
			break;
		}
		
	}

	if (!_isJump) {
		for (int i = _y; i <= _probeY; ++i)
		{
			COLORREF color = GetPixel(_bossGround->getMemDC(), _x, i);

			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);

			if ((r == 0 && g == 0 && b == 255))
			{
				_y = (i - (_rc.bottom - _rc.top) / 2);
				break;
			}
			else _y += 0.2f;
		}
	}
	else {
		for (int i = _y; i <= _probeY; ++i)
		{
			COLORREF color = GetPixel(_bossGround->getMemDC(), _x, i);

			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);



			if ((r == 0 && g == 0 && b == 255))
			{
				_y = (i - (_rc.bottom - _rc.top) / 2);
				_isJump = false;
				break;
			}
			//else //_isJump = true;
		}
	}*/

	
}
