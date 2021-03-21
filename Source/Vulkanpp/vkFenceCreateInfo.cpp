#include "vkFenceCreateInfo.h"

vk::FenceCreateInfo::FenceCreateInfo(const VkFenceCreateFlags flags)
{
    _info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    _info.pNext = nullptr;
    _info.flags = flags;
}
