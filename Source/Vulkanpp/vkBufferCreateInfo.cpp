#include "vkBufferCreateInfo.h"

vk::BufferCreateInfo::BufferCreateInfo(VkBufferCreateFlags    flags,
                                       VkDeviceSize           size,
                                       VkBufferUsageFlags     usage,
                                       VkSharingMode          sharingMode,
                                       const std::vector<uint32_t>& queueFamilyIndices) :
    _queueFamilyIndices(queueFamilyIndices)
{
    _info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.usage = usage;
    _info.size = size;
    _info.queueFamilyIndexCount = _queueFamilyIndices.size();
    _info.pQueueFamilyIndices = (_queueFamilyIndices.size() == 0) ? 0 : _queueFamilyIndices.data();
    _info.sharingMode = sharingMode;
}
