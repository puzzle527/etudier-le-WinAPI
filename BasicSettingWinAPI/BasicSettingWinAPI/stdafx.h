#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일

#include <string>

using namespace std;

#include <windows.h>
#include <tchar.h> //제네릭 텍스트 매핑

#ifdef _MBCS
#define _tstring string

#else
#define _tstring wstring

#endif

//해상도 관련
//창 시작좌표
#define     WINSTARTX 0
#define     WINSTARTY 0

//창 너비,높이 (디스플레이크기,해상도에따라 변경된다)
#define     WINSIZEX 800
#define     WINSIZEY 600

//프로그램 이름
#define     WINDOWNAME _T("WINAPI") 

extern HDC          g_hdc;
extern HWND		    g_hwnd;

//포함파일
#include "Vertex.h"
using namespace Vertex;