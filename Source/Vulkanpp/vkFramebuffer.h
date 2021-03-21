#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkFramebufferCreateInfo.h"

namespace vk
{

class Framebuffer
{
public:
	Framebuffer(DevicePtr device, FramebufferCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~Framebuffer();

    VkFramebuffer getRaw(void)
    {
        return _semaphone;
    }

    const VkFramebuffer getRaw(void) const
    {
        return _semaphone;
    }

protected:
	VkFramebuffer _semaphone;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<Framebuffer> FramebufferPtr; 

};


