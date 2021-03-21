#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkFenceCreateInfo.h"
#include "vkDevice.h"

namespace vk
{

class Fence
{
public:
	Fence(DevicePtr device, FenceCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~Fence();

    VkFence getRaw(void)
    {
        return _fence;
    }

    const VkFence getRaw(void) const
    {
        return _fence;
    }

protected:
	VkFence _fence;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<Fence> FencePtr; 

};


