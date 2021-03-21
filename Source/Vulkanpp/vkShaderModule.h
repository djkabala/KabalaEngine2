#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkDevice.h"
#include "vkShaderModuleCreateInfo.h"

namespace vk
{

class ShaderModule
{
public:
	ShaderModule(DevicePtr device, ShaderModuleCreateInfoPtr createInfo, const VkAllocationCallbacks* pAllocator);

	~ShaderModule();

    VkShaderModule getRaw(void)
    {
        return _module;
    }

    const VkShaderModule getRaw(void) const
    {
        return _module;
    }

protected:
	VkShaderModule _module;
	DevicePtr _device;
	const VkAllocationCallbacks* _allocator;
};

typedef std::shared_ptr<ShaderModule> ShaderModulePtr; 

};


