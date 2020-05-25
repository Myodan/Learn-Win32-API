#include "DrawBitmap.h"

void DrawBitmap(HINSTANCE hInst, HDC hdc, int bitmapID, int x, int y, int cx, int cy) {
	// ��Ʈ�� �̹��� �ҷ����� - LoadBitmap
	HBITMAP myBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(bitmapID));

	// ���� �޸� �ϼ� ����(�޸� DC) ����� - CreateCompatibleDC
	HDC memDC = CreateCompatibleDC(hdc);

	// �޸� DC�� ��Ʈ�� ����ϱ� - SelectObject
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, myBitmap);

	// �޸� DC�� ȭ������ ����ϱ� - BitBlt
	BitBlt(hdc, x, y, cx, cy, memDC, 0, 0, SRCCOPY);

	// �޸� DC�� �ҷ��� ��Ʈ�� �����ϱ�(����) - SelectObject
	SelectObject(memDC, oldBitmap);

	// �ҷ��� ��Ʈ�� ���� �����ϱ� - DeleteObject
	DeleteObject(myBitmap);

	// �޸� DC �����ϱ� - DeleteDC
	DeleteDC(memDC);
}