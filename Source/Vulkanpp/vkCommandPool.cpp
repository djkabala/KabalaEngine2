#include "vkCommandPool.h"

vk::CommandPool::CommandPool(DevicePtr device, CommandPoolCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateCommandPool(_device->getRaw(), createInfo->getRaw(), _allocator, &_pool);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::CommandPool::~CommandPool()
{
	if (_pool != nullptr)
	{
		vkDestroyCommandPool(_device->getRaw(), _pool, _allocator);
	}
}
