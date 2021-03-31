#pragma once
class Line; //클래스 전방선언(헤더내에서 타입만 쓸때)
class Object
{
protected:

    Matrix  T; //이동행렬
    Matrix  S; //크기행렬
    Matrix  R; //회전행렬(z축)

    Matrix  W; //월드행렬
public:
    static Line*   Axis;
    Vector2 Position;//위치값,원점
    Vector2 Scale; //크기
    float   Rotation;
    Object();
    virtual ~Object();
    virtual void Init();
    virtual void WorldUpdate();
    virtual void Render();
};

