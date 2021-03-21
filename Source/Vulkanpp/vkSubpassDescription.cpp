#include "vkSubpassDescription.h"
#include <assert.h>
vk::SubpassDescription::SubpassDescription(VkSubpassDescriptionFlags                  flags,
                                           VkPipelineBindPoint                        pipelineBindPoint,
                                           const std::vector<AttachmentReferencePtr>& pInputAttachments,
                                           const std::vector<AttachmentReferencePtr>& pColorAttachments,
                                           const std::vector<AttachmentReferencePtr>& pResolveAttachments,
                                           AttachmentReferencePtr                     pDepthStencilAttachment,
                                           const std::vector<uint32_t>&               pPreserveAttachments) : _preserveAttachments(pPreserveAttachments)
{
    assert(pResolveAttachments.size() == 0 || pResolveAttachments.size() == pColorAttachments.size());

    if (pDepthStencilAttachment != nullptr)
    {
        _depthStencilAttachment = pDepthStencilAttachment->getRaw();
    }

    _inputAttachments.reserve(pInputAttachments.size());
    for (AttachmentReferencePtr reference : pInputAttachments)
    {
        _inputAttachments.push_back(reference->getRaw());
    }

    _colorAttachments.reserve(pColorAttachments.size());
    for (AttachmentReferencePtr reference : pColorAttachments)
    {
        _colorAttachments.push_back(reference->getRaw());
    }

    _resolveAttachments.reserve(pResolveAttachments.size());
    for (AttachmentReferencePtr reference : pResolveAttachments)
    {
        _resolveAttachments.push_back(reference->getRaw());
    }

    _description.flags                   = flags;
    _description.pipelineBindPoint       = pipelineBindPoint;
    _description.inputAttachmentCount    = _inputAttachments.size();
    _description.pInputAttachments       = ((_inputAttachments.size() == 0) ? nullptr : _inputAttachments.data());

    _description.colorAttachmentCount    = _colorAttachments.size();
    _description.pColorAttachments       = ((_colorAttachments.size() == 0) ? nullptr : _colorAttachments.data());

    _description.pResolveAttachments     = ((_resolveAttachments.size() == 0) ? nullptr : _resolveAttachments.data());

    _description.pDepthStencilAttachment = (pDepthStencilAttachment == nullptr) ? nullptr : &_depthStencilAttachment;

    _description.preserveAttachmentCount = _preserveAttachments.size();
    _description.pPreserveAttachments    = ((_preserveAttachments.size() == 0) ? nullptr : _preserveAttachments.data());
}
