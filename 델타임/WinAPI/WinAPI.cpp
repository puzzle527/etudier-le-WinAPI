#include "stdafx.h"
#include "MainGame.h"

//오늘 과제
//별찍기


//h: 리소스 핸들 (자원 관리자)
//g: 글로벌
//m: 멤버
//HWND 창핸들

// 전역 변수:
// 프로그램 관리자(프로그램의 시작주소)
HINSTANCE   g_hInst;
// 창 핸들
HWND        g_hwnd;
HDC         g_hdc;
HDC			g_MemDC;	//더블버퍼링용
Vector2     g_Mouse;
MainGame*   Mg;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//윈도우 창사이즈 설정
void SetWindowSize(int x, int y, int width, int height);

//진입함수
//_t 매크로 제네릭텍스트 매핑 tchar.h
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
    //윈도우 클래스
    WNDCLASS wc;
    
    //NULL값으로 시작주소부터 크기까지 초기화
    ZeroMemory(&wc, sizeof(WNDCLASS));

    //참조하지 않은 인자에 대해 경고를 표시하지 않는다
    UNREFERENCED_PARAMETER(lpCmdLine);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    //프로시져 넘기기 L(함수 포인터 변수) = R(함수 포인터)
    wc.lpfnWndProc = static_cast<WNDPROC>(WndProc);
    
    wc.hInstance = hInstance;
    //아이콘(프로그램 왼쪽위)
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    //윈도우창 활성화시에 마우스커서 모양
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    //윈도우창 바탕색
    wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
    wc.lpszClassName = _T("WINAPI");
    wc.lpszMenuName = nullptr;

    //	운영체제의 레지스터에 이 프로그램을 등록한다
    if (!RegisterClass(&wc))
        return FALSE; //등록이 안됬다면 프로그램 종료

     //생성된 인스턴스값 저장
    g_hInst = hInstance;

    //	메인 윈도우 생성
    g_hwnd = CreateWindow(
        _T("WINAPI"),
        _T("WINAPI"),
        WS_OVERLAPPEDWINDOW,
        WINSTARTX,			//창의 시작 x좌표
        WINSTARTY,			//창의 시작 y좌표
        WINSIZEX,		//창의 너비
        WINSIZEY,		//창의 높이
        nullptr,
        nullptr,
        hInstance,	//등록될 인스턴스
        nullptr
    );
    //핸들이 제대로 값을 가지지 못했다면 프로그램 종료
    if (!g_hwnd)
        return FALSE;

    //다른클래스에서는 호출 불가
    
    Mg = new MainGame();//할당
    Mg->Init();//초기화

    //화면 작업 사이즈 영역 계산
    SetWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

    //	생성한 프로그램을 디스플레이의 최상위로 올린다
    ShowWindow(g_hwnd, nCmdShow);

    //	메인 윈도우 갱신
    UpdateWindow(g_hwnd);

    //**메시지**
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));

    // 기본 메시지 루프입니다:
    //런타임동안 반복시킬 반복문
    while (true)
    {
        //GetMessage 발생한메세지를 줄때까지 계속 기다려서 받는애
        //Peek 발생할때만 집어서 가져오는애
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            TIMEMANAGER->SetFrame(FIXFRAME);
            //메세지를 집어오지 않을때
            Mg->Update();
            Mg->LateUpdate();
            PAINTSTRUCT ps;
            //hdc-> 도화지        어느창?
            g_hdc = BeginPaint(g_hwnd, &ps);//그리기시작
            Mg->Render();
            EndPaint(g_hwnd, &ps);//그리기 끝
        }
    }
    //프로그램 종료 준비
    Mg->Release(); //해제
    delete Mg; //소멸

     //생성된 윈도우 삭제
    DestroyWindow(g_hwnd);
    //등록된 프로그램 해제
    UnregisterClass(_T("WINAPI"), hInstance);

    return (int)msg.wParam;
}


void SetWindowSize(int x, int y, int width, int height)
{
    //화면크기에 맞는 렉트
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = width;
    rc.bottom = height;

    //실제 윈도우 크기 조정
    AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);
    //위 RECT 정보로 윈도우 사이즈 세팅
    SetWindowPos(g_hwnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top),
        SWP_NOZORDER | SWP_NOMOVE);
}

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //어떤 메세지가 발생되었는가를 통해 처리할 조건문
    switch (message)
    {
       
        case WM_MOUSEMOVE:
        {
            g_Mouse.x = (float)LOWORD(lParam);
            g_Mouse.y = (float)HIWORD(lParam);
            break;
        }
        //파괴하거나 닫으라는 메세지가 들어온경우
        case WM_DESTROY: case WM_CLOSE:
        {
            //프로그램 종료 호출 함수
            PostQuitMessage(0);
            break;
        }
        //아무키나 눌렀을때
        case WM_KEYDOWN:
        {
            // VK 버츄얼키 가상키
            if (wParam == VK_ESCAPE)
            {
                //프로그램 종료 호출 함수
                PostQuitMessage(0);
            }
            break;
        }
    }

    return (DefWindowProc(hWnd, message, wParam, lParam));
}


// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
