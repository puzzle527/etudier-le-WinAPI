#include "stdafx.h"
#include "Circle.h"

void Circle::Init()
{
	for (int i = 0; i < 360; i++)
	{
		Vertex[i] = Vector2(cos((1.0f * i) * TORADIAN),
			-sin((1.0f * i) * TORADIAN));
	}
	Object::Init();
}

void Circle::WorldUpdate()
{
	Object::WorldUpdate();
}

void Circle::Render()
{
	Object::Render();
	Vector2 RenderVertex[360];
	for (int i = 0; i < 360; i++)
	{
		D3DXVec2TransformCoord(
			&RenderVertex[i], &Vertex[i], &W);
	}
	MoveToEx(g_hdc, RenderVertex[0].x, RenderVertex[0].y, NULL);

	for (int i = 0; i < 359; i++)
	{
		LineTo(g_hdc, RenderVertex[i+1].x, RenderVertex[i+1].y);
	}
	LineTo(g_hdc, RenderVertex[0].x, RenderVertex[0].y);
}
