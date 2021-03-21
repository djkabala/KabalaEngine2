#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkSemaphoreCreateInfo.h"

namespace vk
{

class Semaphore
{
public:
	Semaphore(DevicePtr device, SemaphoreCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~Semaphore();

    VkSemaphore getRaw(void)
    {
        return _semaphone;
    }

    const VkSemaphore getRaw(void) const
    {
        return _semaphone;
    }

protected:
	VkSemaphore _semaphone;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<Semaphore> SemaphorePtr; 

};


