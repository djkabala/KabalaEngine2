#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "vkPhysicalDevice.h"
#include "vkDeviceCreateInfo.h"

namespace vk
{
typedef std::shared_ptr<class Fence> FencePtr; 
typedef std::shared_ptr<class Queue> QueuePtr; 

class Device
{
public:
	Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~Device();

    QueuePtr getDeviceQueue(const uint32_t queueFamilyIndex, const uint32_t queueIndex) const;

    VkResult waitForFences(const std::vector<VkFence>& fences, VkBool32 waitAll, uint64_t timeout);

    VkResult waitForFence(FencePtr fence, VkBool32 waitAll, uint64_t timeout);

    VkDevice getRaw(void)
    {
        return _device;
    }

    const VkDevice getRaw(void) const
    {
        return _device;
    }
protected:
	VkDevice _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<Device> DevicePtr; 

};

