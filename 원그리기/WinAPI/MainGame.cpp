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

    sc1 = new Scene1();
    sc1->Init();
    sc2 = new Scene2();
    sc2->Init();

    return S_OK;
}

void MainGame::Release()
{
    sc1->Release();
    delete sc1;

    sc2->Release();
    delete sc2;

    //생성된 타이머 해제
    KillTimer(g_hwnd,NULL);
    delete Object::Axis;
}

void MainGame::Update()
{
    if(GetAsyncKeyState(VK_F1)
        & 0x8000)
    {
        CurrentScene = sc1;
    }
    if(GetAsyncKeyState(VK_F2)
        & 0x8000)
    {
        CurrentScene = sc2;
    }
    if(CurrentScene)
    {
        CurrentScene->Update();
    }
   
}

void MainGame::LateUpdate()
{
    if(CurrentScene)
    {
        CurrentScene->LateUpdate();
    }
    //WM_PAINT 발생시키는 함수
    InvalidateRect(g_hwnd, NULL, true);
}

void MainGame::Render()
{
    if(CurrentScene)
    {
        CurrentScene->Render();
    }
}
