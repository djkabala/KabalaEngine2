#include "vkPipelineDepthStencilStateCreateInfo.h"
vk::PipelineDepthStencilStateCreateInfo::PipelineDepthStencilStateCreateInfo(VkPipelineDepthStencilStateCreateFlags    flags,
    VkBool32                                  depthTestEnable,
    VkBool32                                  depthWriteEnable,
    VkCompareOp                               depthCompareOp,
    VkBool32                                  depthBoundsTestEnable,
    VkBool32                                  stencilTestEnable,
    VkStencilOpState                          front,
    VkStencilOpState                          back,
    float                                     minDepthBounds,
    float                                     maxDepthBounds)
{
    _info.sType                 = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    _info.pNext                 = nullptr;
	_info.flags                 = flags;
    _info.depthTestEnable       = depthTestEnable;
    _info.depthWriteEnable      = depthWriteEnable;
    _info.depthCompareOp        = depthCompareOp;
    _info.depthBoundsTestEnable = depthBoundsTestEnable;
    _info.stencilTestEnable     = stencilTestEnable;
    _info.front                 = front;
    _info.back                  = back;
    _info.minDepthBounds        = minDepthBounds;
    _info.maxDepthBounds        = maxDepthBounds;

}
