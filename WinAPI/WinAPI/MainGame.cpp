#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
    //실수좌표를 쓸때 주의점
    //부동소수점
    //근사값
    //3.4;
    //3.4f;
    /*0.1f;
    float a =0;
    a += 0.1f;*/
    // if( a == 1.0f)
    //함부로 좌표끼리의 같다 다르다를 쓰면 안됨

}

MainGame::~MainGame()
{
}

HRESULT MainGame::init()
{
    //타이머 생성(일정주기마다 WM_TIMER호출)
    //                 밀리세컨드(1/1000초)
    SetTimer(g_hwnd, 1, 17, NULL);

    //st.init();
    //st.Position.x = 400;
    //st.Position.y = 300;
    //st.Scale = Vector2(100,100);
    //st.Rotation = 0.0f;
	//
    rc.init();
    rc.Position.x = 200;
    rc.Position.y = 300;
    rc.Scale = Vector2(100, 100);
    rc.Rotation = 0.0f;

	sh.init();
	sh.Position.x = 450;
	sh.Position.y = 350;
	sh.Scale = Vector2(1, 1);
	sh.Rotation = 0.0f;

    
    return S_OK;
}

void MainGame::release()
{
    //생성된 타이머 해제
    KillTimer(g_hwnd, NULL);
}

void MainGame::update()
{
    // & | ^ 비트(bit)연산자
    if(GetAsyncKeyState('W')
        & 0x8000)
    {
		sh.Position.y -=3;
    }
    if(GetAsyncKeyState('S')
        & 0x8000)
    {
		sh.Position.y += 3;
    }
    if(GetAsyncKeyState('A')
        & 0x8000)
    {
		sh.Position.x -= 3;
    }
    if(GetAsyncKeyState('D')
        & 0x8000)
    {
		sh.Position.x += 3;
    }

    if(GetAsyncKeyState('1')
        & 0x8000)
    {
		sh.Scale.x += 3;
    }
    if(GetAsyncKeyState('2')
        & 0x8000)
    {
		sh.Scale.y += 3;
    }

    //반시계방향
    if(GetAsyncKeyState('3')
        & 0x8000)
    {
		sh.Rotation += 3;
    }
    //시계방향
    if(GetAsyncKeyState('4')
        & 0x8000)
    {
		sh.Rotation -= 3;
    }
    //이동행렬 멤버값 만들어주는함수
    rc.WorldUpdate();
    //st.WorldUpdate();
	sh.WorldUpdate();
}

void MainGame::lateupdate()
{
    //WM_PAINT 발생시키는 함수
    InvalidateRect(g_hwnd, NULL, true);
}

void MainGame::render()
{
    //선그리기
    //tr.render();
    rc.render();
    //st.render();
	sh.render();
}
