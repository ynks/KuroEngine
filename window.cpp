#include <Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{

	const auto ClassName = L"kuroEngine";
	const auto WindowName = L"Kuro Engine";
	const int WIDTH = 640;
	const int HEIGHT = 480;

	// Register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
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

	while (true);

	return 0;
}