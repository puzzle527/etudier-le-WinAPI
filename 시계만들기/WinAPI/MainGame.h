#pragma once
class MainGame
{
private:
    Line ln[3];
    //Tri  tr;
    Rect rc;
    Star st;

    SYSTEMTIME time;

public:
    MainGame();//생성
    ~MainGame();//소멸

    HRESULT Init();//초기화
    void Release();//해제

    //루프
    void Update();//갱신
    void LateUpdate();//늦은갱신
    void Render();//그리기
};

