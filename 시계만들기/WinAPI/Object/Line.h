#pragma once
//¼±
struct Line : public Object
{
public:
    Vector2 Vertex[2];
    void Init()override;
    void WorldUpdate()override;
    void Render()override;
};


