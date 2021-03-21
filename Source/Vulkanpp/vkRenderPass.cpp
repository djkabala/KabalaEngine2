#include "vkRenderPass.h"

vk::RenderPass::RenderPass(DevicePtr device, RenderPassCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateRenderPass(_device->getRaw(), createInfo->getRaw(), _allocator, &_renderPass);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::RenderPass::~RenderPass()
{
	if (_renderPass != nullptr)
	{
		vkDestroyRenderPass(_device->getRaw(), _renderPass, _allocator);
	}
}
