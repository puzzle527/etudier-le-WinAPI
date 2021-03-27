#pragma once
class Object
{
protected:
    Matrix T;//이동행렬
    Matrix S;//크기행렬
    Matrix R;//회전행렬

    Matrix W;//최종행렬
public:
    Vector2 Position; //별의 원점,위치값
    Vector2  Scale;    //반지름크기, 원점에서 멀어진 값
    float Rotation; //원점을기준으로 멀어진거리에서 원을잡고 회전한 각도값

   
    Object();
    virtual ~Object();
    virtual void init();
    virtual void WorldUpdate();
    virtual void render();
};

