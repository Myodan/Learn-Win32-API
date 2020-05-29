#include "DrawBitmap.h"

void DrawBitmap(HINSTANCE hInst, HDC hdc, int bitmapID, int x, int y, int cx, int cy) {
	// 비트맵 이미지 불러오기 - LoadBitmap
	HBITMAP myBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(bitmapID));

	// 내부 메모리 완성 공간(메모리 DC) 만들기 - CreateCompatibleDC
	HDC memDC = CreateCompatibleDC(hdc);

	// 메모리 DC에 비트맵 출력하기 - SelectObject
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);

	// 메모리 DC를 화면으로 출력하기 - BitBlt
	BitBlt(hdc, x, y, cx, cy, memDC, 0, 0, SRCCOPY);

	// 메모리 DC에 불러온 비트맵 해제하기(복구) - SelectObject
	SelectObject(memDC, oldBitmap);

	// 불러온 비트맵 파일 제거하기 - DeleteObject
	DeleteObject(myBitmap);

	// 메모리 DC 삭제하기 - DeleteDC
	DeleteDC(memDC);
}