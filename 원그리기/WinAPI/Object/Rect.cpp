#include "stdafx.h"
#include "Rect.h"

Rect::Rect(Vector2 pivot)
{
    //local
    Vertex[0] = Vector2(-0.5f, 0.5f) - pivot;
    Vertex[1] = Vector2(0.5f, 0.5f) - pivot;
    Vertex[2] = Vector2(0.5f, -0.5f) - pivot;
    Vertex[3] = Vector2(-0.5f, -0.5f) - pivot;
}

void Rect::Init()
{
    Object::Init();
    
}

void Rect::WorldUpdate()
{
    //재정의된 스타로 호출될때
   //부모함수도 호출
    Object::WorldUpdate();

}

void Rect::Render()
{
    Object::Render();
    Vector2 RenderVertex[4];
    for(int i = 0; i < 4; i++)
    {
        //L->W
        //벡터와 행렬의 곱연산을 해주는 함수
        D3DXVec2TransformCoord(
            &RenderVertex[i], &Vertex[i], &W);
    }
    MoveToEx(g_hdc, RenderVertex[0].x, RenderVertex[0].y, NULL);
    //이동위치에서 다음위치로 선긋기
    LineTo(g_hdc, RenderVertex[1].x, RenderVertex[1].y);
    LineTo(g_hdc, RenderVertex[2].x, RenderVertex[2].y);
    LineTo(g_hdc, RenderVertex[3].x, RenderVertex[3].y);
    LineTo(g_hdc, RenderVertex[0].x, RenderVertex[0].y);
}