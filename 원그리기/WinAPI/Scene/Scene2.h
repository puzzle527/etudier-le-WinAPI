#pragma once
class Scene2 : public Scene
{
private:
    SYSTEMTIME time;

    Line   Hour;
    Line   Min;
    Line   Sec;

public:
    HRESULT Init() override;//초기화
    void Release() override;//해제


    void Update() override;//갱신
    void LateUpdate() override;//늦은갱신
    void Render() override;//그리기
};

