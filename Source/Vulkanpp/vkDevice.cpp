#include "vkDevice.h"
#include "vkQueue.h"
#include "vkFence.h"

vk::Device::Device(const PhysicalDevice& physicalDevice, const DeviceCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(nullptr) , _allocator(pAllocator)
{
    VkResult res = vkCreateDevice(physicalDevice.getRaw(), createInfo->getRaw(), _allocator, &_device);
    
    if (res != VK_SUCCESS)
    {
        throw res;
    }
}

vk::Device::~Device()
{
    if (_device != nullptr)
    {
        vkDestroyDevice(_device, _allocator);
    }
}

vk::QueuePtr vk::Device::getDeviceQueue(const uint32_t queueFamilyIndex, const uint32_t queueIndex) const
{
    VkQueue queue;
    vkGetDeviceQueue(_device, queueFamilyIndex, queueIndex, &queue);

    return QueuePtr(new Queue(queue));
}

VkResult vk::Device::waitForFences(const std::vector<VkFence>& fences, VkBool32 waitAll, uint64_t timeout)
{
    VkResult res = vkWaitForFences(_device, fences.size(), fences.data(), waitAll, timeout);
    
    if (res != VK_SUCCESS && res != VK_TIMEOUT)
    {
        throw res;
    }
    return res;
}

VkResult vk::Device::waitForFence(FencePtr fence, VkBool32 waitAll, uint64_t timeout)
{
    VkFence fenceRaw(fence->getRaw());
    VkResult res = vkWaitForFences(_device, 1, &fenceRaw, waitAll, timeout);
    
    if (res != VK_SUCCESS && res != VK_TIMEOUT)
    {
        throw res;
    }

    return res;
}
