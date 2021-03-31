#pragma once
//삼각형
struct Rect : public Object
{
public:
    //원하는 중심점으로 찍을수있게
    Rect(Vector2 pivot = Vector2(0.0f,0.0f));
    Vector2 Vertex[4];
    void Init()override;
    void WorldUpdate()override;
    void Render()override;
};

