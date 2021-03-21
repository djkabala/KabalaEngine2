#include "vkCommandPoolCreateInfo.h"

vk::CommandPoolCreateInfo::CommandPoolCreateInfo(const VkCommandPoolCreateFlags flags, uint32_t queueFamilyIndex)
{
    _info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.queueFamilyIndex = queueFamilyIndex;
}
