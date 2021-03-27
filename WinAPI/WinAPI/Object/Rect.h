#pragma once
//»ç°¢Çü
struct Rect : public Object
{
public:
    Vector2 rect[4];
    void init()override;
    void WorldUpdate()override;
    void render()override;
    
};

