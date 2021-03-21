#include "vkWindowWIN.h"

vk::WindowWIN::WindowWIN(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height) :
    Window(name, title, posX, posY, width, height),
	_windowHandle(nullptr)
{
    WNDCLASSEX win_class;

    _osInstance = GetModuleHandle(NULL);

    // Initialize the window class structure:
    win_class.cbSize = sizeof(WNDCLASSEX);
    win_class.style = CS_HREDRAW | CS_VREDRAW;
    win_class.lpfnWndProc = EventHandler;
    win_class.cbClsExtra = 0;
    win_class.cbWndExtra = 0;
    win_class.hInstance = _osInstance;  // hInstance
    win_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    win_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    win_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    win_class.lpszMenuName = NULL;
    win_class.lpszClassName = name.c_str();
    win_class.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

    // Register window class:
    if (!RegisterClassEx(&win_class))
    {
        // It didn't work, so try to give a useful error:
        printf("Unexpected error trying to start the application!\n");
        fflush(stdout);
        exit(1);
    }
    // Create window with the registered class:
    RECT wr = {0, 0, width, height};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    _windowHandle = CreateWindowEx(0,
                                 name.c_str(),             // class name
                                 name.c_str(),             // app name
                                 WS_OVERLAPPEDWINDOW |  // window style
                                     WS_VISIBLE | WS_SYSMENU,
                                 posX, posY,            // x/y coords
                                 wr.right - wr.left,  // width
                                 wr.bottom - wr.top,  // height
                                 NULL,                // handle to parent
                                 NULL,                // handle to menu
                                 _osInstance,     // hInstance
                                 NULL);               // no extra parameters
    if (!_windowHandle)
    {
        // It didn't work, so try to give a useful error:
        printf("Cannot create a window in which to draw!\n");
        fflush(stdout);
        exit(1);
    }
    
    //LONG_PTR windowLongPtr;
    //SetWindowLongPtr(_windowHandle, GWLP_USERDATA, (LONG_PTR)&windowLongPtr);
}

vk::WindowWIN::~WindowWIN()
{
    if (_windowHandle != nullptr)
    {
        CloseWindow(_windowHandle);
    }
}

LRESULT CALLBACK vk::WindowWIN::EventHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// MS-Windows event handling function:
	//struct sample_info *info = reinterpret_cast<struct sample_info *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	switch (uMsg)
    {
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		//case WM_PAINT:
			//run(info);
			//return 0;
		default:
			break;
	}
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

std::uintptr_t vk::WindowWIN::getWindowHandle(void) const
{
    return reinterpret_cast<std::uintptr_t>(_windowHandle);
}

std::uintptr_t vk::WindowWIN::getOsInstanceHandle(void) const
{
    return reinterpret_cast<std::uintptr_t>(_osInstance);
}
