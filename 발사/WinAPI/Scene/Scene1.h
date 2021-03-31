#pragma once
class Scene1 : public Scene
{
private:
    Circle* rc;
	Circle  ball;

	Rect*	rectangle;
	Rect	rectball;

	bool balltrue = false;
	bool rectballtrue = false;

public:
    HRESULT Init() override;//초기화
    void Release() override;//해제

    
    void Update() override;//갱신
    void LateUpdate() override;//늦은갱신
    void Render() override;//그리기
};

