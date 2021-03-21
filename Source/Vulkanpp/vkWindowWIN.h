#pragma once
#include "vkWindow.h"
#include <Windows.h>
#include <memory>

namespace vk
{

class WindowWIN : public Window
{
public:
	WindowWIN(const std::wstring& name, const std::wstring& title, const int32_t posX, const int32_t posY, const uint32_t width, const uint32_t height);

	virtual ~WindowWIN();

	virtual std::uintptr_t getWindowHandle(void) const override;

	virtual std::uintptr_t getOsInstanceHandle(void) const override;
protected:
	// MS-Windows event handling function:
	static LRESULT CALLBACK EventHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HWND _windowHandle;
	HINSTANCE _osInstance;
};
typedef std::shared_ptr<WindowWIN> WindowWINPtr;

};
