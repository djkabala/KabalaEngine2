#include "vkPipelineColorBlendAttachmentState.h"
vk::PipelineColorBlendAttachmentState::PipelineColorBlendAttachmentState(VkBool32                 blendEnable,
    VkBlendFactor            srcColorBlendFactor,
    VkBlendFactor            dstColorBlendFactor,
    VkBlendOp                colorBlendOp,
    VkBlendFactor            srcAlphaBlendFactor,
    VkBlendFactor            dstAlphaBlendFactor,
    VkBlendOp                alphaBlendOp,
    VkColorComponentFlags    colorWriteMask)
{
	_info.blendEnable         = blendEnable;
    _info.srcColorBlendFactor = srcColorBlendFactor;
    _info.dstColorBlendFactor = dstColorBlendFactor;
    _info.colorBlendOp        = colorBlendOp;
    _info.srcAlphaBlendFactor = srcAlphaBlendFactor;
    _info.dstAlphaBlendFactor = dstAlphaBlendFactor;
    _info.alphaBlendOp        = alphaBlendOp;
    _info.colorWriteMask      = colorWriteMask;
}
