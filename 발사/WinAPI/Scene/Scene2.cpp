#include "stdafx.h"
#include "Scene2.h"

HRESULT Scene2::Init()
{
    Hour.Init();
    Hour.Position = Vector2(400.0f,300.0f);
    Hour.Scale = Vector2(200.0f,1.0f);

    Min.Init();
    Min.Position = Vector2(400.0f, 300.0f);
    Min.Scale = Vector2(250.0f, 1.0f);

    Sec.Init();
    Sec.Position = Vector2(400.0f, 300.0f);
    Sec.Scale = Vector2(300.0f, 1.0f);

    return S_OK;
}

void Scene2::Release()
{
}

void Scene2::Update()
{
    //os로부터 현재 시간정보 받아오기
    GetLocalTime(&time);
    cout << time.wHour << "시";
    cout << time.wMinute << "분";
    cout << time.wSecond << "초";
    cout << time.wMilliseconds << "밀리초";
    cout << endl;
                                //분은 시침한테   30/60
    Hour.Rotation = -PI*0.5f +( time.wHour *30.0f
        + time.wMinute *0.5f)*TORADIAN;
    Min.Rotation = -PI*0.5f + time.wMinute *6.0f*TORADIAN;
    Sec.Rotation = -PI*0.5f + (time.wSecond *6.0f
        + time.wMilliseconds *0.006f)*TORADIAN;
}

void Scene2::LateUpdate()
{
    Sec.WorldUpdate();
    Min.WorldUpdate();
    Hour.WorldUpdate();
}

void Scene2::Render()
{
    Sec.Render();
    Min.Render();
    Hour.Render();
}
