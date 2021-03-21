#include "vkCommandBufferAllocateInfo.h"

vk::CommandBufferAllocateInfo::CommandBufferAllocateInfo(CommandPoolPtr commandPool, const VkCommandBufferLevel level, const uint32_t commandBufferCount) : _commandPool(commandPool)
{
    _info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    _info.pNext = NULL;
    _info.commandPool = commandPool->getRaw();
    _info.level = level;
    _info.commandBufferCount = commandBufferCount;
}
