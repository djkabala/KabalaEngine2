#pragma once

#include <Windows.h>
#include <vulkan/vulkan.h>
#include "vkSurfaceCreateInfo.h"
#include <memory>

namespace vk
{

class Win32SurfaceCreateInfo : public SurfaceCreateInfo
{
public:
	Win32SurfaceCreateInfo(VkWin32SurfaceCreateFlagsKHR flags, HINSTANCE hinstance, HWND hwnd);

	VkWin32SurfaceCreateInfoKHR* getRaw(void) { return &_info; }

	const VkWin32SurfaceCreateInfoKHR* getRaw(void) const { return &_info; }
protected:
	VkWin32SurfaceCreateInfoKHR _info;
};

typedef std::shared_ptr<Win32SurfaceCreateInfo> Win32SurfaceCreateInfoPtr;

};

