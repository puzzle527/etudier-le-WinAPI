#include "stdafx.h"
#include "MainGame.h"

//과제

//별 이동, 확대 축소 ,회전 구현


MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

HRESULT MainGame::Init()
{
    //타이머 생성(일정주기마다 WM_TIMER호출)
    SetTimer(g_hwnd, 1, 17, NULL);// 17/1000초
    Object::Axis->Init();

    st.Init();
    st.Position = Vector2(400, 300);
    st.Rotation = 0.0f;
    st.Scale = Vector2(100, 100);

    rc.Init();
    rc.Position = Vector2(200, 300);
    rc.Rotation = 0.0f;
    rc.Scale = Vector2(100, 100);

	for (int i = 0; i < 3; i++)
	{
		ln[i].Init();
		ln[i].Position = Vector2(400, 300);
		ln[i].Scale = Vector2(100, -100);
	}
	ln[0].Scale = Vector2(50, -50);
	ln[1].Scale = Vector2(80, -80);
    
    return S_OK;
}

void MainGame::Release()
{
    //생성된 타이머 해제
    KillTimer(g_hwnd,NULL);
    delete Object::Axis;
}

void MainGame::Update()
{
    //os로부터 현재 시간정보 받아오기
    GetLocalTime(&time);
    cout << time.wHour << "시";
    cout << time.wMinute << "분";
    cout << time.wSecond << "초";
    cout << endl;
	ln[0].Rotation = time.wHour * 30 * TORADIAN;
	ln[1].Rotation = time.wMinute * 6 * TORADIAN;
	ln[2].Rotation = time.wSecond * 6 * TORADIAN;

    // & | ^ 비트연산자
    //이동
    if (GetAsyncKeyState('W') 
        & 0x8000)
    {
        rc.Position.y -= 3;
    }
    if (GetAsyncKeyState('S')
        & 0x8000)
    {
        rc.Position.y += 3;
    }
    if(GetAsyncKeyState('A')
        & 0x8000)
    {
        rc.Position.x -= 3;
    }
    if(GetAsyncKeyState('D')
        & 0x8000)
    {
        rc.Position.x += 3;
    }
    //확대
    if(GetAsyncKeyState('1')
        & 0x8000)
    {
        rc.Scale.x += 3;
    }
    //축소
    if(GetAsyncKeyState('2')
        & 0x8000)
    {
        rc.Scale.y -= 3;
    }

    //시계방향
    if(GetAsyncKeyState('3')
        & 0x8000)
    {
        rc.Rotation -= 0.1f;
    }
    //반시계방향
    if(GetAsyncKeyState('4')
        & 0x8000)
    {
        rc.Rotation += 0.1f;
    }
 
   
}

void MainGame::LateUpdate()
{

    st.WorldUpdate();
    rc.WorldUpdate();
	for (int i = 0; i < 3; i++)
	{
		ln[i].WorldUpdate();
	}
    //WM_PAINT 발생시키는 함수
    InvalidateRect(g_hwnd, NULL, true);
}

void MainGame::Render()
{
    //st.Render();
    //rc.Render();
    //ln.Render();
	for (int i = 0; i < 3; i++)
	{
		ln[i].Render();
	}
	//Ellipse(g_hdc,300, 200, 500, 400);
}
