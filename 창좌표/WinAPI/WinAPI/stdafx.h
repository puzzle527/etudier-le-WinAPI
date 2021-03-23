#pragma once
#include "targetver.h"
// 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define WIN32_LEAN_AND_MEAN 
// Windows 헤더 파일
//WinAPI 포함
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <tchar.h> //제네릭 텍스트 매핑
//멀티바이트 유니코드 스위치

//문자집합 정리
//싱글바이트
//멀티바이트
//유니코드

//해상도 관련
//창 시작좌표
#define     WINSTARTX 0
#define     WINSTARTY 0

//창 너비,높이 (디스플레이크기,해상도에따라 변경된다)
#define     WINSIZEX 800
#define     WINSIZEY 600