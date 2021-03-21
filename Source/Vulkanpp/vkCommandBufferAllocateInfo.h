#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include "vkCommandPool.h"

namespace vk
{

class CommandBufferAllocateInfo
{
public:
	CommandBufferAllocateInfo(CommandPoolPtr commandPool, const VkCommandBufferLevel level, const uint32_t commandBufferCount);

    VkCommandBufferAllocateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkCommandBufferAllocateInfo* getRaw(void) const
    {
        return &_info;
    }

    inline CommandPoolPtr getCommandPool() { return _commandPool; }

    inline const CommandPoolPtr getCommandPool() const { return _commandPool; }
protected:
	VkCommandBufferAllocateInfo _info;
    CommandPoolPtr _commandPool;
};

typedef std::shared_ptr<CommandBufferAllocateInfo> CommandBufferAllocateInfoPtr; 

};

