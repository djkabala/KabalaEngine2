#pragma once
class vkPipelineInputAssemblyStateCreateInfo
{
};
#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineInputAssemblyStateCreateInfo
{
public:
	PipelineInputAssemblyStateCreateInfo(VkPipelineInputAssemblyStateCreateFlags    flags,
                                         VkPrimitiveTopology                        topology,
                                         VkBool32                                   primitiveRestartEnable);

    VkPipelineInputAssemblyStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineInputAssemblyStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineInputAssemblyStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineInputAssemblyStateCreateInfo> PipelineInputAssemblyStateCreateInfoPtr; 

};


