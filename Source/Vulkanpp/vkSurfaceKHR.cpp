#include "vkSurfaceKHR.h"
#include "vkSwapchainKHR.h"
#include <assert.h>

#ifdef WIN32
#include "vkWin32SurfaceCreateInfo.h"
#endif

vk::SurfaceKHR::SurfaceKHR(InstancePtr instance, SurfaceCreateInfoPtr createInfo, const VkAllocationCallbacks* callbacks) : _surface(nullptr), _instance(instance), _callbacks(callbacks)
{
#ifdef WIN32
    VkResult res = vkCreateWin32SurfaceKHR(instance->getRaw(), std::dynamic_pointer_cast<Win32SurfaceCreateInfo>(createInfo)->getRaw(), callbacks, &_surface);
#else
#endif
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::SurfaceKHR::~SurfaceKHR()
{
	if (_surface != nullptr)
	{
		vkDestroySurfaceKHR(_instance->getRaw(), _surface, _callbacks);
	}
}
