#pragma once
class MainGame
{
private:
    Rect rc;    //사각형
    Star st;
    //Tri  tr;    //삼각형
	Shape sh;
    
    

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

