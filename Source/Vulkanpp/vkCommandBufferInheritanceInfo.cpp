#include "vkCommandBufferInheritanceInfo.h"
vk::CommandBufferInheritanceInfo::CommandBufferInheritanceInfo(RenderPassPtr                    renderPass,
    uint32_t                         subpass,
    FramebufferPtr                   framebuffer,
    VkBool32                         occlusionQueryEnable,
    VkQueryControlFlags              queryFlags,
    VkQueryPipelineStatisticFlags    pipelineStatistics)
{

    _info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    _info.pNext = nullptr;
    _info.renderPass = (renderPass == nullptr) ? nullptr : renderPass->getRaw();
    _info.subpass = subpass;
    _info.framebuffer = (framebuffer == nullptr) ? nullptr : framebuffer->getRaw();
    _info.occlusionQueryEnable = occlusionQueryEnable;
    _info.queryFlags = queryFlags;
    _info.pipelineStatistics = pipelineStatistics;
}
