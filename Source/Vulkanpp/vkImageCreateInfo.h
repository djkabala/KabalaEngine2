#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include <vector>

namespace vk
{

class ImageCreateInfo
{
public:
	ImageCreateInfo(VkImageType              imageType,
					VkFormat                 format,
					VkExtent3D               extent,
					uint32_t                 mipLevels,
					uint32_t                 arrayLayers,
					VkSampleCountFlagBits    samples,
					VkImageTiling            tiling,
					VkImageUsageFlags        usage,
					VkSharingMode            sharingMode,
					const std::vector<uint32_t>&    queueFamilyIndices,
					VkImageLayout            initialLayout);

	inline VkImageCreateInfo* getRaw(void) {return &_info;}

	inline const VkImageCreateInfo* getRaw(void) const {return &_info;}

	inline const VkSampleCountFlagBits getSamples(void) const {return _info.samples;}
	inline const VkFormat              getFormat(void) const {return _info.format;}
protected:
	VkImageCreateInfo _info;
};

typedef std::shared_ptr<ImageCreateInfo> ImageCreateInfoPtr; 
};

