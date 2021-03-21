#pragma once

#include "vkSurfaceCreateInfo.h"
#include "vkInstance.h"

namespace vk
{

class SurfaceKHR
{
public:
	SurfaceKHR(InstancePtr instance, SurfaceCreateInfoPtr createInfo, const VkAllocationCallbacks* callbacks);

	virtual ~SurfaceKHR();

	VkSurfaceKHR getRaw(void) { return _surface; }

	const VkSurfaceKHR getRaw(void)	const { return _surface; }

protected:
	VkSurfaceKHR _surface;
	InstancePtr _instance;
	const VkAllocationCallbacks* _callbacks;
};

typedef std::shared_ptr<SurfaceKHR> SurfaceKHRPtr;

};

