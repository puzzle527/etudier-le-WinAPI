#include "stdafx.h"
#include "Circle.h"

Circle::Circle(int slice, Vector2 pivot)
{
    Slice = slice;
    Vertex = new Vector2[slice];
    RenderVertex = new Vector2[slice];

    for(int i = 0; i < slice; i++)
    {
        //                   position   + cos(72*i) * c
        //                            cos(72*i)
        Vertex[i] = Vector2(cos((360.0f / slice * i) * TORADIAN)*0.5f,
            -sin((360.0f / slice * i) * TORADIAN)*0.5f) - pivot;
    }

}

Circle::~Circle()
{
    delete Vertex;
    delete RenderVertex;
}

void Circle::Init()
{
    Object::Init();
}

void Circle::WorldUpdate()
{
    //재정의된 스타로 호출될때
 //부모함수도 호출
    Object::WorldUpdate();
}

void Circle::Render()
{
    Object::Render();
   
    for(int i = 0; i < Slice; i++)
    {
        //L->W
        //벡터와 행렬의 곱연산을 해주는 함수
        D3DXVec2TransformCoord(
            &RenderVertex[i], &Vertex[i], &W);
    }
    MoveToEx(g_MemDC, RenderVertex[0].x, RenderVertex[0].y, NULL);
    //이동위치에서 다음위치로 선긋기
    for(int i = 1; i < Slice; i++)
    {
        LineTo(g_MemDC, RenderVertex[i].x, RenderVertex[i].y);
    }
    LineTo(g_MemDC, RenderVertex[0].x, RenderVertex[0].y);
}
