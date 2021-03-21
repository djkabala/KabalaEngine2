#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class SubpassDependency
{
public:
	SubpassDependency(uint32_t                srcSubpass,
                      uint32_t                dstSubpass,
                      VkPipelineStageFlags    srcStageMask,
                      VkPipelineStageFlags    dstStageMask,
                      VkAccessFlags           srcAccessMask,
                      VkAccessFlags           dstAccessMask,
                      VkDependencyFlags       dependencyFlags);

    VkSubpassDependency getRaw(void)
    {
        return _dependency;
    }

    const VkSubpassDependency getRaw(void) const
    {
        return _dependency;
    }
protected:
	VkSubpassDependency _dependency;
};

typedef std::shared_ptr<SubpassDependency> SubpassDependencyPtr; 

};

