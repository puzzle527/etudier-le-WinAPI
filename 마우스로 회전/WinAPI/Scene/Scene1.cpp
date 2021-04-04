#include "stdafx.h"
#include "Scene1.h"

//과제 원그리기
//회전이동크기 변환 구현

HRESULT Scene1::Init()
{


    //중심점을 -0.5f만큼 이동
    rc = new Circle();
    rc->Init();
    rc->Position = Vector2(200, 300);
    rc->Rotation = 0.0f;
    rc->Scale = Vector2(100, 100);
    rc->isAxis = true;

    //그려줄총알을 30크기로만 설정
    ln = new Line();
    ln->Init();
    ln->Scale.x = 30.0f;

    return S_OK;
}

void Scene1::Release()
{
    
    delete rc;
    delete ln;
}

void Scene1::Update()
{

    // & | ^ 비트연산자
    //이동
    if(KEYMANAGER->KeyPress('W'))
    {
        rc->Position +=
            rc->Right * 3.0f;
    }
    if(KEYMANAGER->KeyPress('S'))
    {
        rc->Position -=
            rc->Right * 3.0f;
    }
    //반시계회전
    if(KEYMANAGER->KeyPress('A'))
    {
       rc->Rotation -=0.1f;
    }
    //시계방향회전
    if(KEYMANAGER->KeyPress('D'))
    {
        rc->Rotation += 0.1f;
    }
    if(KEYMANAGER->KeyDown(VK_LBUTTON))
    {
        //한발씩발사
        for(int i = 0; i < BULLETMAX; i++)
        {
            //발사된놈은 거르고 발사안된놈을 찾기
            if(bl[i].isFire)continue;

            //발사됨이라고 만들기
            bl[i].isFire = true;
            bl[i].Pos = rc->Position;
            bl[i].Dir = rc->Right;
            //bl[i].Rot = rc->Rotation;
            break;//한발만쏴야해서 반복문 탈출
        }
    }
    
    //발사된 총알은 날아가게 하기
    for(int i = 0; i < BULLETMAX; i++)
    {
        if(!bl[i].isFire)continue;

        bl[i].Pos += bl[i].Dir * 10.0f;

    }
    cout << g_Mouse.x << ","<< g_Mouse.y <<endl;

}

void Scene1::LateUpdate()
{

    rc->WorldUpdate();
}

void Scene1::Render()
{
	rc->Right = Vector2(g_Mouse.x, g_Mouse.y) - rc->Position;
	D3DXVec2Normalize(&rc->Right, &rc->Right);
	rc->Rotation = DirToRadian(rc->Right);
	rc->WorldUpdate();
    rc->Render();
    //발사된 총알은 그려주기
    for(int i = 0; i < BULLETMAX; i++)
    {
        if(!bl[i].isFire) continue;

        //그려주기
        ln->Position = bl[i].Pos;
        ln->Rotation = DirToRadian(bl[i].Dir);
        ln->WorldUpdate();
        ln->Render();
    }

}
