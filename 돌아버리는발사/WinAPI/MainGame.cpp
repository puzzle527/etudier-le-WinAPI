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
    KEYMANAGER; //키매니저 할당

    HBITMAP	 m_hOldBitmap, m_hBitmap;

    HDC	hdc = GetDC(g_hwnd); //기존핸들
    g_MemDC = CreateCompatibleDC(hdc);	//
    m_hBitmap = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);//만들크기
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);


    sc1 = new Scene1();
    sc1->Init();
    sc2 = new Scene2();
    sc2->Init();
    CurrentScene = sc1;
    return S_OK;
}

void MainGame::Release()
{
    KEYMANAGER->DeleteSingleton();

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
    KEYMANAGER->Update();
    if(KEYMANAGER->KeyDown(VK_F1))
    {
        CurrentScene = sc1;
    }
    if(KEYMANAGER->KeyDown(VK_F2))
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
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    //바탕색 깔기
    PatBlt(g_MemDC, 0, 0, WINSIZEX, WINSIZEY,
        WHITENESS);

    if(CurrentScene)
    {
        CurrentScene->Render();
    }

    //고속 복사 g_MemDC에서 g_hdc로
    BitBlt(g_hdc, 0, 0, WINSIZEX, WINSIZEY,
        g_MemDC, 0, 0, SRCCOPY);
}
