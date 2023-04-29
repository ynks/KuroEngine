#include <Windows.h>
#include <string>
#include <sstream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F') 
		{
			SetWindowText(hWnd, "F key");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "F key up");
		}
		break;
	case WM_CHAR:
		{
			static std::string title;
			title.push_back((char)wParam);
			SetWindowText(hWnd, title.c_str());
		}
		break;
	case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lParam);
			std::ostringstream oss;
			oss << "(" << pt.x << ", " << pt.y << ")";
			SetWindowText(hWnd, oss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{

	const auto ClassName = "kuroEngine";
	const auto WindowName = "Kuro Engine";
	const int WIDTH = 640;
	const int HEIGHT = 480;

	// Register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = ClassName;

	RegisterClassEx(&wc);

	// Create create window instance
	HWND kuroWindow = CreateWindowEx(
		0, ClassName, WindowName, 
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, WIDTH, HEIGHT,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(kuroWindow, SW_SHOW);

	// Message pump
	MSG msg;
	BOOL gResult;
 
	while((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0 )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1) 
	{
		return -1;
	}
	else
	{
		int wParamValue = static_cast<int>(msg.wParam);
		return wParamValue;
	}
}
