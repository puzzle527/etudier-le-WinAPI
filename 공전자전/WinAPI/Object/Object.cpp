#include "stdafx.h"
#include "Object.h"

//정적멤버는 cpp 전역에서 호출하여 초기화
Line* Object::Axis = new Line();

Object::Object()
{
    P = nullptr;
}

Object::~Object()
{
}

void Object::Init()
{
    Position = Vector2(0.0f,0.0f);
    Scale = Vector2(1.0f,1.0f);
    Rotation = 0.0f; 
    Right = Vector2(1.0f,0.0f);
    Up = Vector2(0.0f,1.0f);
   
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
    W = S * R * T;
    //회전 이동행렬 만들기
    RT = R * T;

    if(P)//부모행렬의주소값이 있을때
    {//                   child   rc
        W *= *P; // W = S *R* T * R*T;
        RT *= *P;// RT= R*T*R*T;
    }
    //(cos sin) Right, (sin cos) Up
    Right = Vector2(RT._11, RT._12);
    Up = Vector2(RT._21, RT._22);
    
    //D3DXVec2TransformCoord(
    //    &Right, &Right, &R);
    //// Right = Right * R;

    //D3DXVec2TransformCoord(
    //    &Up, &Up, &R);
}

void Object::Render()
{
    if(isAxis)
    {
        //right
        Axis->Position = Vector2(W._41, W._42);
        Axis->Rotation = DirToRadian(Right);
        Axis->Scale.x = Scale.x;
        Axis->WorldUpdate();
        Axis->Render();
        //up
        Axis->Position = Vector2(W._41, W._42);
        Axis->Rotation = DirToRadian(Up);
        Axis->Scale.x = Scale.y;
        Axis->WorldUpdate();
        Axis->Render();
    }
    
}
