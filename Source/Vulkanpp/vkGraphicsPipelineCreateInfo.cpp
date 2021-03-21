#include "vkGraphicsPipelineCreateInfo.h"
vk::GraphicsPipelineCreateInfo::GraphicsPipelineCreateInfo(VkPipelineCreateFlags                      flags,
                               const std::vector<PipelineShaderStageCreateInfoPtr>&           stages,
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
    int32_t                                    basePipelineIndex)
{

    for (PipelineShaderStageCreateInfoPtr stage : stages)
    {
        _stages.push_back(stage->getRaw());
    }
    _info.sType               = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    _info.pNext               = NULL;
	_info.flags               = flags;
    _info.stageCount          = _stages.size();
    _info.pStages             = (_stages.size() == 0) ? nullptr : _stages.data();
    _info.pVertexInputState   = pVertexInputState->getRaw();
    _info.pInputAssemblyState = pInputAssemblyState->getRaw();
    _info.pTessellationState  = pTessellationState->getRaw();
    _info.pViewportState      = pViewportState->getRaw();
    _info.pRasterizationState = pRasterizationState->getRaw();
    _info.pMultisampleState   = pMultisampleState->getRaw();
    _info.pDepthStencilState  = pDepthStencilState->getRaw();
    _info.pColorBlendState    = pColorBlendState->getRaw();
    _info.pDynamicState       = pDynamicState->getRaw();
    _info.layout              = layout->getRaw();
    _info.renderPass          = renderPass->getRaw();
    _info.subpass             = subpass;
    _info.basePipelineHandle  = basePipelineHandle;
    _info.basePipelineIndex   = basePipelineIndex;
}
