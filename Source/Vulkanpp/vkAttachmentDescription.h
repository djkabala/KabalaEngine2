#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class AttachmentDescription
{
public:
	AttachmentDescription(VkAttachmentDescriptionFlags    flags,
                          VkFormat                        format,
                          VkSampleCountFlagBits           samples,
                          VkAttachmentLoadOp              loadOp,
                          VkAttachmentStoreOp             storeOp,
                          VkAttachmentLoadOp              stencilLoadOp,
                          VkAttachmentStoreOp             stencilStoreOp,
                          VkImageLayout                   initialLayout,
                          VkImageLayout                   finalLayout);

    VkAttachmentDescription getRaw(void)
    {
        return _info;
    }

    const VkAttachmentDescription getRaw(void) const
    {
        return _info;
    }
protected:
	VkAttachmentDescription _info;
};

typedef std::shared_ptr<AttachmentDescription> AttachmentDescriptionPtr; 

};

