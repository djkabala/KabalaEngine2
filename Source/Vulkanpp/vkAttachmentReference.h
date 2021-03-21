#pragma once

#include <vulkan/vulkan.h>
#include <memory>

namespace vk
{

class AttachmentReference
{
public:
	AttachmentReference(uint32_t         attachment,
                        VkImageLayout    layout);

    VkAttachmentReference getRaw(void)
    {
        return _reference;
    }

    const VkAttachmentReference getRaw(void) const
    {
        return _reference;
    }
protected:
	VkAttachmentReference _reference;
};

typedef std::shared_ptr<AttachmentReference> AttachmentReferencePtr; 

};


