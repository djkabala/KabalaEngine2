#include "vkFramebufferCreateInfo.h"
vk::FramebufferCreateInfo::FramebufferCreateInfo(VkFramebufferCreateFlags    flags,
                                                 RenderPassPtr                renderPass,
                                                 const std::vector<ImageViewPtr>& pAttachments,
                                                 uint32_t                    width,
                                                 uint32_t                    height,
                                                 uint32_t                    layers) : _renderPass(renderPass), _attachments(pAttachments)
{
    _attachmentsRaw.reserve(_attachments.size());
    for (ImageViewPtr attachment : _attachments)
    {
        _attachmentsRaw.push_back(attachment->getRaw());
    }
    _info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    _info.pNext = nullptr;
    _info.flags = flags;
    _info.renderPass = renderPass->getRaw();
    _info.attachmentCount = _attachmentsRaw.size();
    _info.pAttachments = ((_attachmentsRaw.size() == 0) ? nullptr : _attachmentsRaw.data());
    _info.width = width;
    _info.height = height;
    _info.layers = layers;
}
