// 007.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "007.h"

#define MAX_LOADSTRING 126

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	srand((unsigned int)time(NULL));

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY007, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow)) {
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY007));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY007));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY007);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance;

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case IDM_TEST:
		{
			MessageBox(hWnd, L"테스트", L"Test", MB_OK);
		}
		break;
		case IDM_RECTANGLE:
		{
			HDC hdc = GetDC(hWnd);
			int x1 = rand() % 1000, y1 = rand() % 1000,
				x2 = rand() % 1000, y2 = rand() % 1000;
			WCHAR buffer[MAX_LOADSTRING];

			Rectangle(hdc, x1, y1, x2, y2);

			wsprintf(buffer, L"랜덤 생성 좌표: (%03d, %03d), (%03d, %03d)", x1, y1, x2, x2);
			TextOut(hdc, 16, 16 * 10, buffer, wcslen(buffer));

			ReleaseDC(hWnd, hdc);
		}
		break;
		case IDM_CIRCLE:
		{
			HDC hdc = GetDC(hWnd);
			int x1 = rand() % 1000, y1 = rand() % 1000,
				x2 = rand() % 1000, y2 = rand() % 1000;
			WCHAR buffer[MAX_LOADSTRING];

			Ellipse(hdc, x1, y1, x2, y2);

			wsprintf(buffer, L"랜덤 생성 좌표: (%03d, %03d), (%03d, %03d)", x1, y1, x2, x2);
			TextOut(hdc, 16, 16 * 10, buffer, wcslen(buffer));

			ReleaseDC(hWnd, hdc);
		}
		break;
		case IDM_ABOUT:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		}
		break;
		case IDM_EXIT:
		{
			DestroyWindow(hWnd);
		}
		break;

		default:
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		WCHAR buffer[MAX_LOADSTRING];

		// 1. 모니터 해상도 출력 - GetSystemMetrics
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		wsprintf(buffer, L"모니터 해상도: %d * %d", screenWidth, screenHeight);
		TextOut(hdc, 16, 16 * 1, buffer, wcslen(buffer));

		// 2. 현재 윈도우 크기 출력하기 - GetWindowRect
		RECT winRect;

		GetWindowRect(hWnd, &winRect);
		wsprintf(buffer, L"현재 창 좌표: (%d, %d, %d, %d)", winRect.left, winRect.top, winRect.right, winRect.bottom);
		TextOut(hdc, 16, 16 * 2, buffer, wcslen(buffer));
		wsprintf(buffer, L"현재 창 크기: %d * %d", winRect.right - winRect.left, winRect.bottom - winRect.top);
		TextOut(hdc, 16, 16 * 3, buffer, wcslen(buffer));

		// 3. 현재 윈도우 클라이언트(Client) 크기 구하기 - GetClientRect
		RECT clientRect;
		GetClientRect(hWnd, &clientRect);
		wsprintf(buffer, L"현재 창 클라이언트 영역 좌표: (%d, %d, %d, %d)", clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
		TextOut(hdc, 16, 16 * 4, buffer, wcslen(buffer));

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
