#include "vkSurfaceCreateInfo.h"

#ifdef WIN32
#include "vkWin32SurfaceCreateInfo.h"
#include "vkWindowWIN.h"
#endif

vk::SurfaceCreateInfoPtr vk::SurfaceCreateInfo::Create(WindowPtr window)
{
#ifdef WIN32
	WindowWINPtr windowWin32 = std::dynamic_pointer_cast<WindowWIN>(window);

	Win32SurfaceCreateInfoPtr createInfo(new Win32SurfaceCreateInfo(0x0, reinterpret_cast<HINSTANCE>(windowWin32->getOsInstanceHandle()), reinterpret_cast<HWND>(windowWin32->getWindowHandle())));
#endif

	return createInfo;
}
