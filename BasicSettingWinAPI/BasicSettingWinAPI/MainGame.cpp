#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

HRESULT MainGame::init()
{
	//타이머 생성(일정주기마다 WM_TIMER호출)
   //                 밀리세컨드(1/1000초)
	SetTimer(g_hwnd, 1, 17, NULL);

	return S_OK;
}

void MainGame::release()
{
	//생성된 타이머 해제
	KillTimer(g_hwnd, NULL);
}

void MainGame::update()
{
}

void MainGame::lateupdate()
{
}

void MainGame::render()
{
}
