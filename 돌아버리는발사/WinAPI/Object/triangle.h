#pragma once
class triangle : public Object
{
public:
	triangle(Vector2 pivot = Vector2(0.0f, 0.0f));
	~triangle();
	Vector2 Vertex[3];
	void Init()override;
	void WorldUpdate()override;
	void Render()override;
};

