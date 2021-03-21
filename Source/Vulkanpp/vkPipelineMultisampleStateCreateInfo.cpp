#include "vkPipelineMultisampleStateCreateInfo.h"
vk::PipelineMultisampleStateCreateInfo::PipelineMultisampleStateCreateInfo(VkPipelineMultisampleStateCreateFlags    flags,
    VkSampleCountFlagBits                    rasterizationSamples,
    VkBool32                                 sampleShadingEnable,
    float                                    minSampleShading,
    const VkSampleMask* pSampleMask,
    VkBool32                                 alphaToCoverageEnable,
    VkBool32                                 alphaToOneEnable)
{
	_info.sType                 = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	_info.pNext                 = nullptr;
	_info.flags                 = flags;
    _info.rasterizationSamples  = rasterizationSamples;
    _info.sampleShadingEnable   = sampleShadingEnable;
    _info.minSampleShading      = minSampleShading;
    _info.pSampleMask           = pSampleMask;
    _info.alphaToCoverageEnable = alphaToCoverageEnable;
    _info.alphaToOneEnable      = alphaToOneEnable;
}
