#pragma once
class Circle : public Object
{
private:
    int Slice;
    Vector2* RenderVertex;
public:
    Circle(int slice = 36,
        Vector2 pivot = Vector2(0.0f, 0.0f));
    ~Circle();
    Vector2* Vertex;
    void Init()override;
    void WorldUpdate()override;
    void Render()override;
};

