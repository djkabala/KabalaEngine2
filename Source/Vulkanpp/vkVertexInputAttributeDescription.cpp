#include "vkVertexInputAttributeDescription.h"
vk::VertexInputAttributeDescription::VertexInputAttributeDescription(uint32_t    location,
    uint32_t    binding,
    VkFormat    format,
    uint32_t    offset)
{
    _info.location = location;
    _info.binding = binding;
    _info.format = format;
    _info.offset = offset;
}
