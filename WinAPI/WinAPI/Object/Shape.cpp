#include "stdafx.h"
#include "Shape.h"

void Shape::init()
{
	for (int i = 0; i < 10; i++)
	{
		shape[i].x =
			cos((36 * i)*TORADIAN);
		shape[i].y =
			-sin((36 * i)*TORADIAN);
	}
}

void Shape::WorldUpdate()
{
	Object::WorldUpdate();
}

void Shape::render()
{
	Vector2 RenderVertex[10];

	for (int i = 0; i < 10; i++)
	{
		D3DXVec2TransformCoord(&RenderVertex[i], &shape[i], &W);
	}
	MoveToEx(g_hdc, RenderVertex[0].x, RenderVertex[0].y, NULL);

	LineTo(g_hdc, RenderVertex[4].x, RenderVertex[4].y);
	LineTo(g_hdc, RenderVertex[8].x, RenderVertex[8].y);
	LineTo(g_hdc, RenderVertex[2].x, RenderVertex[2].y);
	LineTo(g_hdc, RenderVertex[6].x, RenderVertex[6].y);
	LineTo(g_hdc, RenderVertex[0].x, RenderVertex[0].y);

	MoveToEx(g_hdc, RenderVertex[1].x, RenderVertex[1].y, NULL);

	LineTo(g_hdc, RenderVertex[5].x, RenderVertex[5].y);
	LineTo(g_hdc, RenderVertex[9].x, RenderVertex[9].y);
	LineTo(g_hdc, RenderVertex[3].x, RenderVertex[3].y);
	LineTo(g_hdc, RenderVertex[7].x, RenderVertex[7].y);
	LineTo(g_hdc, RenderVertex[1].x, RenderVertex[1].y);
}
