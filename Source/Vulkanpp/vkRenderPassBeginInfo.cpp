#include "vkRenderPassBeginInfo.h"
vk::RenderPassBeginInfo::RenderPassBeginInfo(RenderPassPtr           renderPass,
    FramebufferPtr          framebuffer,
    VkRect2D               renderArea,
    const std::vector<VkClearValue>& pClearValues)
{
    _info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    _info.pNext = nullptr;
    _info.renderPass = renderPass->getRaw();
    _info.framebuffer = framebuffer->getRaw();
    _info.renderArea = renderArea;
    _info.clearValueCount = pClearValues.size();
    _info.pClearValues = ((pClearValues.size() == 0) ? nullptr : pClearValues.data());
}
