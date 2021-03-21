#pragma once

#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

#include "vkAttachmentReference.h"

namespace vk
{

class SubpassDescription
{
public:
	SubpassDescription(VkSubpassDescriptionFlags                  flags,
                       VkPipelineBindPoint                        pipelineBindPoint,
                       const std::vector<AttachmentReferencePtr>& pInputAttachments,
                       const std::vector<AttachmentReferencePtr>& pColorAttachments,
                       const std::vector<AttachmentReferencePtr>& pResolveAttachments,
                       AttachmentReferencePtr                     pDepthStencilAttachment,
                       const std::vector<uint32_t>&               pPreserveAttachments);

    VkSubpassDescription getRaw(void)
    {
        return _description;
    }

    const VkSubpassDescription getRaw(void) const
    {
        return _description;
    }
protected:
	VkSubpassDescription _description;

    std::vector<VkAttachmentReference> _inputAttachments;
    std::vector<VkAttachmentReference> _colorAttachments;
    std::vector<VkAttachmentReference> _resolveAttachments;
    VkAttachmentReference              _depthStencilAttachment;
    std::vector<uint32_t>              _preserveAttachments;
};

typedef std::shared_ptr<SubpassDescription> SubpassDescriptionPtr; 

};


