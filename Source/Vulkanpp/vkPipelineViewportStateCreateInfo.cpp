#include "vkPipelineViewportStateCreateInfo.h"
vk::PipelineViewportStateCreateInfo::PipelineViewportStateCreateInfo(VkPipelineViewportStateCreateFlags    flags,
                                    uint32_t                              numViewports,
                                    const std::vector<VkViewport>& viewports,
                                    uint32_t                              numSissors,
                                    const std::vector<VkRect2D>& scissors)
{
    _info.sType         = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    _info.pNext         = nullptr;
    _info.flags         = flags;
    _info.viewportCount = numViewports;
    _info.pViewports    = (viewports.size() == 0) ? nullptr : viewports.data();
    _info.scissorCount  = numSissors;
    _info.pScissors     = (scissors.size() == 0) ? nullptr : scissors.data();
}
