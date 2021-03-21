#include "vkPipelineRasterizationStateCreateInfo.h"
vk::PipelineRasterizationStateCreateInfo::PipelineRasterizationStateCreateInfo(VkPipelineRasterizationStateCreateFlags    flags,
                                         VkBool32                                   depthClampEnable,
                                         VkBool32                                   rasterizerDiscardEnable,
                                         VkPolygonMode                              polygonMode,
                                         VkCullModeFlags                            cullMode,
                                         VkFrontFace                                frontFace,
                                         VkBool32                                   depthBiasEnable,
                                         float                                      depthBiasConstantFactor,
                                         float                                      depthBiasClamp,
                                         float                                      depthBiasSlopeFactor,
                                         float                                      lineWidth)
{
	_info.sType                   = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	_info.pNext                   = nullptr;
	_info.flags                   = flags;
    _info.depthClampEnable        = depthClampEnable;
    _info.rasterizerDiscardEnable = rasterizerDiscardEnable;
    _info.polygonMode             = polygonMode;
    _info.cullMode                = cullMode;
    _info.frontFace               = frontFace;
    _info.depthBiasEnable         = depthBiasEnable;
    _info.depthBiasConstantFactor = depthBiasConstantFactor;
    _info.depthBiasClamp          = depthBiasClamp;
    _info.depthBiasSlopeFactor    = depthBiasSlopeFactor;
    _info.lineWidth               = lineWidth;

}
