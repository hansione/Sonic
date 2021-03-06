#pragma once
#include <vector>

class animation
{
public:
	//프레임 리스트
	typedef vector<POINT> _vFrameList;

	//재생리스트
	typedef vector<int> _vPlayList;

private:
	int					_frameNum;			//프레임 갯수

	_vFrameList			_frameList;		
	_vPlayList			_playList;

	int					_frameWidth;		//프레임 가로크기
	int					_frameHeight;		//프레임 세로크기

	BOOL				_loop;				//애니메이션 루프 여부

	float				_frameUpdateSec;	//프레임 업데이트
	float				_elapsedSec;		

	DWORD				_nowPlayIdx;
	BOOL				_play;
public:
	animation();
	~animation();

	HRESULT init2(int totalW, int totalH, int frameW, int frameH);
	HRESULT init(int totalW, int totalH, int frameX, int frameY);
	void release();

	//디폴트 애니메이션 재생
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);

	//배열로 담아서 애니메이션 재생
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);

	//구간 애니메이션 재생
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start();
	void stop();
	void pause();
	void resume();


	inline BOOL isPlay() { return _play; }

	inline POINT getFramePos() { return _frameList[_playList[_nowPlayIdx]]; }


	inline int getFrameWidth()	{ return _frameWidth; }
	inline int getFrameHeight() { return _frameHeight; }
};

