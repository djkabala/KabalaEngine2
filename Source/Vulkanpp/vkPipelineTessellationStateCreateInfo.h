#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineTessellationStateCreateInfo
{
public:
	PipelineTessellationStateCreateInfo(VkPipelineTessellationStateCreateFlags    flags,
                                        uint32_t                                  patchControlPoints);

    VkPipelineTessellationStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineTessellationStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineTessellationStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineTessellationStateCreateInfo> PipelineTessellationStateCreateInfoPtr; 

};

