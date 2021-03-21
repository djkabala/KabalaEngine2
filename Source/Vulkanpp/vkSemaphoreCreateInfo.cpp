#include "vkSemaphoreCreateInfo.h"
vk::SemaphoreCreateInfo::SemaphoreCreateInfo(const VkSemaphoreCreateFlags flags)
{
    _info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
}
