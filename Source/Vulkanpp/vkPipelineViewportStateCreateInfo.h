#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class PipelineViewportStateCreateInfo
{
public:
	PipelineViewportStateCreateInfo(VkPipelineViewportStateCreateFlags    flags,
                                    uint32_t                              numViewports,
                                    const std::vector<VkViewport>&        viewports,
                                    uint32_t                              numSissors,
                                    const std::vector<VkRect2D>&          scissors);

    VkPipelineViewportStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineViewportStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineViewportStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineViewportStateCreateInfo> PipelineViewportStateCreateInfoPtr; 

};

