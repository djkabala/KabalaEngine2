#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkGraphicsPipelineCreateInfo.h"

namespace vk
{

class GraphicsPipeline
{
public:
	GraphicsPipeline(DevicePtr device,
                     VkPipelineCache pipelineCache,
                     GraphicsPipelineCreateInfoPtr createInfo,
                     const VkAllocationCallbacks* pAllocator);

	~GraphicsPipeline();

    VkPipeline getRaw(void)
    {
        return _pipeline;
    }

    const VkPipeline getRaw(void) const
    {
        return _pipeline;
    }

protected:
	VkPipeline _pipeline;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<GraphicsPipeline> GraphicsPipelinePtr; 

};


