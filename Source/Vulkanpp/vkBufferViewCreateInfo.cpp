#include "vkBufferViewCreateInfo.h"
vk::BufferViewCreateInfo::BufferViewCreateInfo(VkBufferViewCreateFlags    flags,
                                               BufferPtr                  buffer,
                                               VkFormat                   format,
                                               VkDeviceSize               offset,
                                               VkDeviceSize               range)
{
    _info.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
    _info.pNext = nullptr;
    _info.flags = flags;
    _info.buffer = buffer->getRaw();
    _info.format = format;
    _info.offset = offset;
    _info.range = range;
}
