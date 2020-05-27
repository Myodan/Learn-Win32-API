﻿#include "framework.h"
#include "010.h"

#define swap(a, b) {int temp = a; a = b; b = temp;}

#define MAX_LOADSTRING 100

#define IMG_WIDTH 681
#define IMG_HEIGHT 387

#define BLOCK_WIDTH 227
#define BLOCK_HEIGHT 129

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int block[3][3] = {
	{ IMG_001, IMG_002, IMG_003},
	{ IMG_004, IMG_005, IMG_006},
	{ IMG_007, IMG_008, IMG_BLANK}
};

bool isPlay = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	START_DEBUG_CONSOLE();
	printf("디버그를 시작합니다.\n");

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY010, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow)) {
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY010));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	STOP_DEBUG_CONSOLE();

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY010));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY010);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance;

	RECT clientRect = {0, 0, IMG_WIDTH, IMG_HEIGHT};
	AdjustWindowRect(&clientRect, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, true);

	HWND hWnd = CreateWindowW(
		szWindowClass,
		szTitle,
		WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT,
		0,
		clientRect.right - clientRect.left,
		clientRect.bottom - clientRect.top,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

bool moveBlock(HWND hWnd, LPARAM lParam) {
	if (!isPlay) {
		printf("플레이중이 아닙니다.\n");
		return false;
	}

	int mx = LOWORD(lParam);
	int my = HIWORD(lParam);

	int bx = mx / BLOCK_WIDTH;
	int by = my / BLOCK_HEIGHT;

	if (block[by - 1][bx] == IMG_BLANK) { //위
		swap(block[by][bx], block[by - 1][bx]);
	}
	else if (block[by + 1][bx] == IMG_BLANK) { //아래
		swap(block[by][bx], block[by + 1][bx]);
	}
	else if (block[by][bx + 1] == IMG_BLANK) { //우측
		swap(block[by][bx], block[by][bx + 1]);
	}
	else if (block[by][bx - 1] == IMG_BLANK) { //좌측
		swap(block[by][bx], block[by][bx - 1]);
	}
	else {
		return false;
	}

	InvalidateRect(hWnd, NULL, false);
	UpdateWindow(hWnd);
	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_LBUTTONDOWN:
	{
		if (moveBlock(hWnd, lParam)) {
			printf("블럭 이동 성공\n");
		}
		else {
			printf("블럭 이동 실패\n");
		}
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case IDM_ABOUT:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		}
		break;
		case IDM_START: 
		{
			srand((unsigned int)time(NULL));
			int temp, ranI, ranJ;
			for (int i = 0; i < sizeof(block) / sizeof(block[0]); i++) {
				for (int j = 0; j < sizeof(block[0]) / sizeof(block[0][0]); j++) {
					ranI = rand() % 3;
					ranJ = rand() % 3;
					temp = block[i][j];
					block[i][j] = block[ranI][ranJ];
					block[ranI][ranJ] = temp;
				}
			}

			isPlay = true;

			InvalidateRect(hWnd, NULL, true);
			UpdateWindow(hWnd);
		}
		break;
		case IDM_EXIT:
		{
			DestroyWindow(hWnd);
		}
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		if (!isPlay) {
			DrawBitmap(hInst, hdc, IMG_COMPLETE, 0, 0, IMG_WIDTH, IMG_HEIGHT);
			break;
		}

		for (int i = 0; i < sizeof(block) / sizeof(block[0]); i++) {
			for (int j = 0; j < sizeof(block[0]) / sizeof(block[0][0]); j++) {
				DrawBitmap(hInst, hdc, block[i][j], BLOCK_WIDTH * j, BLOCK_HEIGHT * i, BLOCK_WIDTH, BLOCK_HEIGHT);
			}
		}
		
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}