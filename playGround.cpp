#include "pch.h"
#include "playGround.h"


playGround::playGround()
{

}


playGround::~playGround()
{

}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	
	// 상태 이미지
	IMAGEMANAGER->addImage("IDLE", "Image/Idle.bmp", 186, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RUN", "Image/Run.bmp", 148, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("DUCK", "Image/Duck.bmp", 58, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ROLL & JUMP", "Image/Roll.bmp", 150, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HIT", "Image/Hit.bmp", 30, 72, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("WIN", "Image/Win.bmp", 46, 39, true, RGB(255, 0, 255));


	// 배경 이미지

	IMAGEMANAGER->addImage("BG", "Image/배경화면.bmp", 3215 * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("보스존", "Image/BossZone.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("언덕", "Image/배경시험.bmp", 3215 * 2, WINSIZEY*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("보스언덕", "Image/BossPixelCol.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("시작", "Image/ACT.bmp", 406, 116, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("타이틀배경", "Image/TitleBG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("타이틀소닉", "Image/TitleSonic.bmp", 1024, 364, true, RGB(255, 0, 255));


	// 적 이미지
	IMAGEMANAGER->addImage("FLOWER", "Image/대포꽃.bmp", 235, 68, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("FLOWER_BULLET", "Image/대포알.bmp", 35, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("CRAB", "Image/원반게.bmp", 1008, 184, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("CRAB_BULLET", "Image/원반.bmp", 148, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("TRAP", "Image/가시.bmp", 128, 32, true, RGB(255, 0, 255));

	// 보스
	IMAGEMANAGER->addImage("보스", "Image/Eggman.bmp", 71, 62, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("링", "Image/Ring.bmp", 20, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공", "Image/Ball.bmp", 38, 38, true, RGB(255, 0, 255));

	
	// 오브젝트 이미지 
	IMAGEMANAGER->addImage("동전", "Image/Object_Gold.bmp", 144, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("폴대", "Image/Safe_Poll.bmp", 16, 48, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("원", "Image/Safe_Circle.bmp", 32, 16, 2, 1, true, RGB(255, 0, 255));



	// 씬 변경
	SCENEMANAGER->addScene("시작화면", new startScene);
	SCENEMANAGER->addScene("메인화면", new mainScene);

	SCENEMANAGER->changeScene("시작화면");
	

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();
	


	SCENEMANAGER->update();
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============
	



	SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

