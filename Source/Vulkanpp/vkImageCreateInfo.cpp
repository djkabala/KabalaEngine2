#include "vkImageCreateInfo.h"
vk::ImageCreateInfo::ImageCreateInfo(VkImageType              imageType,
	VkFormat                 format,
	VkExtent3D               extent,
	uint32_t                 mipLevels,
	uint32_t                 arrayLayers,
	VkSampleCountFlagBits    samples,
	VkImageTiling            tiling,
	VkImageUsageFlags        usage,
	VkSharingMode            sharingMode,
	const std::vector<uint32_t>&    queueFamilyIndices,
	VkImageLayout            initialLayout)
{
    _info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    _info.pNext = NULL;
    _info.flags = 0.0;
    _info.imageType = imageType;
    _info.format = format;
    _info.extent = extent;
    _info.mipLevels = mipLevels;
    _info.arrayLayers = arrayLayers;
    _info.samples = samples;
    _info.tiling = tiling;
    _info.initialLayout = initialLayout;
    _info.usage = usage;
    _info.queueFamilyIndexCount = queueFamilyIndices.size();
    _info.pQueueFamilyIndices = (queueFamilyIndices.size() == 0) ? nullptr : queueFamilyIndices.data();
    _info.sharingMode = sharingMode;
}
