#include "stdafx.h"
#include "Star.h"

void Star::init()
{
    //L (모델스페이스)
    //정점들이 얼마나 떨어져있고
    //몇개인지
    for(int i = 0; i < 5; i++)
    {
        star[i].x =
            cos((72 * i)*TORADIAN);
        star[i].y =
            -sin((72 * i)*TORADIAN);
    }
}

void Star::WorldUpdate()
{
    //자식객체에서 부모함수 호출
    Object::WorldUpdate();

    //int a =0;
}

void Star::render()
{

    Vector2 RenderVertex[5];
    for(int i = 0; i < 5; i++)
    {
        //행렬과 벡터를 곱해주는함수
        // x,y,0,1 * M
        D3DXVec2TransformCoord(
            &RenderVertex[i], &star[i], &W);
        // RenderVertex   =포지션빠진정점* 이동값
    }
    MoveToEx(g_hdc, RenderVertex[0].x, RenderVertex[0].y, NULL);

    LineTo(g_hdc, RenderVertex[2].x, RenderVertex[2].y);
    LineTo(g_hdc, RenderVertex[4].x, RenderVertex[4].y);
    LineTo(g_hdc, RenderVertex[1].x, RenderVertex[1].y);
    LineTo(g_hdc, RenderVertex[3].x, RenderVertex[3].y);
    LineTo(g_hdc, RenderVertex[0].x, RenderVertex[0].y);

}
