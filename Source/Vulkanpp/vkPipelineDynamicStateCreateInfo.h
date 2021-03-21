#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class PipelineDynamicStateCreateInfo
{
public:
	PipelineDynamicStateCreateInfo(VkPipelineDynamicStateCreateFlags    flags,
                                   std::vector<VkDynamicState>&         pDynamicStates);

    VkPipelineDynamicStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineDynamicStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineDynamicStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineDynamicStateCreateInfo> PipelineDynamicStateCreateInfoPtr; 

};

