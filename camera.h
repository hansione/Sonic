#pragma once
#include "gameNode.h"
#include "Sonic.h"
#include "pixelCol.h"

class camera : public gameNode
{
private:
	image* _bg, *_bossBg;
	

	float _bx, _by;
	float _xSpeed, _ySpeed;

	pixelCol* _pc;

	bool _isSonicMoveX, _isSonicMoveY;
	bool _isRoll;

	int _dir;

	//������
	bool _isBoss;
	int _fadeIn, _fadeOut;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	// ī�޶� ����
	float getXSpeed() { return _xSpeed; }
	void setXSpeed(float xSpeed) { _xSpeed = xSpeed; }

	float getYSpeed() { return _ySpeed; }
	void setYSpeed(float ySpeed) { _ySpeed = ySpeed; }

	float getBX() { return _bx; }
	void setBX(float bx) { _bx = bx; }

	float getBY() { return _by; }
	void setBY(float by) { _by = by; }

	pixelCol* getPC() { return _pc; }
	void setPC(pixelCol* pc) { _pc = pc; }

	// ī�޶� �̵��� ���� ������, ������
	bool getIsSonicMoveX() { return _isSonicMoveX; }
	void setIsSonicMoveX(bool isSonicMove) { _isSonicMoveX = isSonicMove; }

	bool getIsSonicMoveY() { return _isSonicMoveY; }
	void setIsSonicMoveY(bool isSonicMoveY) { _isSonicMoveY = isSonicMoveY; }

	bool getIsRoll() { return _isRoll; }
	void setIsRoll(bool isRoll) { _isRoll = isRoll; }


	// ������ ���� ��

	bool getIsBoss() { return _isBoss; }

	int getFadeOut() { return _fadeOut; }

};

