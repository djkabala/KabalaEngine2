#include "vkPipelineTessellationStateCreateInfo.h"
vk::PipelineTessellationStateCreateInfo::PipelineTessellationStateCreateInfo(VkPipelineTessellationStateCreateFlags    flags,
    uint32_t                                  patchControlPoints)
{
    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.patchControlPoints = patchControlPoints;
}
