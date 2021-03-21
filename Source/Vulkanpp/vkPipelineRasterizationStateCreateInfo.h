#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class PipelineRasterizationStateCreateInfo
{
public:
	PipelineRasterizationStateCreateInfo(VkPipelineRasterizationStateCreateFlags    flags,
                                         VkBool32                                   depthClampEnable,
                                         VkBool32                                   rasterizerDiscardEnable,
                                         VkPolygonMode                              polygonMode,
                                         VkCullModeFlags                            cullMode,
                                         VkFrontFace                                frontFace,
                                         VkBool32                                   depthBiasEnable,
                                         float                                      depthBiasConstantFactor,
                                         float                                      depthBiasClamp,
                                         float                                      depthBiasSlopeFactor,
                                         float                                      lineWidth);

    VkPipelineRasterizationStateCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkPipelineRasterizationStateCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkPipelineRasterizationStateCreateInfo _info;
};

typedef std::shared_ptr<PipelineRasterizationStateCreateInfo> PipelineRasterizationStateCreateInfoPtr; 

};

