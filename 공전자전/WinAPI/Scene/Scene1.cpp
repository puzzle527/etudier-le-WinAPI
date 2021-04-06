#include "stdafx.h"
#include "Scene1.h"

//과제 원그리기
//회전이동크기 변환 구현

HRESULT Scene1::Init()
{


    //중심점을 -0.5f만큼 이동
    rc = new Circle();
    rc->Init();
    rc->Position = Vector2(400, 300);
    rc->Rotation = 0.0f;
    rc->Scale = Vector2(100, 100);
    rc->isAxis = true;
	for (int i = 0; i < 5; i++)
	{
		child[i] = new Circle();
	}
	for (int i = 0; i < 5; i++)
	{
		child[i]->Init();
		child[i]->Position = Vector2(200, 200);
		child[i]->Rotation = 0.0f;
		child[i]->Scale = Vector2(30, 30);
		child[i]->isAxis = true;
		child[i]->P = &rc->RT;
	}
	child[1]->Position = Vector2(-100, 50);
	child[2]->Position = Vector2(100, -200);
	child[3]->Position = Vector2(-200, -300);
	child[4]->Position = Vector2(250, -50);

	child[1]->Scale = Vector2(50, 50);
	child[2]->Scale = Vector2(70, 70);
	child[3]->Scale = Vector2(90, 90);
	child[4]->Scale = Vector2(100, 100);


    child2 = new Circle();
    child2->Init();
    child2->Position = Vector2(50, 50);
    child2->Rotation = 0.0f;
    child2->Scale = Vector2(30, 30);
    child2->isAxis = true;
    //차일2드객체의 부모행렬은 rc의 회전이동행렬
    child2->P = &child[3]->RT;


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
	for (int i = 0; i < 5; i++)
	{
		delete child[i];
	}
    delete child2;
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
    //rc->Rotation =
        //DirToRadian(g_Mouse - rc->Position);
    //반시계회전
    //if(KEYMANAGER->KeyPress('A'))
    //{
    //   rc->Rotation -=0.1f;
    //}
    ////시계방향회전
    //if(KEYMANAGER->KeyPress('D'))
    //{
    //    rc->Rotation += 0.1f;
    //}
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
    //cout << g_Mouse.x << ","<< g_Mouse.y <<endl;
    child[0]->Rotation +=0.2f;
    child[1]->Rotation +=0.15f;
    child[2]->Rotation +=0.11f;
    child[3]->Rotation +=0.1f;
    child[4]->Rotation +=0.05f;
	rc->Rotation += 0.01f;
}

void Scene1::LateUpdate()
{

    rc->WorldUpdate();
	for (int i = 0; i < 5; i++)
	{
		child[i]->WorldUpdate();
	}
    child2->WorldUpdate();
}

void Scene1::Render()
{
	for (int i = 0; i < 5; i++)
	{
		child[i]->Render();
	}
    child2->Render();
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
