#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkRenderPass.h"
#include "vkImageView.h"

namespace vk
{

class FramebufferCreateInfo
{
public:
	FramebufferCreateInfo(VkFramebufferCreateFlags    flags,
                          RenderPassPtr                renderPass,
                          const std::vector<ImageViewPtr>&                pAttachments,
                          uint32_t                    width,
                          uint32_t                    height,
                          uint32_t                    layers);

    VkFramebufferCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkFramebufferCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkFramebufferCreateInfo _info;

    RenderPassPtr _renderPass;
    const std::vector<ImageViewPtr> _attachments;
    std::vector<VkImageView> _attachmentsRaw;
};

typedef std::shared_ptr<FramebufferCreateInfo> FramebufferCreateInfoPtr; 

};

