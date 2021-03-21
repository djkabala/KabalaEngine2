#include "vkFence.h"

vk::Fence::Fence(DevicePtr device, FenceCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateFence(_device->getRaw(), createInfo->getRaw(), _allocator, &_fence);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::Fence::~Fence()
{
	if (_fence != nullptr)
	{
		vkDestroyFence(_device->getRaw(), _fence, _allocator);
	}
}
