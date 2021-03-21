#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>
#include "vkVertexInputBindingDescription.h"
#include "vkVertexInputAttributeDescription.h"

namespace vk
{

class PipelineVertexInputStateCreateInfo
{
public:
	PipelineVertexInputStateCreateInfo(VkPipelineVertexInputStateCreateFlags                     flags,
                                       const std::vector<VertexInputBindingDescriptionPtr>&      pVertexBindingDescriptions,
                                       const std::vector<VertexInputAttributeDescriptionPtr>&    pVertexAttributeDescriptions);

    VkPipelineVertexInputStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineVertexInputStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineVertexInputStateCreateInfo _info;
    std::vector<VkVertexInputBindingDescription>      _vertexBindingDescriptions;
    std::vector<VkVertexInputAttributeDescription>    _vertexAttributeDescriptions;
};

typedef std::shared_ptr<PipelineVertexInputStateCreateInfo> PipelineVertexInputStateCreateInfoPtr; 

};

