#include "framework.h"
#include "011.h"

#define swap(_a, _b) { int _c = _a; _a = _b; _b = _c; }

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

int blockOri[3][3] = {
	{ IMG_001, IMG_002, IMG_003},
	{ IMG_004, IMG_005, IMG_006},
	{ IMG_007, IMG_008, IMG_BLANK}
};

bool isPlaying = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//START_DEBUG_CONSOLE(); // 디버그용 콘솔

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY011, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow)) {
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY011));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	//STOP_DEBUG_CONSOLE();

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY011));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY011);
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

bool isClear() {
	for (int i = 0; i < sizeof(block) / sizeof(block[0]); i++) {
		for (int j = 0; j < sizeof(block[0]) / sizeof(block[0][0]); j++) {
			if (block[j][i] != blockOri[j][i]) {
				return false;
			}
		}
	}
	return true;
}

bool moveBlock(HWND hWnd, int blockX, int blockY, int nextX, int nextY) {
	if (!isPlaying) {
		return false;
	}

	if (!(0 <= nextX && nextX <= 2 && 0 <= nextY && nextX <= 2)) {
		return false;
	}

	if (block[nextY][nextX] == IMG_BLANK) {
		swap(block[blockY][blockX], block[nextY][nextX]);
	}

	InvalidateRect(hWnd, NULL, false);
	UpdateWindow(hWnd);

	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_LBUTTONDOWN:
	{
		if (!isPlaying) {
			break;
		}

		int curX = LOWORD(lParam);
		int curY = HIWORD(lParam);

		int blockX = curX / BLOCK_WIDTH;
		int blockY = curY / BLOCK_HEIGHT;

		moveBlock(hWnd, blockX, blockY, blockX - 1, blockY); // 상
		moveBlock(hWnd, blockX, blockY, blockX + 1, blockY); // 하
		moveBlock(hWnd, blockX, blockY, blockX, blockY - 1); // 좌
		moveBlock(hWnd, blockX, blockY, blockX, blockY + 1); // 우

		if (isClear()) {
			MessageBox(hWnd, L"게임을 클리어 하셨습니다!", L"알림", MB_OK);

			isPlaying = false;

			InvalidateRect(hWnd, NULL, false);
			UpdateWindow(hWnd);
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
			if (isPlaying && MessageBox(hWnd, L"다시 시작하시겠습니까?", L"알림", MB_YESNO) == IDNO) {
				break;
			}

			srand((unsigned int)time(NULL));
			int ranI, ranJ;
			for (int i = 0; i < sizeof(block) / sizeof(block[0]); i++) {
				for (int j = 0; j < sizeof(block[0]) / sizeof(block[0][0]); j++) {
					ranI = rand() % 3, ranJ = rand() % 3;
					swap(block[j][i], block[ranI][ranJ]);
				}
			}

			isPlaying = true;

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

		if (!isPlaying) {
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
