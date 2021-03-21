#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineColorBlendAttachmentState
{
public:
	PipelineColorBlendAttachmentState(VkBool32                 blendEnable,
                                      VkBlendFactor            srcColorBlendFactor,
                                      VkBlendFactor            dstColorBlendFactor,
                                      VkBlendOp                colorBlendOp,
                                      VkBlendFactor            srcAlphaBlendFactor,
                                      VkBlendFactor            dstAlphaBlendFactor,
                                      VkBlendOp                alphaBlendOp,
                                      VkColorComponentFlags    colorWriteMask);

    VkPipelineColorBlendAttachmentState getRaw(void)
    {
        return _info;
    }

    const VkPipelineColorBlendAttachmentState getRaw(void) const
    {
        return _info;
    }
protected:
	VkPipelineColorBlendAttachmentState _info;
};

typedef std::shared_ptr<PipelineColorBlendAttachmentState> PipelineColorBlendAttachmentStatePtr; 

};

