#include "stdafx.h"
#include "Scene1.h"

//과제 원그리기
//회전이동크기 변환 구현

HRESULT Scene1::Init()
{


    //중심점을 -0.5f만큼 이동
    rc = new Rect();
    rc->Init();
    rc->Position = Vector2(200, 300);
    rc->Rotation = 0.0f;
    rc->Scale = Vector2(100, 100);
    rc->isAxis = true;

	ln = new Rect();
	ln->Init();
	ln->Scale = Vector2(10.0f, 10.0f);
	ln->isAxis = true;

	tri = new triangle();
	tri->Init();
	tri->Position = Vector2(30.0f, 30.0f);
	tri->Rotation = 0.0f;
	tri->Scale = Vector2(20.0f, 20.0f);
	tri->isAxis = false;
	tri->P = &ln->RT;

    //child = new Rect();
    //child->Init();
    //child->Position = Vector2(100, 100);
    //child->Rotation = 0.0f;
    //child->Scale = Vector2(50, 50);
    //child->isAxis = true;
    ////차일드객체의 부모행렬은 rc의 회전이동행렬
    //child->P = &rc->RT;
	//
    //child2 = new Rect();
    //child2->Init();
    //child2->Position = Vector2(70, 70);
    //child2->Rotation = 0.0f;
    //child2->Scale = Vector2(30, 30);
    //child2->isAxis = true;
    ////차일2드객체의 부모행렬은 rc의 회전이동행렬
    //child2->P = &child->RT;


    //그려줄총알을 30크기로만 설정

    return S_OK;
}

void Scene1::Release()
{
    
    delete rc;
    delete ln;
	delete tri;
    //delete child;
    //delete child2;
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
    rc->Rotation =
        DirToRadian(g_Mouse - rc->Position);
	tri->Rotation2 += 0.3f;
    //반시계회전
    if(KEYMANAGER->KeyPress('A'))
    {
       rc->Rotation -=0.1f;
    }
    //시계방향회전
    if(KEYMANAGER->KeyPress('D'))
    {
        rc->Rotation += 0.5f;
    }
    if(KEYMANAGER->KeyDown(VK_SPACE))
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

        bl[i].Pos += bl[i].Dir * 5.0f;

    }
    //cout << g_Mouse.x << ","<< g_Mouse.y <<endl;
    //child->Rotation +=0.1f;
}

void Scene1::LateUpdate()
{

    rc->WorldUpdate();
	ln->WorldUpdate();
	tri->WorldUpdate();
    //child->WorldUpdate();
    //child2->WorldUpdate();
}

void Scene1::Render()
{
    //child->Render();
    //child2->Render();
    rc->Render();
    //발사된 총알은 그려주기
    for(int i = 0; i < BULLETMAX; i++)
    {
        if(!bl[i].isFire) continue;

        //그려주기
        ln->Position = bl[i].Pos;
        ln->Rotation = DirToRadian(bl[i].Dir);
        ln->WorldUpdate();
        //ln->Render();

		tri->WorldUpdate();
		tri->Render();
    }
}
