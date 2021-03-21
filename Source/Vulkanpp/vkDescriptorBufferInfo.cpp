#include "vkDescriptorBufferInfo.h"
vk::DescriptorBufferInfo::DescriptorBufferInfo(BufferPtr       buffer,
    VkDeviceSize    offset,
    VkDeviceSize    range)
{
    _info.buffer = buffer->getRaw();
    _info.offset = offset;
    _info.range = range;
}
