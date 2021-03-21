#include "vkImageViewCreateInfo.h"
vk::ImageViewCreateInfo::ImageViewCreateInfo(VkImageViewCreateFlags     flags,
	VkImage                    image,
	VkImageViewType            viewType,
	VkFormat                   format,
	VkComponentMapping         components,
	VkImageSubresourceRange    subresourceRange)
{
	_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	_info.pNext = NULL;
	_info.flags = flags;
	_info.image = image;
	_info.viewType = viewType;
	_info.format = format;
	_info.components = components;
	_info.subresourceRange = subresourceRange;
}

vk::ImageViewCreateInfo::ImageViewCreateInfo(VkImageViewCreateFlags     flags,
	ImagePtr                   image,
	VkImageViewType            viewType,
	VkFormat                   format,
	VkComponentMapping         components,
	VkImageSubresourceRange    subresourceRange) :

	ImageViewCreateInfo(flags,
		image->getRaw(),
		viewType,
		format,
		components,
		subresourceRange)
{
}

vk::ImageViewCreateInfo::~ImageViewCreateInfo()
{

}
