#include "stdafx.h"
#include "Scene1.h"

//과제 원그리기
//회전이동크기 변환 구현

HRESULT Scene1::Init()
{

    //st.Init();
    //st.Position = Vector2(400, 300);
    //st.Rotation = 0.0f;
    //st.Scale = Vector2(100, 100);

    //중심점을 -0.5f만큼 이동
    rc = new Rect(Vector2(-0.2f,0.0f));
    rc->Init();
    rc->Position = Vector2(200, 300);
    rc->Rotation = 0.0f;
    rc->Scale = Vector2(100, 100);
    rc->isAxis = true;

    //ln.Init();
    //ln.Position = Vector2(200, 300);
    //ln.Rotation = 0.0f;
    //ln.Scale = Vector2(100, 100);

	cir.Init();
	cir.Position = Vector2(400, 300);
	cir.Rotation = 0.0f;
	cir.Scale = Vector2(100, 100);
	//cir.Axis = true;



    return S_OK;
}

void Scene1::Release()
{
}

void Scene1::Update()
{

    // & | ^ 비트연산자
    //이동
    if(GetAsyncKeyState('W')
        & 0x8000)
    {
        //         45?
        //                    방향    * 크기
        cir.Position += Vector2(cosf(45 * TORADIAN), sinf(45 * TORADIAN))*3.0f;
    }
    if(GetAsyncKeyState('S')
        & 0x8000)
    {
        cir.Position += Vector2(-1.0f, 0.0f)*3.0f;
    }
    if(GetAsyncKeyState('A')
        & 0x8000)
    {
        //원이 네모를 향해 움직이기
        Vector2 Dir
            = rc->Position - cir.Position;
        //단위벡터로 만들기
        D3DXVec2Normalize(&Dir, &Dir);
        //            방향
        cir.Position += Dir * 3.0f;
    }
    if(GetAsyncKeyState('D')
        & 0x8000)
    {
		cir.Position += Vector2(1.0f, 0.0f)*3.0f;
    }
    //확대
    if(GetAsyncKeyState('1')
        & 0x8000)
    {
        cir.Scale += Vector2(cosf(45 * TORADIAN), sinf(45 * TORADIAN))*3.0f;;
    }
    //축소
    if(GetAsyncKeyState('2')
        & 0x8000)
    {
		cir.Scale -= Vector2(cosf(45 * TORADIAN), sinf(45 * TORADIAN))*3.0f;
    }

    //시계방향
    if(GetAsyncKeyState('3')
        & 0x8000)
    {
		cir.Rotation -= 0.1f;
    }
    //반시계방향
    if(GetAsyncKeyState('4')
        & 0x8000)
    {
		cir.Rotation += 0.1f;
    }

}

void Scene1::LateUpdate()
{

    //st.WorldUpdate();
    rc->WorldUpdate();
    //ln.WorldUpdate();
	cir.WorldUpdate();
}

void Scene1::Render()
{
    //st.Render();
    rc->Render();
    ln.Render();
	cir.Render();
}
