#pragma once
//¼±
struct Line : public Object
{
    Line()
    {

    }
    Point p1;
    Point p2;
    void render()override;

};

