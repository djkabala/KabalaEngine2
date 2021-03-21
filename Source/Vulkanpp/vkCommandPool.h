#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkCommandPoolCreateInfo.h"

namespace vk
{

class CommandPool
{
public:
	CommandPool(DevicePtr device, CommandPoolCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~CommandPool();

    VkCommandPool getRaw(void)
    {
        return _pool;
    }

    const VkCommandPool getRaw(void) const
    {
        return _pool;
    }

protected:
	VkCommandPool _pool;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<CommandPool> CommandPoolPtr; 

};

