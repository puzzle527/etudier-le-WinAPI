#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일 winapi에서 제공되는게

#include <string>

using namespace std;

#include <windows.h>
#include <tchar.h> //제네릭 텍스트 매핑

#ifdef _MBCS
#define _tstring string

#else
#define _tstring wstring

#endif

// dx 라이브러리 추가
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dX10.h>
#include <d3dx10math.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

//typedef 다른 이름으로 타입정의
typedef D3DXVECTOR2 Vector2; //x,y
typedef D3DXVECTOR3 Vector3;//x,y,z
typedef D3DXVECTOR4 Vector4;//x,y,z,w
typedef D3DXMATRIX	Matrix;
typedef D3DXCOLOR	Color; //r g b a


#define PI          3.141592f //원주율
#define TORADIAN	0.017453f //pi/180 의값
#define	TODEGREE	57.295779f		//180/pi 의값


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
#include "Object/Vertex.h"
using namespace Vertex;
#include "Object/Object.h"
#include "Object/Line.h"
#include "Object/Rect.h"
#include "Object/Star.h"
#include "Object/Shape.h"