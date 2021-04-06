#include "stdafx.h"
#include "triangle.h"

triangle::triangle(Vector2 pivot)
{
	Vertex[0] = Vector2(0.0f, -0.5f) - pivot;
	Vertex[1] = Vector2(0.5f, 0.5f) - pivot;
	Vertex[2] = Vector2(-0.5f, 0.5f) - pivot;
}

triangle::~triangle()
{
}

void triangle::Init()
{
	Object::Init();
}

void triangle::WorldUpdate()
{
	Object::WorldUpdate();
}

void triangle::Render()
{
	Object::Render();
	Vector2 RenderVertex[3];
	for (int i = 0; i < 3; i++)
	{
		D3DXVec2TransformCoord(
			&RenderVertex[i], &Vertex[i], &W);
	}
	MoveToEx(g_MemDC, RenderVertex[0].x, RenderVertex[0].y, NULL);
	//이동위치에서 다음위치로 선긋기
	LineTo(g_MemDC, RenderVertex[1].x, RenderVertex[1].y);
	LineTo(g_MemDC, RenderVertex[2].x, RenderVertex[2].y);
	LineTo(g_MemDC, RenderVertex[0].x, RenderVertex[0].y);
}
