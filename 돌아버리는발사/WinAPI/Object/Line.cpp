#include "stdafx.h"
#include "Line.h"

void Line::Init()
{
    Object::Init();
    //0도를 향하는 선
    Vertex[0] = Vector2(0.0f,0.0f);
    Vertex[1] = Vector2(1.0f, 0.0f);
}

void Line::WorldUpdate()
{
    Object::WorldUpdate();
}

void Line::Render()
{

    Vector2 RenderVertex[2];
    for(int i = 0; i < 2; i++)
    {
        //L->W
        //벡터와 행렬의 곱연산을 해주는 함수
        D3DXVec2TransformCoord(
            &RenderVertex[i], &Vertex[i], &W);
    }
    MoveToEx(g_MemDC, RenderVertex[0].x, RenderVertex[0].y, NULL);
    //이동위치에서 다음위치로 선긋기
    LineTo(g_MemDC, RenderVertex[1].x, RenderVertex[1].y);
}