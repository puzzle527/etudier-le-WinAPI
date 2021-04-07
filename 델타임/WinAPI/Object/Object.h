#pragma once
class Line; //클래스 전방선언(헤더내에서 타입만 쓸때)
class Object
{
protected:

    Matrix  T; //이동행렬
    Matrix  S; //크기행렬
    Matrix  R; //자전 회전행렬(z축)
    Matrix  R2; //공전 회전행렬(z축)

    Matrix  W; //월드행렬
   
public:
    Matrix* P; //부모행렬
    Matrix RT; //회전이동행렬
    static Line*   Axis;
    bool isAxis = false; //원점을기준으로 축을그릴까?
    Vector2 Position;//원점(부모)으로부터 위치값 로컬포지션
    Vector2 Scale; //크기
    float   Rotation;
    float   Rotation2;
    Vector2 Up;     //y축방향
    Vector2 Right;  //x축방향
    Object();
    virtual ~Object();
    virtual void Init();
    virtual void WorldUpdate();
    virtual void Render();
};

