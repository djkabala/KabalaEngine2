#pragma once

#include <vulkan/vulkan.h>
#include <memory>

#include "vkCommandBufferInheritanceInfo.h"

namespace vk
{

class CommandBufferBeginInfo
{
public:
	CommandBufferBeginInfo(VkCommandBufferUsageFlags                flags,
                           CommandBufferInheritanceInfoPtr    pInheritanceInfo);

    VkCommandBufferBeginInfo* getRaw(void)
    {
        return &_info;
    }

    const VkCommandBufferBeginInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkCommandBufferBeginInfo _info;
    CommandBufferInheritanceInfoPtr    _inheritanceInfo;
};

typedef std::shared_ptr<CommandBufferBeginInfo> CommandBufferBeginInfoPtr; 

};

