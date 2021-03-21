#include "vkGraphicsPipeline.h"

vk::GraphicsPipeline::GraphicsPipeline(DevicePtr device,
                                       VkPipelineCache pipelineCache,
                                       GraphicsPipelineCreateInfoPtr createInfo,
                                       const VkAllocationCallbacks* pAllocator) : _device(device), _allocator(pAllocator)
{
	VkResult res = vkCreateGraphicsPipelines(_device->getRaw(), pipelineCache, 1, createInfo->getRaw(), _allocator, &_pipeline);
	
	if (res != VK_SUCCESS)
	{
		throw res;
	}
}

vk::GraphicsPipeline::~GraphicsPipeline()
{
	if (_pipeline != nullptr)
	{
		vkDestroyPipeline(_device->getRaw(), _pipeline, _allocator);
	}
}
