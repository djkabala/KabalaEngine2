#include "vkCommandBufferBeginInfo.h"
vk::CommandBufferBeginInfo::CommandBufferBeginInfo(VkCommandBufferUsageFlags                flags,
    CommandBufferInheritanceInfoPtr    pInheritanceInfo) : _inheritanceInfo(pInheritanceInfo)
{
    _info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.pInheritanceInfo = (_inheritanceInfo == nullptr) ? nullptr : _inheritanceInfo->getRaw();
}
