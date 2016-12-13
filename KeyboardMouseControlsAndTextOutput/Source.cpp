#define WIN32_LEAN_AND_MEAN
#include <windows.h> // Include all the Windows headers.
#include <windowsx.h> // Include useful macros.
#include <strstream>
#include <string>
#include <cmath>

#include "resource.h"

using namespace std;

#define WINDOW_CLASS_NAME L"WINCLASS1"

HINSTANCE g_hInstance;
const RECT* g_prect;
POINT g_pos;
int g_iMouseX;
int g_iMouseY;

bool IS_LEFT_PRESSED  = 0;
bool IS_RIGHT_PRESSED = 0;
bool IS_UP_PRESSED    = 0;
bool IS_DOWN_PRESSED  = 0;

bool IS_LMB_PRESSED = 0;
bool IS_RMB_PRESSED = 0;
bool IS_MMB_PRESSED = 0;

int LAST_KEYPRESS_ASCII = 0;

float ang = 0.0f;

template<typename T>
string ToString(const T& _value)
{
	strstream theStream;
	theStream << _value << ends;
	return (theStream.str());
}

// Game Loop
void GameLoop()
{
	ang += 0.0005f;
	// One frame of game logic goes here
}

// Event handling (window handle, message handle, ...
LRESULT CALLBACK WindowProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT
	HDC hdc; // Handle to a device context

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
		IS_LEFT_PRESSED = TRUE; else IS_LEFT_PRESSED = FALSE;

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
		IS_RIGHT_PRESSED = TRUE; else IS_RIGHT_PRESSED = FALSE;

	if ((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
		IS_UP_PRESSED = TRUE; else IS_UP_PRESSED = FALSE;

	if ((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000)
		IS_DOWN_PRESSED = TRUE; else IS_DOWN_PRESSED = FALSE;

	// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		// Return success
		return(0);
	}
	break;
	case WM_PAINT:
	{
		// Simple validate the window
		hdc = BeginPaint(_hwnd, &ps);
		InvalidateRect(_hwnd, g_prect, FALSE);

		string temp;
		int iYDrawPos = 15;
		int iXDrawPos = 30;
		COLORREF red = RGB(255, 0, 0);
		SetTextColor(hdc, red);
		LPCWSTR a;

		temp = "MOUSE X: ";
		temp += ToString((g_pos.x));
		while (temp.size() < 14)
		{
			temp += " ";
		}
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(temp.begin(), temp.end()).c_str(), static_cast<int>(temp.size()));
		iYDrawPos += 13;

		temp = "MOUSE Y: ";
		temp += ToString((g_pos.y));
		while (temp.size() < 14)
		{
			temp += " ";
		}
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(temp.begin(), temp.end()).c_str(), static_cast<int>(temp.size()));
		iYDrawPos += 13;

		string text = "";
		if (IS_LEFT_PRESSED == TRUE) text = "LEFT IS PRESSED"; else text = "LEFT IS NOT PRESSED";
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(text.begin(), text.end()).c_str(), text.length());
		iYDrawPos += 13;

		if (IS_RIGHT_PRESSED == TRUE) text = "RIGHT IS PRESSED"; else text = "RIGHT IS NOT PRESSED";
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(text.begin(), text.end()).c_str(), text.length());
		iYDrawPos += 13;

		if (IS_DOWN_PRESSED == TRUE) text = "DOWN IS PRESSED"; else text = "DOWN IS NOT PRESSED";
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(text.begin(), text.end()).c_str(), text.length());
		iYDrawPos += 13;

		if (IS_UP_PRESSED == TRUE) text = "UP IS PRESSED"; else text = "UP IS NOT PRESSED";
		TextOut(hdc, iXDrawPos, iYDrawPos, wstring(text.begin(), text.end()).c_str(), text.length());

		TextOut(hdc, static_cast<int>(200 + (sin(ang) * 200)), static_cast<int>(200 + (sin(ang) * 200)), L"O", 1);

		EndPaint(_hwnd, &ps);

		// Return success
		return(0);
	}
	break;
	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return(0);
	}
	break;

	case WM_MOUSEMOVE:
	{
		GetCursorPos(&g_pos);
		// Here is your coordinates
		int x = g_pos.x;
		int y = g_pos.y;
		return(0);
	}
	break;
	case WM_COMMAND:
	{

	}
	default:
		break;
	} // End switch

	// Process any messages we didn't take care of...
	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create
	HWND hwnd; // Generic window handle
	MSG msg; // Generic message.

	g_hInstance = _hInstance;

	// First fill in the window class structure
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
	winclass.hCursor = NULL;
	winclass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));

	// Register the window class
	if (!RegisterClassEx(&winclass))
	{
		// Perhaps use log manager here
		return(0);
	}

	// Create the window
	if (!(hwnd = CreateWindowEx(
		NULL, // Extended style
		WINDOW_CLASS_NAME, // Class
		L"Recipe 4", // Title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		400, 300, // Initial X, Y
		400, 400, // Initial width, height
		NULL, // Handle to parent
		NULL, // Handle to menu
		_hInstance, // Instance of this application
		NULL))) // Extra creation parameters
	{
		return(0);
	}

	RECT rect;
	rect.left = 0;
	rect.right = 400;
	rect.top = 0;
	rect.bottom = 400;
	g_prect = &rect;

	// Enter main event loop
	while (TRUE)
	{
		// Test if there is a message in queue, if so get it
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit
			if (msg.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelator keys
			TranslateMessage(&msg);

			// Send the message to the window proc
			DispatchMessage(&msg);
		}

		// Main game processing goes here
		GameLoop(); // One frame of game logic goes here...
	}
	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));

}