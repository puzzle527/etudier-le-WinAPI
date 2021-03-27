#pragma once
class Shape : public Object
{
public:
	Vector2 shape[10];

	void init() override;
	void WorldUpdate() override;
	void render() override;
};

