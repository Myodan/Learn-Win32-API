#include "framework.h"
#include "윈도우API2D슈팅게임.h"

/* FreeType 라이브러리 헤더 */
#include "font/ft2build.h"
#include FT_FREETYPE_H

/* FreeType 라이브러리 추가 */
#pragma comment (lib, "font/release/freetype.lib")

#define MAX_LOADSTRING 100

HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//START_DEBUG_CONSOLE();

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_API2D, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow)) {
		return FALSE;
	}

	MSG msg;

	initGraphic(hWnd, 0, 0, BG_WIDTH, BG_HEIGHT);
	Time::initTime();
	Input::init();
	Random::init();
	SceneManager::init();

	while (true) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (!Application::isPlaying()) {
			break;
		}

		clear(0, 0, 0);

		Time::updateTime();
		Input::update();

		SceneManager::run();

		render();
	}

	//STOP_DEBUG_CONSOLE();

	exitGraphic();

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API2D));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance;

	RECT rt = { 0,0, BG_WIDTH, BG_HEIGHT };
	AdjustWindowRect(&rt, WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION, FALSE);

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int wndWidth = rt.right - rt.left;
	int wndHeight = rt.bottom - rt.top;

	int wndX = screenWidth / 2 - wndWidth / 2;
	int wndY = screenHeight / 2 - wndHeight / 2;

	hWnd = CreateWindowW(szWindowClass,
		szTitle,
		WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION,
		wndX,
		wndY,
		wndWidth,
		wndHeight,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	if (!hWnd) {
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEMOVE:
	{
		Input::mousePosition.x = LOWORD(lParam);
		Input::mousePosition.y = HIWORD(lParam);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		render();

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