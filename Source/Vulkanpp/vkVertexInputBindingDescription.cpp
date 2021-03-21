#include "vkVertexInputBindingDescription.h"

vk::VertexInputBindingDescription::VertexInputBindingDescription(uint32_t             binding,
    uint32_t             stride,
    VkVertexInputRate    inputRate)
{
    _info.binding = binding;
    _info.stride = stride;
    _info.inputRate = inputRate;
}
