#include "vkAttachmentDescription.h"
#
vk::AttachmentDescription::AttachmentDescription(VkAttachmentDescriptionFlags    flags,
    VkFormat                        format,
    VkSampleCountFlagBits           samples,
    VkAttachmentLoadOp              loadOp,
    VkAttachmentStoreOp             storeOp,
    VkAttachmentLoadOp              stencilLoadOp,
    VkAttachmentStoreOp             stencilStoreOp,
    VkImageLayout                   initialLayout,
    VkImageLayout                   finalLayout)
{
    _info.flags          = flags;
    _info.format         = format;
    _info.samples        = samples;
    _info.loadOp         = loadOp;
    _info.storeOp        = storeOp;
    _info.stencilLoadOp  = stencilLoadOp;
    _info.stencilStoreOp = stencilStoreOp;
    _info.initialLayout  = initialLayout;
    _info.finalLayout    = finalLayout;
}
