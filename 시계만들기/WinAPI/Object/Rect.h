#pragma once
//»ï°¢Çü
struct Rect : public Object
{
public:
    Vector2 rect[4];
    void Init()override;
    void WorldUpdate()override;
    void Render()override;
};

