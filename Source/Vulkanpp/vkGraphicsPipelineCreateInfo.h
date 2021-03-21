#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include "vkPipelineShaderStageCreateInfo.h"
#include "vkPipelineVertexInputStateCreateInfo.h"
#include "vkPipelineInputAssemblyStateCreateInfo.h"
#include "vkPipelineTessellationStateCreateInfo.h"
#include "vkPipelineViewportStateCreateInfo.h"
#include "vkPipelineRasterizationStateCreateInfo.h"
#include "vkPipelineMultisampleStateCreateInfo.h"
#include "vkPipelineDepthStencilStateCreateInfo.h"
#include "vkPipelineColorBlendStateCreateInfo.h"
#include "vkPipelineDynamicStateCreateInfo.h"

#include "vkPipelineLayout.h"
#include "vkRenderPass.h"

namespace vk
{

class GraphicsPipelineCreateInfo
{
public:
	GraphicsPipelineCreateInfo(VkPipelineCreateFlags                      flags,
                               const std::vector<PipelineShaderStageCreateInfoPtr>&           pStages,
                               PipelineVertexInputStateCreateInfoPtr      pVertexInputState,
                               PipelineInputAssemblyStateCreateInfoPtr    pInputAssemblyState,
                               PipelineTessellationStateCreateInfoPtr     pTessellationState,
                               PipelineViewportStateCreateInfoPtr         pViewportState,
                               PipelineRasterizationStateCreateInfoPtr    pRasterizationState,
                               PipelineMultisampleStateCreateInfoPtr      pMultisampleState,
                               PipelineDepthStencilStateCreateInfoPtr     pDepthStencilState,
                               PipelineColorBlendStateCreateInfoPtr       pColorBlendState,
                               PipelineDynamicStateCreateInfoPtr          pDynamicState,
                               PipelineLayoutPtr                          layout,
                               RenderPassPtr                              renderPass,
                               uint32_t                                   subpass,
                               VkPipeline                                 basePipelineHandle,
                               int32_t                                    basePipelineIndex);

    VkGraphicsPipelineCreateInfo* getRaw(void)
    {
        return &_info;
    }

    const VkGraphicsPipelineCreateInfo* getRaw(void) const
    {
        return &_info;
    }
protected:
	VkGraphicsPipelineCreateInfo _info;
    std::vector<VkPipelineShaderStageCreateInfo>           _stages;
};

typedef std::shared_ptr<GraphicsPipelineCreateInfo> GraphicsPipelineCreateInfoPtr; 

};

