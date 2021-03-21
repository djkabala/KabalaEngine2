#include "vkPipelineDynamicStateCreateInfo.h"
vk::PipelineDynamicStateCreateInfo::PipelineDynamicStateCreateInfo(VkPipelineDynamicStateCreateFlags    flags,
    std::vector<VkDynamicState>& dynamicStates)
{
    _info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = flags;
    _info.dynamicStateCount = dynamicStates.size();
    _info.pDynamicStates = ((dynamicStates.size() == 0) ? nullptr : dynamicStates.data());
}
