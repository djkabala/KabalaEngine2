#include "vkFramebuffer.h"

vk::Framebuffer::Framebuffer(DevicePtr device, FramebufferCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateFramebuffer(_device->getRaw(), createInfo->getRaw(), _allocator, &_semaphone);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::Framebuffer::~Framebuffer()
{
	if (_semaphone != nullptr)
	{
		vkDestroyFramebuffer(_device->getRaw(), _semaphone, _allocator);
	}
}
