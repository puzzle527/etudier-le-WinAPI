#pragma once
class Star : public Object
{
public:
    Vector2 star[5];
    void init()override;
    void WorldUpdate()override;
    void render()override;
};

