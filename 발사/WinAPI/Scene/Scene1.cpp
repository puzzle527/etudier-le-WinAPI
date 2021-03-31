#include "stdafx.h"
#include "Scene1.h"

//과제 원그리기
//회전이동크기 변환 구현

HRESULT Scene1::Init()
{
	rc = new Circle();
    rc->Init();
    rc->Position = Vector2(200, 300);
    rc->Rotation = 0.0f;
    rc->Scale = Vector2(100, 100);
    rc->isAxis = true;

	rectangle = new Rect();
	rectangle->Init();
	rectangle->Position = Vector2(600, 200);
	rectangle->Rotation = 0.0f;
	rectangle->Scale = Vector2(100, 100);

	
	ball.Init();
	ball.Position = Vector2(300, 300);
	ball.Rotation = 0.0f;
	ball.Scale = Vector2(30, 30);

	rectball.Init();
	rectball.Position = Vector2(200, 300);
	rectball.Rotation = 0.0f;
	rectball.Scale = Vector2(30, 30);
  

    return S_OK;
}

void Scene1::Release()
{
	delete rc;
	delete rectangle;
}

void Scene1::Update()
{

    // & | ^ 비트연산자
    //이동
    if(GetAsyncKeyState('W')
        & 0x8000)
    {
        rc->Position += 
            rc->Right * 3.0f;
    }
    if(GetAsyncKeyState('S')
        & 0x8000)
    {
        rc->Position -=
            rc->Right * 3.0f;
    }
    //반시계회전
    if(GetAsyncKeyState('A')
        & 0x8000)
    {
       rc->Rotation -=0.1f;
    }
    //시계방향회전
    if(GetAsyncKeyState('D')
        & 0x8000)
    {
        rc->Rotation += 0.1f;
    }
	if (GetAsyncKeyState(VK_SPACE)
			& 0x8000)
	{
		ball.Position = Vector2(300, 300);
		if (!balltrue)
			balltrue = 1;
		else
			balltrue = 0;

		rectball.Position = rc->Position;
		if (!rectballtrue)
			rectballtrue = 1;
		else
			rectballtrue = 0;

	}
}

void Scene1::LateUpdate()
{
    rc->WorldUpdate();
	rectangle->WorldUpdate();
	ball.WorldUpdate();
	rectball.WorldUpdate();
}

void Scene1::Render()
{
	rc->Render();
	rectangle->Render();
	if (balltrue && (ball.Position.x < 800 || ball.Position.y < 600))
	{
		ball.Position += rc->Right * 8.0f;
		ball.Render();
	}
	if (rectballtrue && (rectball.Position.x < 800 || rectball.Position.y < 600))
	{
		Vector2 Dir = rectangle->Position - rc->Position;
		D3DXVec2Normalize(&Dir, &Dir);
		rectball.Position += Dir * 3.0f;
		rectball.Render();
	}
}
