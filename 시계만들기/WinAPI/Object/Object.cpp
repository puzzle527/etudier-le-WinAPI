#include "stdafx.h"
#include "Object.h"

//정적멤버는 cpp 전역에서 호출하여 초기화
Line* Object::Axis = new Line();

Object::Object()
{
}

Object::~Object()
{
}

void Object::Init()
{
    Position = Vector2(0.0f,0.0f);
    Scale = Vector2(1.0f,1.0f);
    Rotation = 0.0f; 
}

void Object::WorldUpdate()
{
    //크기 행렬
    D3DXMatrixScaling(&S, Scale.x
        , Scale.y, 0);
    //회전 행렬
    D3DXMatrixRotationZ(&R, Rotation);

    //이동행렬을 만드는함수
    D3DXMatrixTranslation(&T, Position.x
        , Position.y, 0);
    //최종행렬 만들기
    W = S * R* T;
}

void Object::Render()
{
    ////right
    //Axis->Position = Position;
    //Axis->Rotation = Rotation;
    //Axis->Scale.x = Scale.x;
    //Axis->WorldUpdate();
    //Axis->Render();
    ////up
    //Axis->Position = Position;
    //Axis->Rotation = Rotation + PI*0.5f;
    //Axis->Scale.x = Scale.y;
    //Axis->WorldUpdate();
    //Axis->Render();
}
