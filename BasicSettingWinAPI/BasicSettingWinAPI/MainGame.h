#pragma once
class MainGame
{
private:

public:
	MainGame();     //생성
	~MainGame();    //소멸

	HRESULT init(); //초기화
	void release(); //해제

	//루프
	void update();      //갱신
	void lateupdate();  //늦은갱신
	void render();      //그리기
};

