#include "vkRenderPassCreateInfo.h"
vk::RenderPassCreateInfo::RenderPassCreateInfo(VkRenderPassCreateFlags                      flags,
    const std::vector<AttachmentDescriptionPtr>& pAttachments,
    const std::vector<SubpassDescriptionPtr>& pSubpasses,
    const std::vector<SubpassDependencyPtr>& pDependencies)
{
    _attachments.reserve(pAttachments.size());
    for(AttachmentDescriptionPtr attachment : pAttachments)
    {
        _attachments.push_back(attachment->getRaw());
    }

    _subpasses.reserve(pSubpasses.size());
    for(SubpassDescriptionPtr subpass : pSubpasses)
    {
        _subpasses.push_back(subpass->getRaw());
    }

    _dependencies.reserve(pDependencies.size());
    for(SubpassDependencyPtr dependency : pDependencies)
    {
        _dependencies.push_back(dependency->getRaw());
    }

    _info.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    _info.pNext           = nullptr;
    _info.flags           = flags;
    _info.attachmentCount = _attachments.size();
    _info.pAttachments    = ((_attachments.size() == 0) ? nullptr : _attachments.data());
    _info.subpassCount    = _subpasses.size();
    _info.pSubpasses      = ((_subpasses.size() == 0) ? nullptr : _subpasses.data());
    _info.dependencyCount = _dependencies.size();
    _info.pDependencies   = ((_dependencies.size() == 0) ? nullptr : _dependencies.data());
}
