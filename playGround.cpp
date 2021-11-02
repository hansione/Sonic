#include "pch.h"
#include "playGround.h"


playGround::playGround()
{

}


playGround::~playGround()
{

}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	
	// ���� �̹���
	IMAGEMANAGER->addImage("IDLE", "Image/Idle.bmp", 186, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RUN", "Image/Run.bmp", 148, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DUCK", "Image/Duck.bmp", 58, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ROLL & JUMP", "Image/Roll.bmp", 150, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HIT", "Image/Hit.bmp", 30, 72, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("WIN", "Image/Win.bmp", 46, 39, true, RGB(255, 0, 255));


	// ��� �̹���

	IMAGEMANAGER->addImage("BG", "Image/���ȭ��.bmp", 3215 * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "Image/BossZone.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("���", "Image/������.bmp", 3215 * 2, WINSIZEY*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "Image/BossPixelCol.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("����", "Image/ACT.bmp", 406, 116, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("Ÿ��Ʋ���", "Image/TitleBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ÿ��Ʋ�Ҵ�", "Image/TitleSonic.bmp", 1024, 364, true, RGB(255, 0, 255));


	// �� �̹���
	IMAGEMANAGER->addImage("FLOWER", "Image/������.bmp", 235, 68, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("FLOWER_BULLET", "Image/������.bmp", 35, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("CRAB", "Image/���ݰ�.bmp", 1008, 184, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("CRAB_BULLET", "Image/����.bmp", 148, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TRAP", "Image/����.bmp", 128, 32, true, RGB(255, 0, 255));

	// ����
	IMAGEMANAGER->addImage("����", "Image/Eggman.bmp", 71, 62, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "Image/Ring.bmp", 20, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "Image/Ball.bmp", 38, 38, true, RGB(255, 0, 255));

	
	// ������Ʈ �̹��� 
	IMAGEMANAGER->addImage("����", "Image/Object_Gold.bmp", 144, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "Image/Safe_Poll.bmp", 16, 48, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("��", "Image/Safe_Circle.bmp", 32, 16, 2, 1, true, RGB(255, 0, 255));



	// �� ����
	SCENEMANAGER->addScene("����ȭ��", new startScene);
	SCENEMANAGER->addScene("����ȭ��", new mainScene);

	SCENEMANAGER->changeScene("����ȭ��");
	

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();
	


	SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	



	SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

