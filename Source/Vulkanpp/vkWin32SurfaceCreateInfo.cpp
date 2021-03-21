#include "vkWin32SurfaceCreateInfo.h"
#include <assert.h>

vk::Win32SurfaceCreateInfo::Win32SurfaceCreateInfo(VkWin32SurfaceCreateFlagsKHR flags, HINSTANCE hinstance, HWND hwnd)
{
	assert(hinstance != nullptr);
	assert(hwnd != nullptr);

    _info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    _info.pNext = nullptr;
    _info.flags = flags;
    _info.hinstance = hinstance;
    _info.hwnd = hwnd;
}
