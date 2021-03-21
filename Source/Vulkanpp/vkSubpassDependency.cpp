#include "vkSubpassDependency.h"
vk::SubpassDependency::SubpassDependency(uint32_t                srcSubpass,
    uint32_t                dstSubpass,
    VkPipelineStageFlags    srcStageMask,
    VkPipelineStageFlags    dstStageMask,
    VkAccessFlags           srcAccessMask,
    VkAccessFlags           dstAccessMask,
    VkDependencyFlags       dependencyFlags)
{
    _dependency.srcSubpass      = srcSubpass;
    _dependency.dstSubpass      = dstSubpass;
    _dependency.srcStageMask    = srcStageMask;
    _dependency.dstStageMask    = dstStageMask;
    _dependency.srcAccessMask   = srcAccessMask;
    _dependency.dstAccessMask   = dstAccessMask;
    _dependency.dependencyFlags = dependencyFlags;
}
