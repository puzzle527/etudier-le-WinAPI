#include "stdafx.h"
#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::init()
{
}

void Object::WorldUpdate()
{
    D3DXMatrixTranslation(
        &T, Position.x, Position.y, 0);
    //   만들행렬, Tx,     Ty,      Tz

    D3DXMatrixScaling(
        &S, Scale.x, Scale.y, 0);

    D3DXMatrixRotationZ(
        &R, Rotation);

    W = S * R * T;
}

void Object::render()
{
}
