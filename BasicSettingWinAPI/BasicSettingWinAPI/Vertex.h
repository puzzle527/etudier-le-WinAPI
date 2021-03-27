#include "stdafx.h"
#pragma once

namespace Vertex
{
	//점
	struct Point
	{
		int x;
		int y;
		Point()
		{

		}
		Point(int X, int Y)
		{
			x = X;
			y = Y;
		}
	};
	//선
	struct Line
	{
		Line()
		{

		}
		Point p1;
		Point p2;
		void render()
		{
			MoveToEx(g_hdc, p1.x, p1.y, NULL);
			LineTo(g_hdc, p2.x, p2.y);
		}

	};

	//삼각형
	struct Tri
	{
		Tri()
		{

		}
		Point p1;
		Point p2;
		Point p3;
		void render()
		{
			MoveToEx(g_hdc, p1.x, p1.y, NULL);
			LineTo(g_hdc, p2.x, p2.y);
			LineTo(g_hdc, p3.x, p3.y);
			LineTo(g_hdc, p1.x, p1.y);
		}
	};

	//사각형
	struct Rect
	{
		Point LT;   //왼쪽위
		Point RT;   //오른쪽위
		Point RB;   //오른쪽아래
		Point LB;   //왼쪽아래
		Rect()
		{

		}
		void render()
		{
			//시계방향
			MoveToEx(g_hdc, LT.x, LT.y, NULL);
			LineTo(g_hdc, RT.x, RT.y);
			LineTo(g_hdc, RB.x, RB.y);
			LineTo(g_hdc, LB.x, LB.y);
			LineTo(g_hdc, LT.x, LT.y);
		}
	};
}