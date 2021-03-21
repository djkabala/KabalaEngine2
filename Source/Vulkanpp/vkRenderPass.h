#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkRenderPassCreateInfo.h"

namespace vk
{

class RenderPass
{
public:
	RenderPass(DevicePtr device, RenderPassCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~RenderPass();

    VkRenderPass getRaw(void)
    {
        return _renderPass;
    }

    const VkRenderPass getRaw(void) const
    {
        return _renderPass;
    }

protected:
	VkRenderPass _renderPass;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<RenderPass> RenderPassPtr; 

};

