#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkPipelineColorBlendAttachmentState.h"

namespace vk
{

class PipelineColorBlendStateCreateInfo
{
public:
	PipelineColorBlendStateCreateInfo(VkPipelineColorBlendStateCreateFlags          flags,
                                      VkBool32                                      logicOpEnable,
                                      VkLogicOp                                     logicOp,
                                      const std::vector<PipelineColorBlendAttachmentStatePtr>&    attachments,
                                      float                                         blendConstants[4]);

    VkPipelineColorBlendStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineColorBlendStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineColorBlendStateCreateInfo _info;
    std::vector<VkPipelineColorBlendAttachmentState> _attachments;
};

typedef std::shared_ptr<PipelineColorBlendStateCreateInfo> PipelineColorBlendStateCreateInfoPtr; 

};

