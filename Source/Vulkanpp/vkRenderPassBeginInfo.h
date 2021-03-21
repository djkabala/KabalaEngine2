#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkFramebuffer.h"
#include "vkRenderPass.h"

namespace vk
{

class RenderPassBeginInfo
{
public:
	RenderPassBeginInfo(RenderPassPtr           renderPass,
                        FramebufferPtr          framebuffer,
                        VkRect2D               renderArea,
                        const std::vector<VkClearValue>&    pClearValues);

    VkRenderPassBeginInfo* getRaw(void)
    {
        return &_info;
    }

    const VkRenderPassBeginInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkRenderPassBeginInfo _info;
};

typedef std::shared_ptr<RenderPassBeginInfo> RenderPassBeginInfoPtr; 

};

