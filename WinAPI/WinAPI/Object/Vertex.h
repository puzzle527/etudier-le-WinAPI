#include "stdafx.h"
#pragma once

//»ï°¢ÇÔ¼ö
//cos ,sin ,tan


namespace Vertex
{
    //Á¡(ÁÂÇ¥)
    //½Ç¼ö ÁÂÇ¥
    struct Point
    {
        float x;
        float y;
        Point()
        {

        }
        Point(float X, float Y)
        {
            x = X;
            y = Y;
        }
    };
    

    //»ï°¢Çü
    /*struct Tri
    {
        Tri()
        {

        }
        Point p1;
        Point p2;
        Point p3;
        void render()
        {
            MoveToEx(g_hdc, round(p1.x), round(p1.y), NULL);
            LineTo(g_hdc,   round(p2.x), round(p2.y));
            LineTo(g_hdc,   round(p3.x), round(p3.y));
            LineTo(g_hdc,   round(p1.x), round(p1.y));
        }
    };*/

   
}