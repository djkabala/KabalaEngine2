#include "vkAttachmentReference.h"

vk::AttachmentReference::AttachmentReference(uint32_t         attachment,
    VkImageLayout    layout)
{
    _reference.attachment = attachment;
    _reference.layout     = layout;
}
