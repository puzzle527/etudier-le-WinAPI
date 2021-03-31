#pragma once
class Circle : public Object
{
public:
	Vector2 Vertex[360];
	void Init()override;
	void WorldUpdate()override;
	void Render()override;
};

