#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkRenderPass.h"
#include "vkFramebuffer.h"

namespace vk
{

class CommandBufferInheritanceInfo
{
public:
	CommandBufferInheritanceInfo(RenderPassPtr                    renderPass,
                                 uint32_t                         subpass,
                                 FramebufferPtr                   framebuffer,
                                 VkBool32                         occlusionQueryEnable,
                                 VkQueryControlFlags              queryFlags,
                                 VkQueryPipelineStatisticFlags    pipelineStatistics);

    VkCommandBufferInheritanceInfo* getRaw(void)
    {
        return &_info;
    }

    const VkCommandBufferInheritanceInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkCommandBufferInheritanceInfo _info;
};

typedef std::shared_ptr<CommandBufferInheritanceInfo> CommandBufferInheritanceInfoPtr; 

};

