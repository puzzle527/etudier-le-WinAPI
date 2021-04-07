#pragma once
#include "stdafx.h"

//정점단위로 도형을이루면
//이동,확대 축소,회전표현이 가능하다


namespace Vertex
{
    //점(좌표)
    struct Point 
    {
        
        //실수 좌표계
        //부동소수점
        float x;
        float y;
        Point()
        {

        }
        Point(float a, float b)
        {
            x = a;
            y = b;
        }
    };

    ////삼각형
    //struct Tri
    //{
    //    Point p1;
    //    Point p2;
    //    Point p3;
    //    void render()
    //    {
    //        //이동위치에서 다음위치로 선긋기
    //        MoveToEx(g_hdc, (int)round(p1.x), (int)round(p1.y), NULL);
    //        LineTo(g_hdc,   (int)round(p2.x), (int)round(p2.y));
    //        LineTo(g_hdc,   (int)round(p3.x), (int)round(p3.y));
    //        LineTo(g_hdc,   (int)round(p1.x), (int)round(p1.y));
    //    }
    //};
    
}