#include "vkPipelineVertexInputStateCreateInfo.h"
vk::PipelineVertexInputStateCreateInfo::PipelineVertexInputStateCreateInfo(VkPipelineVertexInputStateCreateFlags                     flags,
    const std::vector<VertexInputBindingDescriptionPtr>& vertexBindingDescriptions,
    const std::vector<VertexInputAttributeDescriptionPtr>& vertexAttributeDescriptions)
{
    for (VertexInputBindingDescriptionPtr desc : vertexBindingDescriptions)
    {
        _vertexBindingDescriptions.push_back(desc->getRaw());
    }
    for (VertexInputAttributeDescriptionPtr desc : vertexAttributeDescriptions)
    {
        _vertexAttributeDescriptions.push_back(desc->getRaw());
    }

    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;

    _info.vertexBindingDescriptionCount = _vertexBindingDescriptions.size();
    _info.pVertexBindingDescriptions = ((_vertexBindingDescriptions.size() == 0) ? nullptr : _vertexBindingDescriptions.data());

    _info.vertexAttributeDescriptionCount = _vertexAttributeDescriptions.size();
    _info.pVertexAttributeDescriptions = ((_vertexAttributeDescriptions.size() == 0) ? nullptr : _vertexAttributeDescriptions.data());
}
