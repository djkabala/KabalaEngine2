#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineDepthStencilStateCreateInfo
{
public:
	PipelineDepthStencilStateCreateInfo(VkPipelineDepthStencilStateCreateFlags    flags,
                                        VkBool32                                  depthTestEnable,
                                        VkBool32                                  depthWriteEnable,
                                        VkCompareOp                               depthCompareOp,
                                        VkBool32                                  depthBoundsTestEnable,
                                        VkBool32                                  stencilTestEnable,
                                        VkStencilOpState                          front,
                                        VkStencilOpState                          back,
                                        float                                     minDepthBounds,
                                        float                                     maxDepthBounds);

    VkPipelineDepthStencilStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineDepthStencilStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineDepthStencilStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineDepthStencilStateCreateInfo> PipelineDepthStencilStateCreateInfoPtr; 

};

