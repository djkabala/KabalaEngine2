#include "vkSemaphore.h"

vk::Semaphore::Semaphore(DevicePtr device, SemaphoreCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateSemaphore(_device->getRaw(), createInfo->getRaw(), _allocator, &_semaphone);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::Semaphore::~Semaphore()
{
	if (_semaphone != nullptr)
	{
		vkDestroySemaphore(_device->getRaw(), _semaphone, _allocator);
	}
}
