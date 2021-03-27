#include "stdafx.h"
#include "Line.h"


void Line::render()
{
MoveToEx(g_hdc, round(p1.x), round(p1.y), NULL);
LineTo(g_hdc, round(p2.x), round(p2.y));
}