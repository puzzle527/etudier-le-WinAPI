#include "stdafx.h"

//해상도: 가로x세로 픽셀

//윈도우 메시지: WM_ 
//보통 이벤트같은거를 메시지를 발생
//키다운,생성CREATE,삭제DESTORY,

//메시지 큐: 발생된 윈도우메시지를 담아놓는곳
//보통 먼저발생된 메시지가 처리되지만
//우선순위따라 정렬된다.

//메시지 루프:프로그램 실행중에
//os에서 담아논 메시지를 계속 받아오는게


//윈도우 프로시저(프록스):



//표기법
//카멜식 표기법: 강조하고싶은 앞에 대문자
//헝가리안 표기법: 접두어를 붙이는 표기법

//h: 리소스 핸들 (자원 관리자)
//g: 글로벌
//m: 멤버
//HWND 창핸들

// 전역 변수:
// 프로그램 관리자(프로그램의 시작주소)
HINSTANCE   g_hInst;
// 창 핸들
HWND        g_hwnd;

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
    //운영체제가 호출
    //wc.lpfnWndProc(g_hwnd,1,1,1);

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
            //메세지를 집어오지 않을때

        }
    }
    //프로그램 종료 준비

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
int x = 130;
int y = 200;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //어떤 메세지가 발생되었는가를 통해 처리할 조건문
    switch (message)
    {
        //그리라는 메세지가 들어온경우
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            //hdc-> 도화지        어느창?
            HDC hdc = BeginPaint(hWnd, &ps);//그리기시작

            //그리기
            //직사각형  도화지,l,t,r,b(위치)
            //윈도우 해상도내의 좌표
            //픽셀과 1:1 대응좌표
            //**정수값**

            //gdi 함수 (예전에 많이썻지만 지금은 잘 안쓰인다)
            //Rectangle(hdc,0,100,400,200);
            //타원
            //Ellipse(hdc, 0, 300, 400, 500);

            //선
            //그려줄 위치로 이동
            MoveToEx(hdc,130,200,NULL);
            //이동위치에서 다음위치로 선긋기
			//김
            LineTo(hdc, x + 50, y);
            LineTo(hdc, x + 50, y + 100);
			MoveToEx(hdc, x + 120, y, NULL);
			LineTo(hdc, x + 120, y + 100);
			Rectangle(hdc, x + 50, y + 150, x + 120, y + 250);
			//성
			MoveToEx(hdc, x + 220, y, NULL);
			LineTo(hdc, x + 170, y + 100);
			MoveToEx(hdc, x + 195, y + 50, NULL);
			LineTo(hdc, x + 245, y + 100);
			MoveToEx(hdc, x + 245, y + 50, NULL);
			LineTo(hdc, x + 290, y + 50);
			MoveToEx(hdc, x + 290, y, NULL);
			LineTo(hdc, x + 290, y + 100);
			Ellipse(hdc, x + 220, y + 150, x + 300, y + 250);
			//훈
			MoveToEx(hdc, x + 410, y, NULL);
			LineTo(hdc, x + 430, y);
			MoveToEx(hdc, x + 380, y + 10, NULL);
			LineTo(hdc, x + 460, y + 10);
			Ellipse(hdc, x + 380, y + 20, x + 460, y + 120);
			MoveToEx(hdc, x + 360, y + 140, NULL);
			LineTo(hdc, x + 480, y + 140);
			MoveToEx(hdc, x + 420, y + 140, NULL);
			LineTo(hdc, x + 420, y + 200);
			MoveToEx(hdc, x + 460, y + 250, NULL);
			LineTo(hdc, x + 380, y + 250);
			LineTo(hdc, x + 380, y + 200);

            EndPaint(hWnd, &ps);//그리기 끝
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
            if (wParam == VK_LEFT)
            {
                x -= 3;
                //WM_PAINT 발생시키는 함수 /지울까?
                InvalidateRect(hWnd,NULL,false);
            }
            if (wParam == VK_RIGHT)
            {
                x+=3;
                //WM_PAINT 발생시키는 함수
                InvalidateRect(hWnd, NULL, true);
            }

            break;
        }




        //마우스 왼쪽클릭 메세지가 들어온경우
        case WM_LBUTTONDOWN:
        {
            //메세지 박스
            MessageBox
            (
                g_hwnd,//어느윈도우에
                _T("내가 메세지 박스다"),
                _T("난 이름"),
                MB_OK
            );
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
